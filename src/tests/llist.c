#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

void modll(struct llist *new);

int main(void)
{
	struct llist *new = llist_create(sizeof(int));
	modll(new);
	for (int i = 0; i < new->len; i++)
		printf("%d\n", *(int*)llist_getval(new, i));

	printf("Memory used: %lu bytes | Constant size %lu + %d nodes of size %lu + %lu each\n", \
			new->len * (sizeof(struct llist_node) + sizeof(int)) + sizeof(struct llist), \
			sizeof(struct llist), new->len, sizeof(struct llist_node), sizeof(int));
	llist_del(new);
}

void modll(struct llist *new)
{
	llist_addnode(new, &(int){1}, 0);
	llist_addnode(new, &(int){2}, 1);
	llist_addnode(new, &(int){3}, 2);
	llist_addnode(new, &(int){4}, 3);
	llist_addnode(new, &(int){5}, 0);
	llist_addnode(new, &(int){6}, 3);
	llist_addnode(new, &(int){7}, 6);
	llist_addnode(new, &(int){8}, 7);
	llist_addnode(new, &(int){9}, 8);
	llist_addnode(new, &(int){10}, 9);
	llist_addnode(new, &(int){11}, 9);
	llist_swap(new, 8, 9);
	llist_rmnode(new, 4);
}
