/*
Copyright (c) Mario Garcia, Under the GNU Public v2 License.
*/

%{
#include <stdlib.h>
#include "../token/token.h"
#include "../parser/y.tab.h"
%}


%%


"boolean"      return _boolean;
"break"        return _break;
"class"        return _class;
"double"       return _double;
"else"         return _else;
"for"          return _for;
"if"           return _if;
"implements"   return _implements;
"int"          return _int;
"interface"    return _interface;
"newarray"     return _newarray;
"println"      return _println;
"readln"       return _readln;
"return"       return _return;
"string"       return _string;
"void"         return _void;
"while"        return _while;
"extends"      return _extends;

"+"            return _plus;
"-"            return _minus;
"*"            return _multiplication;
"/"            return _division;
"%"            return _mod;
"<"            return _less;
"<="           return _lessequal;
">"            return _greater;
">="           return _greaterequal;
"=="           return _equal;
"!="           return _notequal;
"&&"           return _and;
"||"           return _or;
"!"            return _not;
"="            return _assignop;
";"            return _semicolon;
","            return _comma;
"."            return _period;
"("            return _leftparen;
")"            return _rightparen;
"["            return _leftbracket;
"]"            return _rightbracket;
"{"            return _leftbrace;
"}"            return _rightbrace;


"true"|"false"                                 return _booleanconstant;
\".*\"                                           return _stringconstant;
0[x|X][a-fA-F0-9]+|[0-9]+                        return _intconstant;
[0-9][0-9]*"."[0-9]*|[0-9][0-9]*"."[0-9]*[e|E][-|+]*[0-9]+ return _doubleconstant;
_*[a-zA-Z]+[a-zA-Z0-9]*                          return _id;

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]    { };
"//".*                                 { };

" "+                                   { };

%%


int yywrap()
{
  return 1;
}
