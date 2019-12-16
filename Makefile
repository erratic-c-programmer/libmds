CC=gcc
OCC=$(CC) -c
CFLAGS=-fPIC -g -o $@

all : libmds.so

libmds.so : dynstr/objects/strop.o dynstr/objects/stralg.o
	$(CC) $(CFLAGS) -shared $^

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $(CFLAGS) $^

dynstr/objects/stralg.o : dynstr/stralg.c
	$(OCC) $(CFLAGS) $^

test : tests/hello tests/jumble
	@echo 'Run this:  export LD_LIBRARY_PATH=$$(pwd)'

tests/hello : tests/hello.c libmds.so 
	$(CC) $(CFLAGS) -L. -lmds $<

tests/jumble : tests/jumble.c libmds.so
	$(CC) $(CFLAGS) -L. -lmds $<

clean : FORCE
	rm -f */objects/*
	rm -f tests/hello
	rm -f tests/jumble

FORCE :
