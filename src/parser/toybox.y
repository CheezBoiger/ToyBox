%{
void yyerror (char *s);
#include <stdio.h>  
#include <stdlib.h>


 int yylex();
 
%}

/* yacc definitions */
%start Program

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


%left _leftbracket _period
%left _multiplication _division _mod
%left _plus _not _minus
%left _greater _greaterequal _less _lessequal
%left _equal _notequal
%left _and
%left _or
%left _assignop
/* CFG here */
%%

Program:
Decl
;

/*
  Simply comment out one of these Decls in order to debug the tree for which
  ever keyword is giving you trouble.
 */
Decl:
/* NULL */
| VariableDecl 
| ClassDecl 
| InterfaceDecl
| FunctionDecl 
;

/*
  Item 2
 */
VariableDecl:
Variable _semicolon
;

/*
  Item 3

  NOTE(Wallace): VARIABLE CANNOT BE x; if you think it should
  add in a null alternative. Will cause conflicts though...
 */
Variable:
Type _id 
;

/*
  Item 4
 */
Type:
  _double { printf("[reduce item 4]\n"); }
| _int { printf("[reduce item 4]\n"); }
| _boolean { printf("[reduce item 4]\n"); }
| _string { printf("[reduce item 4]\n"); }
| Type _leftbracket _rightbracket { printf("[reduce item 4]\n"); }
| _id { printf("[reduce item 4]\n"); }
;

/*
  Item 5
 */
ClassDecl:
_class _id ExtendClass ImplementClass _leftbrace Field _rightbrace Decl 
;

/*
  Item 6
 */
ExtendClass:
_extends _id { printf("[reduce]"); }
|
;

/*
  Item 7
 */
ImplementClass:
_implements ImplInterface
|
;

/*
  Item 8
 */
ImplInterface:
_id
| _id _comma ImplInterface
;

/*
  Item 9
 */
InterfaceDecl:
_interface _id _leftbrace Prototype _rightbrace Decl 
;

/*
  Item 10
 */
Prototype:
Type _id _leftparen Formals _rightparen _semicolon Prototype
|
;

/*
  Item 11
 */
Formals:
Variable
| Variable _comma Formals
|
;

/*
  Item 12
 */
Field:
VariableDecl
|
;

/*
  Item 13
 */
FunctionDecl:
Type _id _leftparen Formals _rightparen StmtBlock Decl
;

/*
  Item 14
 */
StmtBlock:
_leftparen StmtDeclares Stmt _rightparen
;


/*
  Item 15
 */
StmtDeclares:
VariableDecl
|
;


/*
  Item 16
 */
Stmt:
Expr _semicolon Stmt
|
;


/*
  Item 17
 */
Expr: 
Lvalue _assignop Expr
| Constant
| Lvalue
| Call
| Expr _plus Expr
| Expr _minus Expr
| Expr _multiplication Expr
| Expr _division Expr
| Expr _mod Expr
| _minus Expr
| Expr _less Expr
| Expr _lessequal Expr
| Expr _greater Expr
| Expr _greaterequal Expr
| Expr _equal Expr
| Expr _notequal Expr
| Expr _and Expr
| Expr _or Expr
| _not Expr
| _readln _leftparen _rightparen
| _newarray _leftparen _intconstant _comma Type _rightparen
;


/*
  Item 18
  TODO(Wallace): This is causing conflict with Expr -> Lvalue ! Expr is fine,
  Lvalue is left recursive, need to fix!
  
  Also add in Call too! Everything else is ok. (classes, interfaces, and variabledecls 
  are fine, hopefully they don't conflict with you).
 */
Lvalue:
_id
| Lvalue _leftbracket Expr _rightbracket
| Lvalue _period _id
| Lvalue _assignop Expr
;

Call:
_id _leftparen Actuals _rightparen
| _id _period _id _leftparen Actuals _rightparen
;

Actuals:
Expr
;
/*
  Item 19
 */
Constant:
_intconstant
| _doubleconstant
| _stringconstant
| _booleanconstant
;


%%




//some thing                printf("reduce 28");
//y.tab.c add print shift statement
//will get overwritten use make file 
//sed "s/\/\* Shift the lookahead token. \*\//\/\/
// sed command can add code at those locations

//bison compiler option -v will show conflicts




void yyerror (char *s){fprintf (stderr, "%s\n", s);}


