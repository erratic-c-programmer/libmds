#ifndef INCLUDE_STDLIB
#include <stdlib.h>
#define INCLUDE_STDLIB
#endif
#ifndef INCLUDE_STRING
#include <string.h>
#define INCLUDE_STRING
#endif
#define INCLUDE_STROP

typedef struct {
	int len;
	char *str;
} string;

string *str_create(void);
void str_del(string *str);
void str_append(string *str, const char *s, size_t bufsz);
void str_trunc(string *str, size_t nsz);
void str_flush(string *str);
