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

void llist_addnode(struct llist *in, generic_t data, int pos)
{
	/* WARNING! Contains hazardous amounts of pointer wrangling! */
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->abs_parent = NULL;

	if (pos == 0) { /* In this case new_node->prev always points to NULL */
		if (in->len == 0) {
			in->first = new_node;
			in->last = new_node;
		} else {
			in->first->prev = new_node;
			new_node->next = in->first;
			in->first = new_node;
		}
	} else if (pos == in->len) { /* In this case new_node->next points to NULL */
		in->last->next = new_node;
		new_node->prev = in->last;
		in->last = new_node;
	} else {
		struct llist_node *t = in->first;
		for (int i = 0; i < pos; i++) {
			t = t->next;
		}

		t->prev->next = new_node;
		new_node->prev = t->prev;
		new_node->next = t;
		t->prev = new_node;
	}

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