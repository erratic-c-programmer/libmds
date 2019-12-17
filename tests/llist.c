#include <stdio.h>
#include "../llist/headers/llist.h"

int main(void)
{
	struct llist *new = llist_create();
	llist_addnode(new, TO_GT 1, 0);
	llist_addnode(new, TO_GT 2, 1);
	llist_addnode(new, TO_GT 3, 2);
	llist_addnode(new, TO_GT 4, 3);
	llist_addnode(new, TO_GT 5, 0);
	llist_addnode(new, TO_GT 6, 3);
	llist_addnode(new, TO_GT 7, 6);
	llist_addnode(new, TO_GT 8, 7);
	llist_addnode(new, TO_GT 9, 8);
	llist_addnode(new, TO_GT 10, 9);
	llist_swap(new, 8, 9);
	for (int i = 0; i < new->len; i++)
		printf("%d\n", llist_getval(new, i).int_t);

	printf("Memory used: %d bytes | Constant size %d + %d nodes of size %d each\n", \
			new->len * sizeof(struct llist_node) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node));
	llist_del(new);
}
