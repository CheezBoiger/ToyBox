/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <stdio.h>
#include <stdlib.h>

#include <debugger/debug.h>
#include <token/scanner.h>
#include <lex/lexical.h>
#include <symbol/trieArray.h>
#include <parser/parser.h>
#include <parser/slr.h>

extern int yyparse();

int main(int c, char *args[])
{
  
  enum yytokentype token = yylex();
  struct trieArray myTrie;
  trieInit(&myTrie);
  // Initialize the parse engine with this algorithm.
  toy_parser_init(slr_parse_algorithm);
  
  while (token)
  {
    yyparse();
    const char * str = get_lang_table_pair(token)->str;
    //get rid of _
    str++;
    /**
       TODO(): Use yytext to read integers, doubles, 
       or string literals for the symbol table variable data.
     */
    debug("%s ", str);
      
    if (!trieLookup(&myTrie, str)) //not in lookup
    {
      trieInsert(&myTrie, str);
      //debug("trieInsert result: %d\n", res);
    }
    token = yylex();
  }
  debug("\n");
  
  printTrie(&myTrie);
  debug("\n");
  
  return 0;
}
