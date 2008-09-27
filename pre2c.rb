infile = File.open(ARGV[0],'r')
outfile = File.open(ARGV[0].gsub(/pre$/,'c'),'w')

names = {}
outfile.puts '#include "symbol.h"'
outfile.puts '#define NT "\n\t"'

infile.each_line do |o|
	
	if o =~ /^dispatch \"(.+)\"$/
		s = ""
		$1.hash.to_s.each_byte {|b| s << (b+0x16).chr}
		names[$1] = s
		o = "void #{s}()"
	end
	
	if o =~ /binop\((.+)\);$/
		op = $1
		o = <<-EOF
			long a,b,r;
			a = popl();
			b = popl();
		EOF
		o << "\tr = " << op << ";\n"
		o << "\tpush(r);\n"
	end
	
	if o =~ /aa\((.+)\);$/
		op = $1
		o = <<-EOF
			asm (
				"xor	%%rax, %%rax" NT
				"call	_stack_pop" NT
				"push	%%rax" NT
				"xor	%%rax, %%rax" NT
				"call	_stack_pop" NT
				"pop	%%rbx" NT
				--OPCODE-- NT
				"mov	%%rbx, %%rdi" NT
				"call	_stack_push" NT
				: /* no output */
				: /* no input */
				: "%rax", "%rbx", "%rdi"
			);
		EOF
		o = o.gsub('--OPCODE--', op)
	end
	
	o = o.gsub(/popl\(\)/,"(long)stack_pop()")
	o = o.gsub(/\Wpush\(/,"\tstack_push((stack_entry)")
	outfile.puts o
end

outfile.puts "void init_register() {"
names.each do |k,v|
	outfile.puts "\tsymbol_cbind(\"#{k}\", *#{v});"
end
outfile.puts "}"
outfile.close
infile.close
