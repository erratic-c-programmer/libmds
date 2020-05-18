#include <stdio.h>
#include "../types.h"
#include "../libmds.h"

int main(void)
{
	string *mystr = str_create();
	str_append(mystr, "Hello, ", 7);
	str_append(mystr, "world!f", 7);
	str_trunc(mystr, 13);
	printf("%s\n", mystr->str);
	str_del(mystr);
}
