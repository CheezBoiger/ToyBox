/*
  Copyright (c) Mario Garcia, Michael Wallace, Under the GNU Public v2 License.
 */
#include <symbol/trie.h>
#include <stdlib.h>



enum err_t trie_init(struct trie *trie)
{
    trie->root = (struct trie_node*)calloc(1,sizeof(struct trie_node));
    trie->root->children[0] = (struct trie_node*)calloc(1, sizeof(struct trie_node[DEFAULT_TABLESIZE]));
}

/**
Inserts a value to the trie structure.

@param tree
@param str
@return err_success (1) on successfully inserting, otherwise
err_fail (0) is returned.
*/
enum err_t trie_insert(struct trie *tree, char *str)
{
    
    int i = 0;
    int length = (int)strlen(str);    
    struct trie_node *temp = tree->root;
    while (i < length)
    {
        int position = str[i] - 'a';//check if upper or lower
        //no node in the tree corresponding to char in str
        if (temp->children[position] == NULL)
        {    
            struct trie_node *newTrie = malloc(sizeof(struct trie_node));
            memset(newTrie->children, 0, sizeof(newTrie->children));
            temp->children[position] = newTrie;
        }
        
        temp = temp->children[position];
        ++i;
    }
    temp->end = 1;
}


int32 trie_lookup(struct trie *tree, char *str)
{
    struct trie_node *temp = tree->root;
    int length = (int)strlen(str);
    int i = 0;
    int position = str[0] - 'a';//check if upper or lower
    while (i < length)
    {   
        if (temp->children[position] != NULL)
        {
            temp = temp->children[position];
            position = str[++i] - 'a';
        }
        else
        {
            break;
        }
    }

    if (i == length && temp->end != 0)
    {
        return 1;
    }
    return 0;
}