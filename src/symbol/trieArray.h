#include <err/types.h>
#include <symbol/map.h>
#include <string.h>


struct trieArray
{
    char characters[DEFAULT_TABLESIZE];
    int switchValue[DEFAULT_TABLESIZE];
    char *symbols;
    int *next;
    int maxSize;
    int current;
};


/**
Initializes the trie structure
*/

enum err_t trieInit(struct trieArray  *trieArr);



/**
Inserts a value to the trie structure.

@param tree
@param str
@return err_success (1) on successfully inserting, otherwise
err_fail (0) is returned.
*/
enum err_t trieInsert(struct trieArray  *trieArr, char *str);


/**
Looks up a given string that is inside the trie structure.

@param tree
@param str
@return 1 if the given str string param was found in the trie,
otherwise 0 if the str string param was not found.
*/
int trieLookup(struct trieArray  *trieArr, char *str);


void printTrie(struct trieArray *trieArr);