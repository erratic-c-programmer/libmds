#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

int main(void)
{
	struct vector *new = vector_create(sizeof(int));
	for (int i = 0; i < 1000000; i++) {
		vector_pushback(new, &(int){i});
	}
	vector_del(new);
	return 0;
}
