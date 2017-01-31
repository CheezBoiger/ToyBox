//
//
//
#include <symbol/trieArray.h>
#include <debugger/debug.h>

#include <stdlib.h>
//#include <stdio.h>

//what position is our chacter at
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

//what position should we store our character in?
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

//resize the symbol and next dynmaic arrays
enum err_t trieResize(struct trieArray *trieArr, int size)
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


/**
Initializes the trie structure
*/

//init the arrays and allocates memory for the symbol and next arrays
enum err_t trieInit(struct trieArray  *trieArr)
{
    int size = DEFAULT_TABLESIZE;
    trieArr->maxSize = size;
    trieArr->symbols = calloc(1, sizeof(char)* size);
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


enum err_t trieCurrentIncrement(struct trieArray *trieArr)
{
    trieArr->current++;//increment total of letters 
    if (trieArr->current >= trieArr->maxSize)//resize
    {
        trieResize(trieArr, trieArr->maxSize * 2);
    }
}

/**
Inserts a value to the trie structure.

@param tree
@param str
@return err_success (1) on successfully inserting, otherwise
err_fail (0) is returned.
*/
enum err_t trieInsert(struct trieArray  *trieArr, const char *str)
{
    int i = 0;
    int position = charToPosition(str[i]);


    /**check swicth table**/
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

    /** use symbol table and next to fill our data **/
    while (i < strlen(str))
    {
        if (trieArr->symbols[position] == ' ')//new symbol
        {
            trieArr->symbols[position] = str[i];
            i++;//increment string letter;
            trieCurrentIncrement(trieArr);//increment total of letters 
            
            position = trieArr->current;
             
            if (i >= strlen(str))//end of word
            {
                while (trieArr->symbols[position] != ' ')//search for a spot to put termination *
                {
                    position = trieArr->next[position];//insert termination
                }
                trieArr->symbols[position] = '*';
                trieCurrentIncrement(trieArr);
            }
        }
        else//symbol in place find our new position
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
int trieLookup(struct trieArray  *trieArr, const char *str)
{
    int length = strlen(str);
    
    //look up switch
    int position = trieArr->switchValue[charToPosition(str[0])];
    if (position == -1)return 0;//no switch return false
    
    for (int i = 1; i < length; i++)
    {
        //matching symbnol continue
        if (trieArr->symbols[position] == str[i])
        {
            position++;
        }
        else//not matching position
        {
            while (trieArr->next[position] != -1 && trieArr->symbols[position] != str[i])
            {
                position = trieArr->next[position];
            }

            if (trieArr->symbols[position] != str[i])return 0;
        }
        
    }//end for

    //check if next symbol is * or next position is *    
    if (trieArr->symbols[position] == '*')return 1;

    while (trieArr->next[position] != -1 && trieArr->symbols[position] != '*')
    {
        position = trieArr->next[position];
    }
    if (trieArr->symbols[position] == '*')return 1;
    else return 0;
}


void printTrie(struct trieArray *trieArr)
{
    //print switch and position
    int i = 0;
    int const PRINT_PER_COL = 8;
    while (i < DEFAULT_TABLESIZE)
    {
        //character print
        printf("\t");
        for (int j = 0; j < PRINT_PER_COL && (j+ i) < DEFAULT_TABLESIZE; j++)
        {
            printf("%c\t ", trieArr->characters[j + i]);
        }
        printf("\n");
        //switch print
        printf("Switch: ");
        for (int j = 0; j < PRINT_PER_COL && (j + i) < DEFAULT_TABLESIZE; j++)
        {
            printf("%d\t", trieArr->switchValue[j + i]);
        }
        printf("\n\n");
        i += PRINT_PER_COL;
    }
    
    printf("\n\n");
    i = 0;
    while (i < trieArr->current)
    {
        //character numerical position
        printf("\t");
        for (int j = 0; j < PRINT_PER_COL && (j + i) < trieArr->current; j++)
        {
            if (trieArr->symbols[i + j] != ' ')
            printf("%d\t", i + j);
        }
        
        printf("\n");
        printf("symbol: ");
        //symbol print        
        for (int j = 0; j < PRINT_PER_COL && (j + i) < trieArr->current; j++)
        {
            printf("%c\t", trieArr->symbols[i+j]);
        }
        
        printf("\n");
        printf("next:\t");
        for (int j = 0; j < PRINT_PER_COL && (j + i) < trieArr->current; j++)
        {
            if (trieArr->next[i + j] != -1)
            {
                printf("%d\t", trieArr->next[i + j]);
            }
            else
            {
                printf(" \t");
            }
        }
        
        i += PRINT_PER_COL;
        printf("\n\n");
    }
}
