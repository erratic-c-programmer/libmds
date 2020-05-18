#include "llist.h"

struct llist *llist_create(ssize_t datasize)
{
	struct llist *retval = malloc(sizeof(struct llist));
	CHECKNULL(retval) NULL;
	/* ...And it's up to the program to check errno for
	 * ENOMEM.
	 */

	retval->first = NULL;
	retval->last = NULL;
	retval->datasize = datasize;
	retval->len = 0;

	return retval;
}

void llist_del(struct llist *in)
{
	CHECKNULL(in);
	struct llist_node *t = in->last;

	while (t->prev != NULL) {
		t = t->prev;
		free(t->next->data);
		free(t->next);
	}

	free(in->first->data);
	free(in->first);
	free(in);
}

void __llist_pushfront(struct llist *in, void *data)
{
	CHECKNULL(in);
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = calloc(1, in->datasize);
	memcpy(new_node->data, data, in->datasize);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->root = NULL;
	if (in->len == 0) {
		in->first = new_node;
		in->last = new_node;
	} else {
		in->first->prev = new_node;
		new_node->next = in->first;
		in->first = new_node;
	}
	in->len++;
}

void __llist_pushback(struct llist *in, void *data)
{
	CHECKNULL(in);
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = calloc(1, in->datasize);
	memcpy(new_node->data, data, in->datasize);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->root = NULL;
	if (in->len == 0) {
		in->first = new_node;
		in->last = new_node;
	} else {
		in->last->next = new_node;
		new_node->prev = in->last;
		in->last = new_node;
	}
	in->len++;
}

void __llist_emplace(struct llist *in, void *data, struct llist_node *pos)
{
	CHECKNULL(in);
	struct llist_node *new_node = malloc(sizeof(struct llist_node));
	new_node->data = calloc(1, in->datasize);
	memcpy(new_node->data, data, in->datasize);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->root = NULL;
	pos->prev->next = new_node;
	new_node->prev = pos->prev;
	new_node->next = pos;
	pos->prev = new_node;
	new_node->root = in;
	in->len++;
}

void llist_erase(struct llist *in, struct llist_node *pos)
{
	CHECKNULL(in);
	CHECKNULL(pos);
	if (pos != in->first)
		pos->prev->next = pos->next;
	if (pos != in->last)
		pos->next->prev = pos->prev;

	free(pos->data);
	free(pos);
	in->len--;
}

void llist_swap(struct llist *in, int first, int second)
{
	CHECKNULL(in);
	void *t;
	t = __llist_getval(in, first);
	llist_getnode(in, first)->data = llist_getnode(in, second)->data;
	llist_getnode(in, second)->data = t;
}

struct llist_node *llist_getnode(struct llist *in, int node_no)
{
	CHECKNULL(in) NULL;
	struct llist_node *t = in->first;
	for (int i = 0; i < node_no; i++)
		t = t->next;
	return t;
}

void *__llist_getval(struct llist *in, int node_no)
{
	if (in == NULL) {
		errno = EFAULT; /* Up to the program to check this! */
		return NULL;
	}

	return llist_getnode(in, node_no)->data;
}
