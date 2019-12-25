#ifndef INCLUDE_TYPES
#include "../../types.h"
#endif
#ifndef INCLUDE_STDLIB
#include <stdlib.h>
#define INCLUDE_STDLIB
#endif
#ifndef INCLUDE_STRING
#include <string.h>
#define INCLUDE_STRING
#endif
#ifndef INCLUDE_ASSERT
#include <assert.h>
#define INCLUDE_ASSERT
#endif
#define INCLUDE_LLIST

struct llist *llist_create(size_t datasize);
void *llist_getval(struct llist *in, int node_no);
void llist_del(struct llist *in);
void llist_addnode(struct llist *in, void *data, int pos);
void llist_rmnode(struct llist *in, int pos);
void llist_swap(struct llist *in, int first, int second);
struct llist_node *llist_getelem(struct llist *in, int node_no);
