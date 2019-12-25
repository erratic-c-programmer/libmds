#include "headers/stralg.h"

string *str_shuf(string *str)
{
	string *newstr = str_create();
	int random;
	int random2;
	char t;
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	str_append(newstr, str->str, str->len);
	srand(ts.tv_nsec);
	for (int i = 0; i < str->len; i++) {
		random = rand() % str->len;
		random2 = rand() % str->len;
		t = newstr->str[random];
		newstr->str[random] = newstr->str[random2];
		newstr->str[random2] = t;
	}
	return newstr;
}
