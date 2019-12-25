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
	llist_pushfront(new, &(int){1});
	llist_pushback(new, &(int){2});
	llist_pushback(new, &(int){3});
	llist_pushback(new, &(int){4});
	llist_pushback(new, &(int){5});
	llist_pushback(new, &(int){6});
	llist_pushback(new, &(int){7});
	llist_pushback(new, &(int){9});
	llist_pushback(new, &(int){10});
	llist_pushback(new, &(int){11});
	llist_emplace(new, &(int){8}, llist_getnode(new, 7));
	llist_swap(new, 8, 9);
	llist_erase(new, llist_getnode(new, 4));
}
