#ifndef INCLUDE_STDDEF
#include <stddef.h>
#define INCLUDE_STDDEF
#endif
#define INCLUDE_TYPES

/* And since this is about types... */
#include <sys/types.h>

/*! @brief A dynamic string
 *
 * A dynamically-allocated char array
 */
typedef struct {
	 /*! The actual string */
	char *str;
	/*! Length of string */
	int len;
} string;

/*! @brief Dynamic array
 *
 * Basically has an array of void pointers that point to data
 */
struct vector {
	/*! Pointers to actual data */
	void **data;
	/*! Size of each element in data array */
	ssize_t datasize;
	/*! Current length(=used) */
	ssize_t len;
	/*! Current size of data array(=used+unused) */
	ssize_t cap;
};

/*! @brief Doubly-linked list
 */
struct llist {
	/*! First node of linked list */
	struct llist_node *first;
	/*! Last node of linked list */
	struct llist_node *last;
	/*! Size of each element */
	ssize_t datasize;
	/*! Length of linked list */
	int len;
};

/*! @brief A node in llist 
 */
struct llist_node {
	/*! void pointer to actual data */
	void *data;
	/*! relative previous node in linked list; NULL if this is first node in linked list */
	struct llist_node *prev;
	/*! relative next node in linked list; NULL if this is last node in linked list */
	struct llist_node *next;
	/* the container struct llist of this node */
	struct llist *root;
};
