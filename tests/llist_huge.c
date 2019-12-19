#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../types.h"
#include "../llist/headers/llist.h"


int main(void)
{
	struct llist *new = llist_create(sizeof(int));

	for(int i = 0; i < 1000000; i++)
		llist_addnode(new, &(int){i}, i);

	/*
	for (int i = 0; i < new->len; i++)
		printf("%d\n", *(int*)llist_getval(new, i));
	*/

	printf("Memory used: %lu bytes | Constant size %lu + %d nodes of size %lu each\n", \
			new->len * sizeof(struct llist_node) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node));

	llist_del(new);
}
