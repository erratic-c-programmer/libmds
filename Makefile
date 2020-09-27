WARNINGS += -Wpedantic
WARNINGS += -Wall
WARNINGS += -Wextra
WARNINGS += -Waggregate-return
WARNINGS += -Wbad-function-cast
WARNINGS += -Wcast-align
WARNINGS += -Wcast-qual
WARNINGS += -Wdeclaration-after-statement
WARNINGS += -Wfloat-equal
WARNINGS += -Wformat=2
WARNINGS += -Wmissing-declarations
WARNINGS += -Wmissing-include-dirs
WARNINGS += -Wmissing-prototypes
WARNINGS += -Wnested-externs
WARNINGS += -Wpointer-arith
WARNINGS += -Wredundant-decls
WARNINGS += -Wsequence-point
WARNINGS += -Wshadow
WARNINGS += -Wstrict-prototypes
WARNINGS += -Wswitch
WARNINGS += -Wundef
WARNINGS += -Wunreachable-code
WARNINGS += -Wunused-parameter
WARNINGS += -Wwrite-strings
WARNINGS += -Werror

DEBUG = -g
OPTIM = -O3 -march=native -mtune=native
CFLAGS= $(WARNINGS) $(DEBUG) $(OPTIM) -std=c99 -fPIC -o $@
CC=gcc
OCC=$(CC) -c
AR=ar
.PHONY : all static dynamic test

all : static dynamic test

static : libmds.a

dynamic : libmds.so

libmds.a : dynstr/strop.o llist/llist.o vector/vector.o
	$(AR) rcs $@ $^

libmds.so : dynstr/strop.o llist/llist.o vector/vector.o
	$(CC) $(CFLAGS) -shared $^

%.o : %.c %.h
	$(OCC) $(CFLAGS) $<

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
