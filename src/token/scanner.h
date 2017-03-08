/**
   Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_SCANNER_H
#define __TOYBOX_SCANNER_H


#include <parser/toybox.tab.h>
#include <debugger/debug.h>


/**
   enum-string pair for the language.
 */
struct toylang_pair
{
  enum yytokentype    lang_token;
  const char          *str;
};


/**
   Lookup the information of a token in the Toy language.
 */
struct toylang_pair *get_lang_table_pair(enum yytokentype token);


#endif // __TOYBOX_SCANNER_H
