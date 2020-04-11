#include "vector.h"

struct vector *vector_create(ssize_t datasize)
{
	struct vector *retval = malloc(sizeof(struct vector));
	retval->data = malloc(PREALLOC * sizeof(void*));
	for (int i = 0; i < PREALLOC; i++)
		retval->data[i] = calloc(1, datasize);

	retval->datasize = datasize;
	retval->len = 0;
	retval->cap = PREALLOC;
	return retval;
}

void vector_del(struct vector *in)
{
	for (int i = 0; i < in->cap; i++) {
		free(in->data[i]);
	}
	free(in->data);
	free(in);
}

#define max(A, B) ((A) > (B) ? (A) : (B))
static void vec_realloc_asneeded(struct vector *in)
{
	if (in->len == in->cap) {
		size_t realloc_sz = 2 * in->cap;
		void **t = realloc(in->data, realloc_sz * sizeof(void*));
		in->data = t;
		for (int i = in->len; i < realloc_sz; i++)
			in->data[i] = calloc(1, in->datasize);

		in->cap = realloc_sz;
	}
}
#undef max

void __vector_pushback(struct vector *in, void *data)
{
	vec_realloc_asneeded(in);
	memcpy(in->data[in->len], data, in->datasize);
	in->len++;
}

void __vector_pushfront(struct vector *in, void *data)
{
	vec_realloc_asneeded(in);
	for (int i = in->len; i > 0; i--)
		memcpy(in->data[i], in->data[i - 1], in->datasize);
	memcpy(in->data[0], data, in->datasize);
	in->len++;
}

void __vector_insert(struct vector *in, void *data, int pos)
{
	vec_realloc_asneeded(in);

	for (int i = in->len; i > pos; i--)
		memcpy(in->data[i], in->data[i - 1], in->datasize);

	memcpy(in->data[pos], data, in->datasize);
	in->len++;
}

void vector_erase(struct vector *in, int pos)
{
	if (!in->len)
		return;
	
	for (int i = pos; i < in->len; i++)
		memcpy(in->data[i], in->data[i + 1], in->datasize);

	in->len--;
}

void vector_shrinkfit(struct vector *in)
{
	if (!in->cap)
		return;

	while (in->cap != in->len) {
		free(in->data[in->cap - 1]);
		in->cap--;
	}
	void **t = realloc(in->data, in->len * sizeof(void*));
	in->data = t;
}
