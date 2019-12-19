#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../types.h"
#include "../llist/headers/llist.h"


int main(void)
{
	struct llist *new = llist_create();

	for(int i = 0; i < 1000000; i++)
		llist_addnode(new, TO_GT i, i);

	/*
	for (int i = 0; i < new->len; i++)
		printf("%d\n", llist_getval(new, i).int_t);
	*/

	printf("Memory used: %d bytes | Constant size %d + %d nodes of size %d each\n", \
			new->len * sizeof(struct llist_node) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node));

	llist_del(new);
}
