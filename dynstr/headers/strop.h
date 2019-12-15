#include <stdlib.h>
#include <bsd/string.h>

typedef struct {
	int len;
	char *str;
} string;

string *str_create(void);
void str_del(string *str);
void str_append(string *str, const char *s, size_t bufsz);
void str_trunc(string *str, size_t nsz);
void str_flush(string *str);
