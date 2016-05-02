#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dictionary.h"



void add_transaction (char *s, int num, struct dictionary *d) {
  bool in_dict = dict_find(s, d);
  dict_add(s, num, d);
  
}
  