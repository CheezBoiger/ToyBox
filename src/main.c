/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <stdio.h>

#include <debugger/debug.h>
#include <token/scanner.h>
#include <lex/lexical.h>


int main(int c, char *args[])
{
  enum ToyboxLang token = (enum ToyboxLang)yylex();
  while ((int)token)
  {
    printf("%s", get_lang_table_pair(token)->str);
    token = (enum ToyboxLang)yylex();
  }
  return 0;
}
