#include "headers/vector.h"

struct vector *vector_create(size_t datasize)
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
	free(in->data);
	free(in);
}

void vector_pushback(struct vector *in, void *data)
{
	if (in->len == in->cap) {
		void **t = realloc(in->data, (in->cap + PREALLOC) * sizeof(void*));
		in->data = t;
		for (int i = in->len; i < in->len + PREALLOC; i++)
			in->data[i] = calloc(1, in->datasize);

		in->cap += PREALLOC;
	}

	memcpy(in->data[in->len], data, in->datasize);
	(in->len)++;
}
