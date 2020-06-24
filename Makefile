AR=ar
CC=gcc
OCC=$(CC) -c
CFLAGS=-Wall -Wpointer-arith -fPIC -g -o $@

.PHONY : all static dynamic

all : static dynamic test

static : libmds.a

dynamic : libmds.so

libmds.a : dynstr/strop.o llist/llist.o vector/vector.o
	$(AR) rcs $@ $^

libmds.so : dynstr/strop.o llist/llist.o vector/vector.o
	$(CC) $(CFLAGS) -shared $^

###############################################################################

test : tests/hello tests/llist tests/llist_huge tests/vector tests/vector_huge

tests/hello : tests/hello.c libmds.a
	$(CC) $(CFLAGS) $^

tests/llist : tests/llist.c libmds.a
	$(CC) $(CFLAGS) $^

tests/llist_huge : tests/llist_huge.c libmds.a
	$(CC) $(CFLAGS) $^

tests/vector : tests/vector.c libmds.a
	$(CC) $(CFLAGS) $^

tests/vector_huge : tests/vector_huge.c libmds.a
	$(CC) $(CFLAGS) $^

clean : FORCE
	rm -f */*.o
	(cd tests/; rm -f `grep --colour=never -r -I -L .`)

cleanproper : clean FORCE
	rm -f *.a *.so

FORCE :
