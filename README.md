# A library of misc. data structures

###### Note:
Beware! For generic containers please prefix data passed into functions
with TO_GT which is a macro that expands to (generic_t)

Like so:
```c
llist_addnode(myllist /* list to append to */, TO_GT myint /* data */, 0 /* position */
```

## Data structures:
### Dynamic string (datatype `string`)
#### Methods
-`string *str_create(void)`: return a newly-created a dynamic string

-`void str_del(string *str)`: delete a dynamic string

-`void str_append(string *str, const char *s)`: append to a dynamic string

-`void str_trunc(string *str, int len)`: truncate a dynamic string to `len` length

-`void str_flush(string *str)`: truncate a dynamic string to 0 length

-`string *str_shuf(string *str)`: return a newly-created jumbled-up copy of `str`

_______________________________________________________________________________________
### Linked list
