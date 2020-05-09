/*!
 * @file strop.h
 * @brief Functions to create, delete, append to, etc. a dynamic string
 */

#ifndef INCLUDE_TYPES
#include "../types.h"
#endif
#ifndef INCLUDE_STDLIB
#include <stdlib.h>
#define INCLUDE_STDLIB
#endif
#ifndef INCLUDE_STRING
#include <string.h>
#define INCLUDE_STRING
#endif
#define INCLUDE_STROP

/*!
 * @brief Create a new dynamic string
 *
 * Allocate memory for a new <tt>struct string</tt> and return a pointer to it
 * Example:
 * @code
 * struct string *mystr = str_create();
 * @endcode
 * @return A pointer to the newly-allocated dynamic string
 * @warning Remember to delete (deallocate) the string after allocating it!
 * @see str_del
 */
string *str_create(void);

/*!
 * @brief Delete a previously created (allocated) dynamic string
 * 
 * @param str Pointer to a previously created dynamic string
 * @see str_create
 */
void str_del(string *str);

/*!
 * @brief Append a char array to a dynamic string
 *
 * @param str Pointer to a dynamic string to append to
 * @param s C string of length @p bufsz to be appended to @p str
 * @param bufsz Size of @p s
 */
void str_append(string *str, const char *s, ssize_t bufsz);
void str_trunc(string *str, ssize_t nsz);
void str_flush(string *str);
