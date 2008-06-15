CC = gcc
CFLAGS = -Wall -g

LD = gcc
LDFLAGS = -Wall -lreadline

RM = rm

OBJS = token.o stack.o main.o class.o eval.o symbol.o
PROG = chimi
all: chimi

ctest: clean test

clean:
	$(RM) -f $(PROG) $(OBJS)

test: all
	./$(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o chimi

%.o: %.c
	$(CC) $(CFLAGS) -c $<
