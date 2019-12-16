#include <stdio.h>
#include "../dynstr/headers/strop.h"
#include "../dynstr/headers/stralg.h"

int main(void)
{
	string *mystr = str_create();
	str_append(mystr, "abcdefghijklmnopqrstuvwxyz", 26);
	string *jstring = str_shuf(mystr);
	printf("%s\n%s\n", mystr->str, jstring->str);
	return 0;
}
