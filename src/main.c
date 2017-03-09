/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <stdio.h>
#include <stdlib.h>

#include <lex/lexical.h>
#include <parser/parser.h>
#include <parser/slr.h>


//extern int yyparse();

int main(int c, char *args[])
{
  toy_parser_init(slr_parse_algorithm);
  // No input needed, yacc and lex handle most of it.
  toy_parse(NULL, 0);
  return 0;
}
