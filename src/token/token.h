/*
  Copyright (c) Mario Garcia, Under the GPL v2 License.
 */
#ifndef __TOYBOX_TOKEN_H
#define __TOYBOX_TOKEN_H


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
  ToyLangReadln,
  ToyLangReturn,
  ToyLangString,
  ToyLangTrue,
  ToyLangVoid,
  ToyLangWhile
};


#endif // __TOYBOX_TOKEN_H
