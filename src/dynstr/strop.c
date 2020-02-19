#ifndef INCLUDE_STROP
#include "strop.h"
#endif

/* TODO: malloc safety checks */

string *str_create(void)
{
	string *new = malloc(sizeof(string));
	new->str = malloc(sizeof(char));
	new->str[0] = '\0';
	new->len = 0;
	return new;
}

void str_append(string *str, const char *s, size_t bufsz)
{
	assert(str != NULL);
	char *tmp = realloc(str->str, bufsz + str->len + 1);
	str->str = tmp;
	str->len += bufsz;
	strcat(str->str, s);
}

void str_del(string *str)
{
	assert(str != NULL);
	free(str->str);
	free(str);
}

void str_trunc(string *str, size_t nsz)
{
	assert(str != NULL);
	str->str[nsz] = '\0'; /*This it a bit hacky, but it works */
	str->len = nsz;
}

void str_flush(string *str)
{
	assert(str != NULL);
	str_trunc(str, 0); /* lol why */
}
