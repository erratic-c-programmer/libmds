#include <stdio.h>
#include "../llist/headers/llist.h"

int main(void)
{
	struct llist *new = llist_create();
	llist_addnode(new, TO_GT 1, 0);
	llist_addnode(new, TO_GT 2, 0);
	llist_addnode(new, TO_GT 3, 0);
	llist_addnode(new, TO_GT 4, 0);
	printf("%d\n", llist_getval(new, 0).int_t);
	printf("%d\n", llist_getval(new, 1).int_t);
	printf("%d\n", llist_getval(new, 2).int_t);
	printf("%d\n", llist_getval(new, 3).int_t);
	llist_del(new);
}
