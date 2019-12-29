#ifndef INCLUDE_TYPES
#include "../../types.h"
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
void vector_popback(struct vector *in);
void vector_pushfront(struct vector *in, void *data);
void vector_popfront(struct vector *in);
void vector_shrinkfit(struct vector *in);
void vector_insert(struct vector *in, void *data, int pos);
