CC=gcc
OCC=$(CC) -c
CFLAGS=-Wall -Wpointer-arith -fPIC -g -o $@

all : libmds.so

libmds.so : dynstr/objects/strop.o dynstr/objects/stralg.o llist/objects/llist.o
	$(CC) $(CFLAGS) -shared $^

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $(CFLAGS) $^

dynstr/objects/stralg.o : dynstr/stralg.c
	$(OCC) $(CFLAGS) $^

llist/objects/llist.o : llist/llist.c
	$(OCC) $(CFLAGS) $^

###############################################################################

test : tests/hello tests/jumble tests/llist all
	@echo 'Run this:  export LD_LIBRARY_PATH=$$(pwd)'

tests/hello : tests/hello.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/jumble : tests/jumble.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/llist : tests/llist.c
	$(CC) $(CFLAGS) -L. -lmds $<

clean : FORCE
	rm -f */objects/*
	rm -f tests/hello
	rm -f tests/jumble

FORCE :
