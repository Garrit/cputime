CC=gcc
CFLAGS=-Wall -Werror -pedantic --std=gnu99

all: cputime

clean:
	-rm *.o cputime

cputime: cputime.o
