/**
   Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_SCANNER_H
#define __TOYBOX_SCANNER_H


#include <token/token.h>
#include <debugger/debug.h>


/**
   enum-string pair for the language.
 */
struct ToyLangPair {
  enum ToyboxLang lang_token;
  const char      *str;
};


#define LANG_KEY(lang, str) { lang, str }

/**
   Language table, holding information of Language.
 */
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
  LANG_KEY(ToyLangInt,        "_int"),
  LANG_KEY(ToyLangInterface,  "_interface"),
  LANG_KEY(ToyLangNewArray,   "_newarray"),
  LANG_KEY(ToyLangPrintln,    "_println"),
  LANG_KEY(ToyLangReadln,     "_readln"),
  LANG_KEY(ToyLangReturn,     "_return"),
  LANG_KEY(ToyLangString,     "_string"),
  LANG_KEY(ToyLangTrue,       "_true"),
  LANG_KEY(ToyLangVoid,       "_void"),
  LANG_KEY(ToyLangWhile,      "_while")
};


struct ToyLangPair *get_lang_table_pair(enum ToyboxLang token) {
  if ((int)token > (int)ToyLangWhile || (int)token < (int)ToyLangBoolean) {
    debug("Improper enum => %d which is out of the bounds of ToyboxLang\n", (int)token);
    return (void *)0;
  }
  return &lang_table[(unsigned int)token];
}
#endif // __TOYBOX_SCANNER_H
