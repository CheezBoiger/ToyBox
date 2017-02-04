/*
  Copyright (c) Mario Garcia, Under the GPL v2 License.
 */
#ifndef __TOYBOX_TOKEN_H
#define __TOYBOX_TOKEN_H

// If we are on Windows, we must disable unistd.h include
// it is POSIX defined.
#if _WIN32
 #define YY_NO_UNISTD_H
#endif 
/**
   Toy Language lexemes. These are used to return the token to 
   the parser.
 */
enum toylang {
  ToyLangBoolean = 1,
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
  ToyLangWhile,
  ToyLangPlus,
  ToyLangMinus,
  ToyLangMultiplication,
  ToyLangDivision,
  ToyLangMod,
  ToyLangLess,
  ToyLangLessEqual,
  ToyLangGreater,
  ToyLangGreaterEqual,
  ToyLangEqual,
  ToyLangNotEqual,
  ToyLangAnd,
  ToyLangOr,
  ToyLangNot,
  ToyLangAssignOp,
  ToyLangSemicolon,
  ToyLangComma,
  ToyLangPeriod,
  ToyLangLeftParen,
  ToyLangRightParen,
  ToyLangLeftBracket,
  ToyLangRightBracket,
  ToyLangLeftBrace,
  ToyLangRightBrace,
  ToyLangIntConstant,
  ToyLangDoubleConstant,
  ToyLangStringConstant,
  ToyLangBooleanConstant,
  ToyLangId
};


#endif // __TOYBOX_TOKEN_H
