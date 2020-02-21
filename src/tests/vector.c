#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

int main(void)
{
	struct vector *new = vector_create(sizeof(int));
	vector_pushback(new, &(int){1});
	vector_pushback(new, &(int){2});
	vector_pushback(new, &(int){3});
	vector_pushback(new, &(int){4});
	vector_pushback(new, &(int){5});
	vector_pushfront(new, &(int){6});
	vector_insert(new, &(int){7}, 3);
	vector_insert(new, &(int){8}, 0);
	vector_insert(new, &(int){9}, 8);
	vector_pushfront(new, &(int){10});
	vector_pushfront(new, &(int){11});
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
