#include "headers/llalg.h"

bool cmp_int_smaller(long long int a, long long int b)
{
	return a < b ? true : false;
}

bool cmp_int_greater(long long int a, long long int b)
{
	return a > b ? true : false;
}

void llist_qsort(struct llist *in, bool (*cmp)(long long int, long long int))
{
	/* Naive pivot */
	long long int pivot;
	for (int i = 0; i < llist->len; i++) {
		pivot = llist_getval(in, 0).int_t;
		for (int j = 0; j < llist->len; j++) {
			if (cmp(pivot, j)) {
				llist_swap(in, pivot, j);
				pivot = j;
			}
		}
	}
}
