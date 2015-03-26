CC=gcc
CFLAGS=-Wall -Werror -pedantic --std=gnu99

all: cputime

clean:
	-rm *.o cputime

install: cputime
	cp cputime /usr/local/bin/cputime

uninstall:
	-rm /usr/local/bin/cputime

cputime: cputime.o
