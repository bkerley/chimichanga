CC = gcc
CFLAGS = -Wall -g -arch x86_64

LD = gcc
LDFLAGS = -Wall -lreadline -arch x86_64

CT = gcc
CTFLAGS = -S -arch x86_64

RM = rm

PRE2C = ruby pre2c.rb

OBJS = token.o stack.o main.o class.o eval.o symbol.o init.o
PROG = chimi

MARKDOWN = Markdown.pl

all: $(PROG)

doc: README.html

ctest: clean test

clean:
	$(RM) -f $(PROG) $(OBJS) init.c

test: all
	cat test.in | ./$(PROG) 2> /dev/null | diff test.out -

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o chimi

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.s: %.c
	$(CT) $(CTFLAGS) -c $<

init.c: init.pre
	$(PRE2C) $<

README.html: README
	$(MARKDOWN) $< > README.html
