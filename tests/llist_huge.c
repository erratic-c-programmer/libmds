#include <stdio.h>
#include "../types.h"
#include "../libmds.h"


int main(void)
{
	struct llist *new = llist_create(sizeof(int));

	for(int i = 0; i < 1000000; i++)
		llist_pushback(new, i, int);

	printf("Memory used: %lu bytes | Constant size %lu + %d nodes of size (%lu + %lu) each\n", \
			new->len * (sizeof(struct llist_node) + sizeof(int)) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node), sizeof(int));

	llist_del(new);
}
