#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../util.h"
#ifndef INCLUDE_TYPES
#include "../types.h"
#endif
#define INCLUDE_LLIST

struct llist *llist_create(ssize_t datasize);
void *__llist_getval(struct llist *in, int node_no);
void llist_del(struct llist *in);
void __llist_pushback(struct llist *in, void *data);
void __llist_pushfront(struct llist *in, void *data);
void __llist_emplace(struct llist *in, void *data, struct llist_node *pos);
void llist_erase(struct llist *in, struct llist_node *pos);
void llist_swap(struct llist *in, int first, int second);
struct llist_node *llist_getnode(struct llist *in, int node_no);
/* "Function" macros */

#define llist_popfront(in) \
	(llist_erase((in), llist_getnode(in, 0)))

#define llist_popback(in) \
	(llist_erase((in), llist_getnode(in, in->len - 1)))

#define llist_pushback(ll, data, type) \
	(__llist_pushback((ll), &(type){data}))

#define llist_pushfront(ll, data, type) \
	(__llist_pushfront((ll), &(type){data}))

#define llist_insert(ll, data, pos, type) \
	(__llist_emplace((ll), &(type){data}, llist_getnode(ll, pos)))

#define llist_getval(ll, ind, type) \
	*(type*)__llist_getval(ll, ind)
