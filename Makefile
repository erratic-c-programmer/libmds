CC=gcc
OCC=$(CC) -c
CFLAGS=-fPIC -g -o $@

all : libmds.so

libmds.so : dynstr/objects/strop.o
	$(CC) $(CFLAGS) -shared $^

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $(CFLAGS) $^

test : test/hello

test/hello : test/hello.c libmds.so 
	export LD_LIBRARY_PATH=.
	$(CC) $(CFLAGS) -L. -lmds $<

clean : FORCE
	rm -f */objects/*
	rm -f test/hello

FORCE :
