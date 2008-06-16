CC = gcc
CFLAGS = -Wall -g

LD = gcc
LDFLAGS = -Wall -lreadline

RM = rm

PRE2C = ruby pre2c.rb

OBJS = token.o stack.o main.o class.o eval.o symbol.o init.o
PROG = chimi
all: chimi

ctest: clean test

clean:
	$(RM) -f $(PROG) $(OBJS) init.c

test: all
	cat test.in | ./$(PROG) 2> /dev/null | diff test.out -

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o chimi

%.o: %.c
	$(CC) $(CFLAGS) -c $<

init.c: init.pre
	$(PRE2C) $<
