#ifndef INCLUDE_TYPES
#include "../../types.h"
#endif
#ifndef INCLUDE_STDLIB
#include <stdlib.h>
#endif
#define INCLUDE_LLIST

struct llist *llist_create(void);
generic_t llist_getval(struct llist *in, int node_no);
void llist_del(struct llist *in);
void llist_addnode(struct llist *in, generic_t data, int pos);
generic_t llist_getval(struct llist *in, int node_no);
