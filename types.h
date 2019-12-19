#ifndef INCLUDE_STDDEF
#include <stddef.h>
#define INCLUDE_STDDEF
#endif
#define INCLUDE_TYPES

typedef struct {
	int len;
	char *str;
} string;

struct llist {
	struct llist_node *first;
	struct llist_node *last;
	size_t datasize;
	int len;
};

struct llist_node {
	void *data;
	struct llist_node *prev;
	struct llist_node *next;
	struct llist *abs_parent;
};
