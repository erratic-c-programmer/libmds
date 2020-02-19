#ifndef INCLUDE_TYPES
#include "../types.h"
#endif
#ifndef INCLUDE_STDLIB
#include <stdlib.h>
#define INCLUDE_STDLIB
#endif
#ifndef INCLUDE_STRING
#include <string.h>
#define INCLUDE_STRING
#endif
#define INCLUDE_VECTOR

#define PREALLOC 4

struct vector *vector_create(size_t datasize);
void vector_del(struct vector *in);
void vector_pushback(struct vector *in, void *data);
void vector_pushfront(struct vector *in, void *data);
void vector_insert(struct vector *in, void *data, int pos);
void vector_erase(struct vector *in, int pos);
void vector_shrinkfit(struct vector *in);

/* "Function" macros */

#define __vector_assert(in) \
	(void) (in)->len; \
	(void) (in)->cap; \
	(void) (in)->data;

#define vector_popfront(in) \
	__vector_assert((in)); \
	(vector_erase((in), 0))

#define vector_popback(in) \
	__vector_assert((in)); \
	(vector_erase((in), (in)->(len - 1)))
