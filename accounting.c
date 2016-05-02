#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include "readline.h"
#include "transaction.h"

int main(void) {
  struct dictionary *constants = dict_create();
  while(1) {
    printf("Please enter what you want to record. And enter the accoutning name first\n");
    char *s = readline();
    int num;
    scanf("%d", &num);
    if (s == NULL) break;
    add_transaction(s, num, constants);
    free(s);
  }
  dict_destroy(constants);
}
