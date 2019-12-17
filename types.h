#define INCLUDE_TYPES

typedef struct {
	int len;
	char *str;
} string;

typedef union {
	char char_t;
	int int_t;
	long int lint_t;
	long long int llint_t;
	float float_t;
	double double_t;
	long double ldouble_t;
	char *cstring_t;
	string *string_t;
	struct llist *llist_t;
} generic_t;

struct llist {
	struct llist_node *first;
	struct llist_node *last;
	int len;
};

struct llist_node {
	generic_t data;
	struct llist_node *prev;
	struct llist_node *next;
	struct llist *abs_parent;
};

#define TO_GT (generic_t)
