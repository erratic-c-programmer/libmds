#include <stdio.h>
#include "../dynstr/headers/strop.h"
#include "../dynstr/headers/stralg.h"

char *buf;
size_t buflen;
int nread;

int main(void)
{
	string *mystr = str_create();
	printf("Enter a string: ");
	nread = getline(&buf, &buflen, stdin);
	str_append(mystr, buf, nread - 1);
	string *jstring = str_shuf(mystr);
	printf("%s\n%s\n", mystr->str, jstring->str);
	return 0;
}
