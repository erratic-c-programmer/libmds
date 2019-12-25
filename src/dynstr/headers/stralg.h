/*!
 * @file stralg.h
 * @brief Some algorithms used on strings
 */

#ifndef INCLUDE_TYPES
#include "../../types.h"
#endif
#ifndef INCLUDE_STROP
#include "strop.h"
#endif
#ifndef INCLUDE_TIME
#include <time.h>
#define INCLUDE_TIME
#endif
#define INCLUDE_STRALG

/*!
 * @brief Shuffles a dynamic string
 *
 * Returns a jumbled-up copy of @p *str
 */
string *str_shuf(string *str);
