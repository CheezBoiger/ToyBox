/*
  Copyright (c) Mario Garcia, Under the GPL v2 License.
 */
#ifndef __TOYBOX_SCANNER_H
#define __TOYBOX_SCANNER_H

#include <debugger/debug.h>


/**
   Toy Language lexemes. These are used to return the token to 
   the parser.
 */
enum ToyboxLang {
  ToyLangBoolean = 0,
  ToyLangBreak,
  ToyLangClass,
  ToyLangDouble,
  ToyLangElse,
  ToyLangExtends,
  ToyLangFalse,
  ToyLangFor,
  ToyLangIf,
  ToyLangImplements,
  ToyLangInt,
  ToyLangInterface,
  ToyLangNewArray,
  ToyLangPrintln,
  ToyLangReadin,
  ToyLangReturn,
  ToyLangString,
  ToyLangTrue,
  ToyLangVoid,
  ToyLangWhile
};


/**
   enum-string pair for the language.
 */
struct ToyLangPair {
  enum ToyboxLang lang_token;
  const char      *str;
};


#define LANG_KEY(lang, str) { lang, str }

struct ToyLangPair lang_table[] = {
  LANG_KEY(ToyLangBoolean,    "_boolean"),
  LANG_KEY(ToyLangBreak,      "_break"),
  LANG_KEY(ToyLangClass,      "_class"),
  LANG_KEY(ToyLangDouble,     "_double"),
  LANG_KEY(ToyLangElse,       "_else"),
  LANG_KEY(ToyLangExtends,    "_extends"),
  LANG_KEY(ToyLangFalse,      "_false"),
  LANG_KEY(ToyLangFor,        "_for"),
  LANG_KEY(ToyLangIf,         "_if"),
  LANG_KEY(ToyLangImplements, "_implements"),
};


struct ToyLangPair *get_lang_table_pair(enum ToyboxLang token) {
  if ((int)token > (int)ToyLangWhile || (int)token < (int)ToyLangBoolean) {
    debug("Improper enum => %d which is out of the bounds of ToyboxLang\n", (int)token);
    return (void *)0;
  }
  return &lang_table[(unsigned int)token];
}

#endif // __TOYBOX_SCANNER_H
