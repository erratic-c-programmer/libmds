#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

int main(void)
{
	struct vector *new = vector_create(sizeof(int));
	for (int i = 0; i < 1000000; i++) {
		vector_pushback(new, i, int);
	}
	printf("Memory used: %lu bytes | Constant size %lu + %lu elements of size (%lu + %lu) each\n", \
			sizeof(struct vector) + new->len * new->datasize + new->len * sizeof(void*), \
			sizeof(struct vector), new->len, new->datasize, sizeof(void*));
	vector_del(new);
	return 0;
}
