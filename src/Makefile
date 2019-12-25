AR=ar
CC=gcc
OCC=$(CC) -c
CFLAGS=-Wall -Wpointer-arith -fPIC -g -o $@

all : static dynamic test

static : libmds.a

dynamic : libmds.so

libmds.a : dynstr/objects/strop.o dynstr/objects/stralg.o llist/objects/llist.o vector/objects/vector.o
	$(AR) rcs $@ $^

libmds.so : dynstr/objects/strop.o dynstr/objects/stralg.o llist/objects/llist.o vector/objects/vector.o
	$(CC) $(CFLAGS) -shared $^

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $(CFLAGS) $^

dynstr/objects/stralg.o : dynstr/stralg.c
	$(OCC) $(CFLAGS) $^

llist/objects/llist.o : llist/llist.c
	$(OCC) $(CFLAGS) $^

llist/objects/llalg.o : llist/llalg.c
	$(OCC) $(CFLAGS) $^

vector/objects/vector.o : vector/vector.c
	$(OCC) $(CFLAGS) $^

###############################################################################

test : libmds.so tests/hello tests/jumble tests/llist tests/llist_huge tests/vector tests/vector_huge
	@echo 'Run this:  export LD_LIBRARY_PATH=$$(pwd)'

tests/hello : tests/hello.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/jumble : tests/jumble.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/llist : tests/llist.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/llist_huge : tests/llist_huge.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/vector : tests/vector.c
	$(CC) $(CFLAGS) -L. -lmds $<

tests/vector_huge : tests/vector_huge.c
	$(CC) $(CFLAGS) -L. -lmds $<

clean : FORCE
	rm -f */objects/*.o
	(cd tests/; rm -f `grep --colour=never -r -I -L .`)

FORCE :
