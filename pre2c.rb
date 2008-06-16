infile = File.open(ARGV[0],'r')
outfile = File.open(ARGV[0].gsub(/pre$/,'c'),'w')

names = {}
outfile.puts '#include "symbol.h"'
infile.each_line do |l|
	o = l
	if l =~ /^dispatch \"(.+)\"$/
		s = ""
		$1.hash.to_s.each_byte {|b| s << (b+0x16).chr}
		names[$1] = s
		o = "void #{s}()"
	end
	o = o.gsub(/popl()/,"(long)stack_pop()")
	o = o.gsub(/\Wpush\(/,"stack_push((stack_entry)")
	outfile.puts o
end
outfile.puts "void init_register() {"
names.each do |k,v|
	outfile.puts "symbol_cbind(\"#{k}\", *#{v});"
end
outfile.puts "}"
outfile.close
infile.close
