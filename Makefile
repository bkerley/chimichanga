CC = gcc
CFLAGS = -Wall -g

LD = gcc
LDFLAGS = -Wall

RM = rm

OBJS = token.o main.o

all: chimi

chimi: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o chimi

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) chimi $(OBJS)
