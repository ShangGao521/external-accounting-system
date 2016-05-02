#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "readline.h"

// see dictionary.h for documentation
#include "dictionary.h"

// this is *mostly* the version from the notes

// Do NOT modify this file.

struct bstnode {
  char *item;  // key
  int value;
  struct bstnode *left;
  struct bstnode *right;
};

struct dictionary {
  struct bstnode *root;
};


struct dictionary *dict_create(void) {
  struct dictionary *d = malloc(sizeof(struct dictionary));
  d->root = NULL;
  return d;
}

static char *my_strdup (const char *s) {
  char *newstr = malloc((strlen(s) + 1) * sizeof(char));
  strcpy(newstr, s);
  return newstr;
}


struct bstnode *insert_bstnode(const char *key, int val, struct bstnode *node) {
  if (node == NULL) {
    node = malloc(sizeof(struct bstnode));
    node->item = my_strdup(key);
    node->value = val;
    node->left = NULL;
    node->right = NULL;
  } else {
    int cmpval = strcmp(key, node->item);
    if (cmpval < 0) {
      node->left = insert_bstnode(key, val, node->left);
    } else if (cmpval > 0) {
      node->right = insert_bstnode(key, val, node->right);
    } else {
      node->value += val;
    }
  }
  return node;
}


void dict_add(const char *key, int val, struct dictionary *d) {
  d->root = insert_bstnode(key, val, d->root);
}


int dict_lookup(const char *key, const struct dictionary *d) {
  struct bstnode *curnode = d->root;
  while (curnode) {
    int cmpval = strcmp(key, curnode->item);
    if (cmpval == 0) return curnode->value;
    if (cmpval < 0) {
      curnode = curnode->left;
    } else {
      curnode = curnode->right;
    }
  }
  return INT_MIN;
}




static struct bstnode *remove_bstnode(int key, struct bstnode *node) {
  if (node == NULL) return NULL;
  if (key < node->value) {
    node->left = remove_bstnode(key, node->left);
  } else if (key > node->value) {
    node->right = remove_bstnode(key, node->right);
  } else if (node->left == NULL) {
    struct bstnode *backup = node->right;
    free(node);
    return backup;
  } else if (node->right == NULL) {
    struct bstnode *backup = node->left;
    free(node);
    return backup;
  } else {
    struct bstnode *next = node->right;
    while (next->left) {
      next = next->left;
    }
    free(node->item);
    node->value = next->value;
    node->item = my_strdup(next->item);
    node->right = remove_bstnode (next->value, node->right);
  }
  return node;
}


void dict_remove(int key, struct dictionary *d) {
  d->root = remove_bstnode(key, d->root);
}

void free_bstnode(struct bstnode *node) {
  if (node) {
    free_bstnode(node->left);
    free_bstnode(node->right);
    free(node->item);
    free(node);
  }
}



void dict_destroy(struct dictionary *d) {
  free_bstnode(d->root);
  free(d);
}

bool dict_find(const char *key, const struct dictionary *d) {
  struct bstnode *curnode = d->root;
  while (curnode) {
    int cmpval = strcmp(key, curnode->item);
    if (cmpval == 0) return true;
    if (cmpval < 0) {
      curnode = curnode->left;
    } else {
      curnode = curnode->right;
    }
  }
  return false;
}


