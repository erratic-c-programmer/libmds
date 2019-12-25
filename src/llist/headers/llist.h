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
void llist_pushback(struct llist *in, void *data);
void llist_pushfront(struct llist *in, void *data);
void llist_emplace(struct llist *in, void *data, struct llist_node *pos);
void llist_erase(struct llist *in, struct llist_node *pos);
void llist_swap(struct llist *in, int first, int second);
struct llist_node *llist_getnode(struct llist *in, int node_no);
