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


%%


int yywrap()
{
  return 1;
}
