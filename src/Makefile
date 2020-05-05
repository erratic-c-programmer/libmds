AR=ar
CC=gcc
OCC=$(CC) -c
CFLAGS=-Wall -Wpointer-arith -fPIC -g -o $@

.PHONY : all

all : static dynamic test
	@echo -e "\033[0;31mRun this:  export LD_LIBRARY_PATH=\$${LD_LIBRARY_PATH}:$$(pwd)\033[0m"

static : libmds.a

dynamic : libmds.so

libmds.a : obj/strop.o obj/llist.o obj/vector.o
	$(AR) rcs $@ $^

libmds.so : obj/strop.o obj/llist.o obj/vector.o
	$(CC) $(CFLAGS) -shared $^

###############################################################################

test : libmds.so tests/hello tests/llist tests/llist_huge tests/vector tests/vector_huge

tests/hello : tests/hello.c
	$(CC) $< $(CFLAGS) -L. -lmds

tests/llist : tests/llist.c
	$(CC) $< $(CFLAGS) -L. -lmds

tests/llist_huge : tests/llist_huge.c
	$(CC) $< $(CFLAGS) -L. -lmds

tests/vector : tests/vector.c
	$(CC) $< $(CFLAGS) -L. -lmds

tests/vector_huge : tests/vector_huge.c
	$(CC) $< $(CFLAGS) -L. -lmds

clean : FORCE
	rm -f obj/*
	(cd tests/; rm -f `grep --colour=never -r -I -L .`)

cleanproper : clean FORCE
	rm -f *.a *.so

FORCE :
