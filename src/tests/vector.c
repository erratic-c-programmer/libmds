#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

int main(void)
{
	struct vector *new = vector_create(sizeof(int));
	vector_pushback(new, 1, int);
	vector_pushback(new, 2, int);
	vector_pushback(new, 3, int);
	vector_pushfront(new, 4, int);
	vector_insert(new, 5, 1, int);
	vector_pushback(new, 6, int);
	vector_erase(new, 3);
	vector_popfront(new);
	vector_shrinkfit(new);
	for (int i = 0; i < new->len; i++)
		printf("%d\n", vector_get(new, i, int));
	printf("Memory used: %lu bytes | Constant size %lu + %lu elements of size (%lu + %lu) each\n", \
			sizeof(struct vector) + new->len * new->datasize + new->len * sizeof(void*), \
			sizeof(struct vector), new->len, new->datasize, sizeof(void*));
	vector_del(new);
	return 0;
}
