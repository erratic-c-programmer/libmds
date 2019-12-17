# A library of misc. data structures

###### On data structures:
Beware! For generic containers please prefix data passed into functions
with TO_GT which is a macro that expands to (generic_t)

Like so:
```c
llist_addnode(myllist /* list to append to */, TO_GT myint /* data */, 0 /* position */
```
