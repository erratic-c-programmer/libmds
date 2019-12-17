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
	for (int i = 0; i < new->len; i++)
		printf("%d\n", llist_getval(new, i).int_t);
	llist_del(new);
}
