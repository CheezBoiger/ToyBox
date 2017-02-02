/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <stdio.h>
#include <stdlib.h>

#include <debugger/debug.h>
#include <token/scanner.h>
#include <lex/lexical.h>
#include <symbol/trieArray.h>

int main(int c, char *args[])
{
  enum toylang token = yylex();
  struct trieArray *myTrie = malloc(sizeof(struct trieArray));
  trieInit(myTrie);
  
  while (token)
  {
    const char * str = get_lang_table_pair(token)->str;
    //get rid of _
    str++;
    /**
       TODO(): Use yytext to read integers, doubles, 
       or string literals for the symbol table variable data.
     */
    debug("%s ", str);
      
    if (!trieLookup(myTrie, str)) //not in lookup
    {
      trieInsert(myTrie, str);
      //debug("trieInsert result: %d\n", res);
    }
    token = yylex();
  }
  
  printTrie(myTrie);
  debug("\n");
  
  return 0;
}
