#include "headers/llist.h"

struct llist *llist_create(void)
{
	struct llist *retval = malloc(sizeof(struct llist));
	retval->first = NULL;
	retval->last = NULL;
	retval->len = 0;
	return retval;
}

void llist_del(struct llist *in)
{
	struct llist_node *t = in->last;
	while (t->next != NULL) {
		t = t->prev;
		free(t->next);
	}
	free(in->first);
	free(in);
}

void llist_addnode(struct llist *in, generic_t data)
{
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = data;
	if (in->len == 0) {
		in->first = new_node;
		in->last = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
		goto return_code;
	}
	new_node->prev = in->last;
	new_node->next = NULL;
	in->last->next = new_node;
	in->last = new_node;
return_code:
	new_node->abs_parent = in;
	(in->len)++;
}

generic_t llist_getval(struct llist *in, int node_no)
{
	struct llist_node *t = in->first;
	for (int i = 0; i < node_no; i++)
		t = t->next;
	return t->data;
}
