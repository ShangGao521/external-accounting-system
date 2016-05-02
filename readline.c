#include <stdio.h>
#include <stdlib.h>

char *readline(void) {
  char c;
  if (scanf(" %c", &c) != 1) return NULL;
  int maxlen = 80;  
  char *str = malloc(maxlen * sizeof(char));
  int len = 0;
  do {
    str[len] = c;
    ++len;
    if (len == maxlen) {    // DOUBLE the allocated array size
      maxlen *= 2;
      str = realloc(str, maxlen * sizeof(char));
    }
    if (scanf("%c", &c) != 1) break;
  } while (c != '\n');   // read to the end of the line
  str[len] = '\0';
  // shrink the array back down to the correct size
  str = realloc(str, (len + 1) * sizeof(char));
  return str;
}


