/*
Copyright (c) Mario Garcia, Under the GNU Public v2 License.
*/

%{
#include "../token/token.h"
%}


%%


"boolean"      return (int)ToyLangBoolean;
"break"        return (int)ToyLangBreak;
"class"        return (int)ToyLangClass;
"double"       return (int)ToyLangDouble;
"else"         return (int)ToyLangElse;
"false"        return (int)ToyLangFalse;
"for"          return (int)ToyLangFor;
"if"           return (int)ToyLangIf;
"implements"   return (int)ToyLangImplements;
"int"          return (int)ToyLangInt;
"interface"    return (int)ToyLangInterface;
"newarray"     return (int)ToyLangNewArray;
"println"      return (int)ToyLangPrintln;
"readln"       return (int)ToyLangReadln;
"return"       return (int)ToyLangReturn;
"string"       return (int)ToyLangString;
"true"         return (int)ToyLangTrue;
"void"         return (int)ToyLangVoid;
"while"        return (int)ToyLangWhile;

"+"            return (int)ToyLangPlus;
"-"            return (int)ToyLangMinus;
"*"            return (int)ToyLangMultiplication;
"/"            return (int)ToyLangDivision;
"%"            return (int)ToyLangMod;
"<"            return (int)ToyLangLess;
"<="           return (int)ToyLangLessEqual;
">"            return (int)ToyLangGreater;
">="           return (int)ToyLangGreaterEqual;
"=="           return (int)ToyLangEqual;
"!="           return (int)ToyLangNotEqual;
"&&"           return (int)ToyLangAnd;
"||"           return (int)ToyLangOr;
"!"            return (int)ToyLangNot;
"="            return (int)ToyLangAssignOp;
";"            return (int)ToyLangSemicolon;
","            return (int)ToyLangComma;
"."            return (int)ToyLangPeriod;
"("            return (int)ToyLangLeftParen;
")"            return (int)ToyLangRightParen;
"["            return (int)ToyLangLeftBracket;
"]"            return (int)ToyLangRightBracket;
"{"            return (int)ToyLangLeftBrace;
"}"            return (int)ToyLangRightBrace;


\".*\"                                           return (int)ToyLangStringConstant;
0[x|X][a-fA-F0-9]+|[0-9]+                        return (int)ToyLangIntConstant;
[0-9]*"."[0-9]*|[0-9]*"."[0-9]*[e|E][-|+]*[0-9]+ return (int)ToyLangDoubleConstant;
_*[a-zA-Z]+[a-zA-Z0-9]*                          return (int)ToyLangId;


%%


int yywrap()
{
  return 1;
}
