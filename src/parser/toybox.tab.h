/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TOYBOX_TAB_H_INCLUDED
# define YY_YY_TOYBOX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _boolean = 258,
    _break = 259,
    _class = 260,
    _double = 261,
    _else = 262,
    _extends = 263,
    _false = 264,
    _for = 265,
    _if = 266,
    _implements = 267,
    _int = 268,
    _interface = 269,
    _newarray = 270,
    _println = 271,
    _readln = 272,
    _return = 273,
    _string = 274,
    _true = 275,
    _void = 276,
    _while = 277,
    _plus = 278,
    _minus = 279,
    _multiplication = 280,
    _division = 281,
    _mod = 282,
    _less = 283,
    _lessequal = 284,
    _greater = 285,
    _greatereequal = 286,
    _equal = 287,
    _notequal = 288,
    _and = 289,
    _or = 290,
    _not = 291,
    _assignop = 292,
    _semicolon = 293,
    _comma = 294,
    _period = 295,
    _leftparen = 296,
    _rightparen = 297,
    _leftbracket = 298,
    _rightbracket = 299,
    _leftbrace = 300,
    _rightbrace = 301,
    _intconstant = 302,
    _doubleconstant = 303,
    _stringconstant = 304,
    _booleanconstant = 305,
    _id = 306,
    _epsilon = 307,
    _greaterequal = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOYBOX_TAB_H_INCLUDED  */
