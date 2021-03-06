#include <stdlib.h>
#include <string.h>
#ifndef INCLUDE_TYPES
#include "../types.h"
#endif
#define INCLUDE_LLIST

struct llist *llist_create(ssize_t datasize);
struct llist_node *llist_getnode(struct llist *in, int node_no);
void *__llist_getval(struct llist *in, int node_no);
void __llist_insert(struct llist *in, void *data, struct llist_node *pos);
void __llist_pushback(struct llist *in, void *data);
void __llist_pushfront(struct llist *in, void *data);
void llist_del(struct llist *in);
void llist_erase(struct llist *in, struct llist_node *pos);
void llist_popback(struct llist *in);
void llist_popfront(struct llist *in);
void llist_swap(struct llist *in, int first, int second);

/* "Function" macros */

#define llist_pushback(ll, data, type) \
	(__llist_pushback((ll), &(type){data}))

#define llist_pushfront(ll, data, type) \
	(__llist_pushfront((ll), &(type){data}))

#define llist_insert(ll, data, node, type) \
	(__llist_insert((ll), &(type){data}, node))

#define llist_getval(ll, ind, type) \
	*(type*)__llist_getval(ll, ind)
