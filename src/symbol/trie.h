/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_TRIE_H
#define __TOYBOX_TRIE_H


#include <err/types.h>
#include <symbol/map.h>



/*

  TODO(Wallace): Should we implement the array structure instead?
  It is recommended...


 */


/**

 */
struct trie_node {
  unsigned int end;
  char   value;  
  struct trie_node *children[DEFAULT_TABLESIZE];
};


/**
   Trie structure implementation.
 */
struct trie {
  struct trie_node *root;
  unsigned int size;
};


/**
   Initializes the trie structure
 */
enum err_t trie_node_init(struct trie_node *node);

enum err_t trie_init(struct trie *trie);



/**
   Inserts a value to the trie structure.
   
   @param tree 
   @param str
   @return err_success (1) on successfully inserting, otherwise
   err_fail (0) is returned.
 */
enum err_t trie_insert(struct trie *tree, char *str);


/**
   Looks up a given string that is inside the trie structure.
   
   @param tree
   @param str
   @return 1 if the given str string param was found in the trie,
   otherwise 0 if the str string param was not found.
 */
int32 trie_lookup(struct trie *tree, int8 *str);


/**
   Destroys the trie structure and cleans up any memory allocated.
   
   @param tree
   @return err_success (1) if the tree was successfully cleaned up and destroyed,
   otherwise err_fail (0) if the trie could not successfully cleanup and destoy. 
 */
enum err_t trie_destroy(struct trie *tree); 


#endif // __TOYBOX_TRIE_H
