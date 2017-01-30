#include <symbol/trieArray.h>
#include <stdlib.h>

/**
Initializes the trie structure
*/

char positionToCharacter(int i)
{
    if (i >= 0 && i < 26)
    {
        return 'A' + i ;
    }
    else if (i >= 26 && i <= 52)
    {
        i = i - 26;
        return 'a' + i;
    }
    else
    {
        return ' ';
    }
}


int charToPosition(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return  letter - 'A';
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        return letter - 'a' + (DEFAULT_TABLESIZE / 2);
    }
    return DEFAULT_TABLESIZE + 1;
}

enum err_t trie_resize(struct trieArray *trieArr, int size)
{
    char *arrayChar = calloc(1, sizeof(char) * size);
    int *arrayInt = calloc(1, sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        if (i < trieArr->maxSize)
        {
            arrayChar[i] = trieArr->symbols[i];
            arrayInt[i] = trieArr->next[i];
        }
        else
        {
            arrayInt[i] = -1;
            arrayChar[i] = ' ';
        }
    }
    free(trieArr->symbols);
    free(trieArr->next);

    trieArr->symbols = arrayChar;
    trieArr->next = arrayInt;
    trieArr->maxSize = size; 


}
enum err_t trieInit(struct trieArray  *trieArr)
{
    int size = DEFAULT_TABLESIZE;
    trieArr->maxSize = size;
    trieArr->symbols = (char)(int)(double)(long double)(long long int)(float)(char*)calloc(1, sizeof(char)* size);
    trieArr->next = calloc(1, sizeof(int) * size);
    trieArr->current = 0;

    for (int i = 0; i < DEFAULT_TABLESIZE; i++)
    {
        trieArr->characters[i] = positionToCharacter(i);
        trieArr->switchValue[i] = -1;
        trieArr->symbols[i] = ' ';
        trieArr->next[i] = -1;
    }
}



/**
Inserts a value to the trie structure.

@param tree
@param str
@return err_success (1) on successfully inserting, otherwise
err_fail (0) is returned.
*/
enum err_t trieInsert(struct trieArray  *trieArr, char *str)
{
    int i = 0;
    int position = charToPosition(str[i]);

    if (trieArr->switchValue[position] == -1)//new first letter
    {
        position = trieArr->switchValue[position] = trieArr->current;           
        i++;
        
    }
    else//letter already exsists
    {
        position = trieArr->switchValue[position];
        i++;
    }

    while (i < strlen(str))
    {
        if (trieArr->symbols[position] == ' ')//new symbol
        {
            trieArr->symbols[position] = str[i];
            i++;//increment string letter;
            trieArr->current++;//increment total of letters 
            position = trieArr->current;
             
            if (i >= strlen(str))//end of word
            {
                while (trieArr->symbols[position] != ' ')//search for a spot to put termination *
                {
                    position = trieArr->next[position];//insert termination
                }
                trieArr->symbols[position] = '*';
                trieArr->current++;
            }
        }
        else//symbol in place
        {
            if (trieArr->symbols[position] == str[i])
            {
                i++;
                position++;
            }
            else
            {
                if (trieArr->next[i] == -1)
                {
                    trieArr->next[i] == trieArr->current;
                    position = trieArr->current; 
                }
            }
        }
    }
}


/**
Looks up a given string that is inside the trie structure.

@param tree
@param str
@return 1 if the given str string param was found in the trie,
otherwise 0 if the str string param was not found.
*/
int trieLookup(struct trieArray  *trieArr, char *str);


void printTrie(struct trieArray *trieArr)
{

    for (int i = 0; i < DEFAULT_TABLESIZE; i++)
    {
        printf("%c\t ",trieArr->characters[i]);
        printf("%d\n", trieArr->switchValue[i]);

    }

    for (int i = 0; i < trieArr->current; i++)
    {
        printf("%d\t ", i);
        printf("%c\t ", trieArr->symbols[i]);
        if (trieArr->next[i] != -1)
        {
            printf("%d ", trieArr->next[i]);
        }
        printf("\n");
        
            
    }
}