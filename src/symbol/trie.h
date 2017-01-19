/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_TRIE_H
#define __TOYBOX_TRIE_H


#include <symbol/map.h>


/**
 */
struct trie_node {
  unsigned int end;
  const char   value;
  struct trie_node *lookup[DEFAULT_TABLESIZE];
};


/**
   Trie structure implementation.
 */
struct trie {
  struct trie_node root;
  unsigned int size;
};



struct trie *create_trie_structure();




#endif // __TOYBOX_TRIE_H
