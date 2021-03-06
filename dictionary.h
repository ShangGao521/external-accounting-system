#include <limits.h>
#include <stdbool.h>

struct dictionary;


// dict_create() creates a new dictionary
// effects: allocates memory (call dict_destroy)
struct dictionary *dict_create(void);


// dict_add(key, val, d) adds key/value to d
//   if key already exists, it replaces the corresponding val
// requires: d is a valid dictionary
//           key is a valid string
//           val != INT_MIN
// effects: may modify d
void dict_add(const char *key, int val, struct dictionary *d);


// dict_lookup(key, d) finds the val for key in d
//   or produces INT_MIN if unsuccessful
// requires: d is a valid dictionary
//           key is a valid string
int dict_lookup(const char *key, const struct dictionary *d);


// dict_destroy(d) frees all memory for d
// requires: d is a valid dictionary
// effects: d is no longer valid
void dict_destroy(struct dictionary *d);

void dict_remove(int key, struct dictionary *d);
bool dict_find(const char *key, const struct dictionary *d);
