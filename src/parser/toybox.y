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


 %nonassoc _else
 %nonassoc _ifx


%glr-parser
 /* CFG here */
%%

Program:
Decl    { printf("[reduce 0]\n"); }
;

/*
  Simply comment out one of these Decls in order to debug the tree for which
  ever keyword is giving you trouble.
 */
Decl:
/* NULL */
| VariableDecl Decl { printf("[reduce 1]\n"); }
| ClassDecl   Decl  { printf("[reduce 2]\n"); }
| InterfaceDecl Decl { printf("[reduce 3]\n"); }
| FunctionDecl Decl { printf("[reduce 4]\n"); }
;

/*
  Item 2
 */
VariableDecl:
Variable _semicolon { printf("[reduce 5]\n"); }
;

/*
  Item 3
 */
Variable:
Type _id Assign { printf("[reduce 6]\n"); }
| _id Assign
;


Assign:
_assignop Constant { printf("[reduce 7]\n"); }
|
;

/*
  Item 4
 */
Type:
  _double { printf("[reduce 8]\n"); }
| _int { printf("[reduce 9]\n"); }
| _boolean { printf("[reduce  10]\n"); }
| _string { printf("[reduce 11]\n"); }
| Type _leftbracket _rightbracket { printf("[reduce 12]\n"); }
| _id { printf("[reduce 13]\n"); }
;

/*
  Item 5
 */
ClassDecl:
_class _id ExtendClass ImplementClass _leftbrace Field _rightbrace { printf("[reduce 14]\n"); }
;

/*
  Item 6
 */
ExtendClass:
_extends _id { printf("[reduce 15]\n"); }
|
;

/*
  Item 7
 */
ImplementClass:
_implements ImplInterface { printf("[reduce 16]\n"); }
|
;

/*
  Item 8
 */
ImplInterface:
_id
| _id _comma ImplInterface { printf("[reduce 17]\n"); }
;

/*
  Item 9
 */
InterfaceDecl:
_interface _id _leftbrace Prototype _rightbrace { printf("[reduce 18]\n"); }
;

/*
  Item 10
 */
Prototype:
Type _id _leftparen Formals _rightparen _semicolon Prototype { printf("[reduce 19]\n"); }
| _void _id _leftparen Formals _rightparen _semicolon Prototype { printf("[reduce 20]\n\n"); }
|
;

/*
  Item 11
 */
Formals:
Variable                  { printf("[reduce 21]\n"); }
| Variable _comma Formals { printf("[reduce 22]\n"); }
|
;

/*
  Item 12
 */
Field:
VariableDecl Field { printf("[reduce 23]\n"); }
| FunctionDecl Field { printf("[reduce 24]\n"); }
|  
;

/*
  Item 13
 */
FunctionDecl:
Type _id _leftparen Formals _rightparen StmtBlock { printf("[reduce 25]\n"); }
| _void _id _leftparen Formals _rightparen StmtBlock { printf("[reduce 26]\n"); }
; 

/*
  Item 14
 */
StmtBlock:
_leftbrace StmtDeclares Stmt _rightbrace { printf("[reduce 27]\n"); }
;


/*
  Item 15
 */
StmtDeclares:
VariableDecl StmtDeclares { printf("[reduce 28]\n"); }
|
;


/*
  Item 16
 */
Stmt:
Expr _semicolon Stmt { printf("[reduce 29]\n"); }
| IfStmt                { printf("[reduce 30]\n"); }
| WhileStmt             { printf("[reduce 31]\n"); }
| ForStmt Stmt          { printf("[reduce 32]\n"); }
| BreakStmt Stmt        { printf("[reduce 33]\n"); }
| ReturnStmt Stmt       { printf("[reduce 34]\n"); }
| PrintStmt Stmt        { printf("[reduce 35]\n"); }
| StmtBlock Stmt        { printf("[reduce 36]\n"); }
|
;


/*
  Item 17
 */
Expr: 
Lvalue _assignop Expr       { printf("[reduce 37]\n"); }
| Constant                  { printf("[reduce 38]\n"); }
| Lvalue                    { printf("[reduce 39]\n"); }
| Call                      { printf("[reduce 40]\n"); }
| Expr _plus Expr           { printf("[reduce 41]\n"); }
| Expr _minus Expr          { printf("[reduce 42]\n"); }
| Expr _multiplication Expr { printf("[reduce 43]\n"); }
| Expr _division Expr       { printf("[reduce 44]\n"); }
| Expr _mod Expr            { printf("[reduce 45]\n"); }
| _minus Expr               { printf("[reduce 46]\n"); }
| Expr _less Expr           { printf("[reduce 47]\n"); }    
| Expr _lessequal Expr      { printf("[reduce 48]\n"); }
| Expr _greater Expr        { printf("[reduce 49]\n"); }
| Expr _greaterequal Expr   { printf("[reduce 50]\n"); }
| Expr _equal Expr          { printf("[reduce 51]\n"); }
| Expr _notequal Expr       { printf("[reduce 52]\n"); }
| Expr _and Expr            { printf("[reduce 53]\n"); }
| Expr _or Expr             { printf("[reduce 54]\n"); }
| _not Expr                 { printf("[reduce 55]\n"); }
| _leftparen Expr _rightparen                               { printf("[reduce 56\n"); }
| _readln _leftparen _rightparen                            { printf("[reduce 57]\n"); }
| _newarray _leftparen _intconstant _comma Type _rightparen { printf("[reduce 58]\n"); }
;


/*
  Item 18
 */
Lvalue:
_id LHelper                                 { printf("[reduce 59]\n"); }
;


LHelper:
_leftbracket Expr _rightbracket LHelper  { printf("[reduce 60]\n"); }
| _period _id LHelper                       { printf("[reduce 61]\n"); }
|
;


Call:
_id _leftparen Actuals _rightparen                  { printf("[reduce 62]\n"); }
| _id _period _id _leftparen Actuals _rightparen    { printf("[reduce 63]\n"); }
;


Actuals:
Expr    { printf("[reduce 64]\n"); }
;
/*
  Item 19
 */
Constant:
_intconstant        { printf("[reduce 65]\n"); }
| _doubleconstant   { printf("[reduce 66]\n"); }
| _stringconstant   { printf("[reduce 67]\n"); }
| _booleanconstant  { printf("[reduce 68]\n"); }
;

/*
Item 20
*/
IfStmt:
_if _leftparen Expr _rightparen Stmt                { printf("[reduce 69]\n"); }
| _if _leftparen Expr _rightparen Stmt _else Stmt   { printf("[reduce 70]\n"); }
;

WhileStmt:
_while _leftparen Expr _rightparen Stmt             { printf("[reduce 71]\n"); }
;

ForStmt:
_for _leftparen ForOption _semicolon Expr _semicolon ForOption _rightparen  { printf("[reduce 72]\n"); }
;


ForOption:
Expr    { printf("[reduce 73]\n"); }
|
;


BreakStmt:
_break _semicolon   { printf("[reduce 74]\n"); }
;

ReturnStmt:
_return Expr _semicolon { printf("[reduce 75]\n"); }
| _return _semicolon    { printf("[reduce 76]\n"); }
;

PrintStmt:
_println _leftparen Expr PrintOption  _rightparen _semicolon    { printf("[reduce 77]\n"); }
;


PrintOption:
_comma Expr PrintOption { printf("[reduce 78]\n"); }
|
;

%%

void yyerror (char *s){fprintf (stderr, "%s\n", s);}


