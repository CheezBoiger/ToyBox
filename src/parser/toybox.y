%{
void yyerror (char *s);
#include <stdio.h>  
#include <stdlib.h>


%}

/* yacc definitions */
%start program

%token _boolean
%token _break
%token _class
%token _double
%token _else
%token _extends
%token _false
%token _for
%token _if
%token _implements
%token _int
%token _interface
%token _newarray
%token _println
%token _readln
%token _return
%token _string
%token _true
%token _void
%token _while
%token _plus
%token _minus
%token _multiplication
%token _division
%token _mod
%token _less
%token _lessequal
%token _greater
%token _greatereequal
%token _equal
%token _notequal
%token _and
%token _or
%token _not
%token _assignop
%token _semicolon
%token _comma
%token _period
%token _leftparen
%token _rightparen
%token _leftbracket
%token _rightbracket
%token _leftbrace
%token _rightbrace
%token _intconstant
%token _doubleconstant
%token _stringconstant
%token _booleanconstant
%token _id

//new
%token _epsilon



/* CFG here */
%%

/*descriptions of expected inputs       correspoinding actions (in C)*/
program : Decl _plus        ';'         {printf("reduce ");}
        ;

Decl    : VariableDecl      ';'         {printf("reduce ");}
        | FunctionDecl      ';'         {printf("reduce ");}         
        | ClassDecl         ';'         {printf("reduce ");}
        | InterfaceDecl     ';'         {printf("reduce ");}
        ;

VariableDecl:   Variable  ';'

Variable    :   Type _id  ';'
Type        :   _int      ';'
            |   _double   ';'
            |   _boolean  ';'  
            |   _string   ';'  
            |   Type _leftbracket _rightbracket ';'
            |   _id       ';'
            ;

FunctionDecl:   Type _id _leftparen Formals _rightparen StmtBlock ';'
            |   _void _id _leftparen Formals _rightparen StmtBlock';'
            ;

Formals     :   Variable _plus ';'
            |   _epsilon       ';'
            ;

ClassDecl: _class _id _less _extends _id _greater _less _implements _id _plus _comma _greater _leftbrace Field _multiplication _rightbrace ';'
         ;

Field   : VariableDecl ';'
        | FunctionDecl ';'
        ;

InterfaceDecl   :   _interface _id _leftbrace Prototype _multiplication _rightbrace ';'
                ;
Prototype   : Type _id _leftparen Formals _rightparen _semicolon ';'
            | _void _id _leftparen Formals _rightparen _semicolon ';'
            ;

StmtBlock   : _leftbrace VariableDecl _multiplication Stmt _multiplication _rightbrace ';'
            ;

Stmt :  _less Expr _greater _semicolon ';'
     |  IfStmt  ';'
     |  WhileStmt ';'
     |  ForStmt ';'
     |  BreakStmt ';'
     |  ReturnStmt ';'
     |  PrintStmt ';'
     |  StmtBlock   ';'
     ;

IfStmt :    _if _less Expr _greater Stmt _less _else Stmt _greater ';'
       ;

WhileStmt : _while _leftparen Expr _rightparen Stmt ';'
          ;

ForStmt : _for _leftparen _less Expr _greater _semicolon Expr _semicolon _less Expr _greater _rightparen Stmt ';'
        ;

BreakStmt   : _break _semicolon ';'
            ;

ReturnStmt :    _return _less Expr _greater _semicolon ';'
           ;

PrintStmt  : _println _leftparen Expr _plus _comma _rightparen _semicolon ';'
           ;

Expr    : Lvalue _assignop Expr ';'
        | Constant ';'
        | Lvalue ';'
        | Call ';'
        | _leftparen Expr _rightparen ';'
        | Expr _plus Expr ';'
        | Expr _minus Expr ';'
        | Expr _multiplication Expr ';'
        | Expr _division Expr ";"
        | Expr _mod Expr ';'
        | _minus Expr ';'
        | Expr _less Expr ';'
        | Expr _lessequal Expr ';'
        | Expr _greater Expr ';'
        | Expr _greatereequal Expr ';'
        | Expr _equal Expr ';'
        | Expr _notequal Expr ';'
        | Expr _and Expr ';'
        | Expr _or Expr ';'
        | Expr ';'
        | _not Expr ';'
        | _readln _leftparen _rightparen ';'
        | _newarray _leftparen _intconstant _comma Type _rightparen ';'
        ;

Lvalue  : _id ';'
        | Lvalue _leftbracket Expr _rightbracket ';'
        | Lvalue _period _id ';'
        ;

Call    : _id _leftparen Actuals _rightparen ';'
        | _id _period _id _leftparen Actuals _rightparen ';'
        ;

Actuals : Expr _plus _comma ';'
        | _epsilon ';'
        ;

Constant : _intconstant ';'
         | _doubleconstant ';'
         | _stringconstant ';'
         | _booleanconstant ';'
         ;
%%




//some thing                printf("reduce 28");
//y.tab.c add print shift statement
//will get overwritten use make file 
//sed "s/\/\* Shift the lookahead token. \*\//\/\/
// sed command can add code at those locations

//bison compiler option -v will show conflicts




void yyerror (char *s){fprintf (stderr, "%s\n", s);}
