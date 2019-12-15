#include <stdio.h>
#include "../dynstr/headers/strop.h"

int main(void)
{
	string *mystr = str_create();
	str_append(mystr, "Hello, ", 7);
	str_append(mystr, "world!f", 7);
	str_trunc(mystr, mystr->len - 1);
	printf("%s\n", mystr->str);
	str_del(mystr);
}
