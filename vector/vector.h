#include <stdlib.h>
#include <string.h>
#include "../util.h"
#ifndef INCLUDE_TYPES
#include "../types.h"
#endif
#define INCLUDE_VECTOR

#define PREALLOC 4

struct vector *vector_create(ssize_t datasize);
void vector_del(struct vector *in);
void *__vector_pushback(struct vector *in, void *data);
void *__vector_pushfront(struct vector *in, void *data);
void *__vector_insert(struct vector *in, void *data, int pos);
void vector_erase(struct vector *in, int pos);
void vector_shrinkfit(struct vector *in);

/* "Function" macros */

#define vector_popfront(in) \
	(vector_erase((in), 0))

#define vector_popback(in) \
	(vector_erase((in), in->len - 1))

#define vector_pushback(vec, data, type) \
	(__vector_pushback((vec), &(type){data}))

#define vector_pushfront(vec, data, type) \
	(__vector_pushfront((vec), &(type){data}))

#define vector_insert(vec, data, pos, type) \
	(__vector_insert((vec), &(type){data}, pos))

#define vector_get(vec, ind, type) \
	(*(type*)(vec)->data[ind])

#define vector_getptr(vec, ind, type) \
	((type*)(vec)->data[ind])
