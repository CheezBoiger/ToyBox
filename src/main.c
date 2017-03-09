/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <stdio.h>
#include <stdlib.h>

#include <lex/lexical.h>


extern int yyparse();
extern 
int main(int c, char *args[])
{
  yyparse();
  return 0;
}
