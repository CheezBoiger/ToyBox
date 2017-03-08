//
// Copyright (c) Mario Garcia Micheal Wallace, Under the GNu Public v2 Licnense.
//
#include <token/scanner.h>
#include <parser/y.tab.h>


#define LANG_KEY(lang, str) { lang, str }
#define YACC_STARTING_INDEX 258

/**
   Language table, holding information of Language.
 */
static struct toylang_pair lang_table[] = {
  LANG_KEY(_boolean,         "_boolean"),
  LANG_KEY(_break,           "_break"),
  LANG_KEY(_class,           "_class"),
  LANG_KEY(_double,          "_double"),
  LANG_KEY(_else,            "_else"),
  LANG_KEY(_extends,         "_extends"),
  LANG_KEY(_false,           "_false"),
  LANG_KEY(_for,             "_for"),
  LANG_KEY(_if,              "_if"),
  LANG_KEY(_implements,      "_implements"),
  LANG_KEY(_int,             "_int"),
  LANG_KEY(_interface,       "_interface"),
  LANG_KEY(_newarray,        "_newarray"),
  LANG_KEY(_println,         "_println"),
  LANG_KEY(_readln,          "_readln"),
  LANG_KEY(_return,          "_return"),
  LANG_KEY(_string,          "_string"),
  LANG_KEY(_true,            "_true"),
  LANG_KEY(_void,            "_void"),
  LANG_KEY(_while,           "_while"),
  LANG_KEY(_plus,            "_plus"),
  LANG_KEY(_minus,           "_minus"),
  LANG_KEY(_multiplication,  "_multiplication"),
  LANG_KEY(_division,        "_division"),
  LANG_KEY(_mod,             "_mod"),
  LANG_KEY(_less,            "_less"),
  LANG_KEY(_lessequal,       "_lessequal"),
  LANG_KEY(_greater,         "_greater"),
  LANG_KEY(_greaterequal,    "_greatereequal"),
  LANG_KEY(_equal,           "_equal"),
  LANG_KEY(_notequal,        "_notequal"),
  LANG_KEY(_and,             "_and"),
  LANG_KEY(_or,              "_or"),
  LANG_KEY(_not,             "_not"),
  LANG_KEY(_assignop,        "_assignop"),
  LANG_KEY(_semicolon,       "_semicolon"),
  LANG_KEY(_comma,           "_comma"),
  LANG_KEY(_period,          "_period"),
  LANG_KEY(_leftparen,       "_leftparen"),
  LANG_KEY(_rightparen,      "_rightparen"),
  LANG_KEY(_leftbracket,     "_leftbracket"),
  LANG_KEY(_rightbracket,    "_rightbracket"),
  LANG_KEY(_leftbrace,       "_leftbrace"),
  LANG_KEY(_rightbrace,      "_rightbrace"),
  LANG_KEY(_intconstant,     "_intconstant"),
  LANG_KEY(_doubleconstant,  "_doubleconstant"),
  LANG_KEY(_stringconstant,  "_stringconstant"),
  LANG_KEY(_booleanconstant, "_booleanconstant"),
  LANG_KEY(_id,              "_id")
};



struct toylang_pair *get_lang_table_pair(enum yytokentype token)
{
  if (token > _greaterequal || token < _boolean)
  {
    debug("Improper enum => %d which is out of the bounds of ToyboxLang\n", token);
    return (void *)0;
  }
  return &lang_table[token-YACC_STARTING_INDEX];
}
