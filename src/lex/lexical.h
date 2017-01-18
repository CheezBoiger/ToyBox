/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_LEXICAL_H
#define __TOYBOX_LEXICAL_H

#include <token/token.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

#endif // __TOYBOX_LEXICAL_H
