//
// Copyright (c) Mario Garcia Micheal Wallace, Under the GNu Public v2 Licnense.
//
#include <token/scanner.h>


#define LANG_KEY(lang, str) { lang, str }

/**
   Language table, holding information of Language.
 */
static struct toylang_pair lang_table[] = {
  LANG_KEY(ToyLangBoolean,         "_boolean"),
  LANG_KEY(ToyLangBreak,           "_break"),
  LANG_KEY(ToyLangClass,           "_class"),
  LANG_KEY(ToyLangDouble,          "_double"),
  LANG_KEY(ToyLangElse,            "_else"),
  LANG_KEY(ToyLangExtends,         "_extends"),
  LANG_KEY(ToyLangFalse,           "_false"),
  LANG_KEY(ToyLangFor,             "_for"),
  LANG_KEY(ToyLangIf,              "_if"),
  LANG_KEY(ToyLangImplements,      "_implements"),
  LANG_KEY(ToyLangInt,             "_int"),
  LANG_KEY(ToyLangInterface,       "_interface"),
  LANG_KEY(ToyLangNewArray,        "_newarray"),
  LANG_KEY(ToyLangPrintln,         "_println"),
  LANG_KEY(ToyLangReadln,          "_readln"),
  LANG_KEY(ToyLangReturn,          "_return"),
  LANG_KEY(ToyLangString,          "_string"),
  LANG_KEY(ToyLangTrue,            "_true"),
  LANG_KEY(ToyLangVoid,            "_void"),
  LANG_KEY(ToyLangWhile,           "_while"),
  LANG_KEY(ToyLangPlus,            "_plus"),
  LANG_KEY(ToyLangMinus,           "_minus"),
  LANG_KEY(ToyLangMultiplication,  "_multiplication"),
  LANG_KEY(ToyLangDivision,        "_division"),
  LANG_KEY(ToyLangMod,             "_mod"),
  LANG_KEY(ToyLangLess,            "_less"),
  LANG_KEY(ToyLangLessEqual,       "_lessequal"),
  LANG_KEY(ToyLangGreater,         "_greater"),
  LANG_KEY(ToyLangGreaterEqual,    "_greatereequal"),
  LANG_KEY(ToyLangEqual,           "_equal"),
  LANG_KEY(ToyLangNotEqual,        "_notequal"),
  LANG_KEY(ToyLangAnd,             "_and"),
  LANG_KEY(ToyLangOr,              "_or"),
  LANG_KEY(ToyLangNot,             "_not"),
  LANG_KEY(ToyLangAssignOp,        "_assignop"),
  LANG_KEY(ToyLangSemicolon,       "_semicolon"),
  LANG_KEY(ToyLangComma,           "_comma"),
  LANG_KEY(ToyLangPeriod,          "_period"),
  LANG_KEY(ToyLangLeftParen,       "_leftparen"),
  LANG_KEY(ToyLangRightParen,      "_rightparen"),
  LANG_KEY(ToyLangLeftBracket,     "_leftbracket"),
  LANG_KEY(ToyLangRightBracket,    "_rightbracket"),
  LANG_KEY(ToyLangLeftBrace,       "_leftbrace"),
  LANG_KEY(ToyLangRightBrace,      "_rightbrace"),
  LANG_KEY(ToyLangIntConstant,     "_intconstant"),
  LANG_KEY(ToyLangDoubleConstant,  "_doubleconstant"),
  LANG_KEY(ToyLangStringConstant,  "_stringconstant"),
  LANG_KEY(ToyLangBooleanConstant, "_booleanconstant"),
  LANG_KEY(ToyLangId,              "_id")
};



struct toylang_pair *get_lang_table_pair(enum toylang token)
{
  if (token > ToyLangId || token < ToyLangBoolean)
  {
    debug("Improper enum => %d which is out of the bounds of ToyboxLang\n", token);
    return (void *)0;
  }
  return &lang_table[token-1];
}
