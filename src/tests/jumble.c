#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

char *buf;
size_t buflen;
int nread;

int main(void)
{
	string *mystr = str_create();
	printf("Enter a string: ");
	nread = getline(&buf, &buflen, stdin);
	str_append(mystr, buf, nread - 2);
	string *jstring = str_shuf(mystr);
	printf("%s\n%s\n", mystr->str, jstring->str);
	str_del(mystr);
	str_del(jstring);
	return 0;
}
