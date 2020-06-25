#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

void modll(struct llist *new);

int main(void)
{
	struct llist *new = llist_create(sizeof(int));
	modll(new);
	for (int i = 0; i < new->len; i++)
		printf("%d\n", llist_getval(new, i, int));

	printf("Memory used: %lu bytes | Constant size %lu + %d nodes of size %lu + %lu each\n", \
			new->len * (sizeof(struct llist_node) + sizeof(int)) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node), sizeof(int));
	llist_del(new);
}

void modll(struct llist *new)
{
	llist_pushfront(new, 1, int);
	llist_pushback(new, 2, int);
	llist_pushback(new, 3, int);
	llist_pushback(new, 4, int);
	llist_pushback(new, 5, int);
	llist_pushback(new, 6, int);
	llist_pushback(new, 7, int);
	llist_pushback(new, 8, int);
	llist_pushback(new, 9, int);
	llist_pushback(new, 10, int);
	llist_erase(new, 0);
	llist_pushback(new, 11, int);
	llist_insert(new, 8, llist_getnode(new, 7), int);
	llist_swap(new, 8, 9);
	llist_erase(new, llist_getnode(new, 4));
}
