#include "headers/llist.h"

struct llist *llist_create(size_t datasize)
{
	struct llist *retval = malloc(sizeof(struct llist));
	retval->first = NULL;
	retval->last = NULL;
	retval->datasize = datasize;
	retval->len = 0;
	return retval;
}

void llist_del(struct llist *in)
{
	assert(in != NULL);
	struct llist_node *t = in->last;

	while (t->prev != NULL) {
		t = t->prev;
		free(t->next);
		free(t->next->data);
	}

	free(in->first->data);
	free(in->first);
	free(in);
}

void llist_addnode(struct llist *in, void *data, int pos)
{
	/* WARNING! Contains hazardous amounts of pointer wrangling! */
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = calloc(1, in->datasize);
	memcpy(new_node->data, data, in->datasize);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->root = NULL;

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

	new_node->root = in;
	(in->len)++;
}

void llist_rmnode(struct llist *in, int pos)
{
	struct llist_node *t = llist_getelem(in, pos);
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
	(in->len)--;
}

void llist_swap(struct llist *in, int first, int second)
{
	void *t;
	t = llist_getval(in, first);
	llist_getelem(in, first)->data = llist_getelem(in, second)->data;
	llist_getelem(in, second)->data = t;
}

struct llist_node *llist_getelem(struct llist *in, int node_no)
{
	struct llist_node *t = in->first;
	for (int i = 0; i < node_no; i++)
		t = t->next;
	return t;
}

void *llist_getval(struct llist *in, int node_no)
{
	return llist_getelem(in, node_no)->data;
}
