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


%glr-parser
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

  NOTE(Wallace): VARIABLE CANNOT BE x; if you think it should
  add in a null alternative. Will cause conflicts though...
 */
Variable:
Type _id { printf("[reduce 6]\n"); }
;

/*
  Item 4
 */
Type:
  _double { printf("[reduce 7]\n"); }
| _int { printf("[reduce 8]\n"); }
| _boolean { printf("[reduce  9]\n"); }
| _string { printf("[reduce 10]\n"); }
| Type _leftbracket _rightbracket { printf("[reduce 11]\n"); }
| _id { printf("[reduce 12]\n"); }
;

/*
  Item 5
 */
ClassDecl:
_class _id ExtendClass ImplementClass _leftbrace Field _rightbrace { printf("[reduce 13]\n"); }
;

/*
  Item 6
 */
ExtendClass:
_extends _id { printf("[reduce 14]\n"); }
|
;

/*
  Item 7
 */
ImplementClass:
_implements ImplInterface { printf("[reduce 15]\n"); }
|
;

/*
  Item 8
 */
ImplInterface:
_id
| _id _comma ImplInterface { printf("[reduce 16]\n"); }
;

/*
  Item 9
 */
InterfaceDecl:
_interface _id _leftbrace Prototype _rightbrace { printf("[reduce 17]\n"); }
;

/*
  Item 10
 */
Prototype:
Type _id _leftparen Formals _rightparen _semicolon Prototype { printf("[reduce 18]\n"); }
|
;

/*
  Item 11
 */
Formals:
Variable
| Variable _comma Formals { printf("[reduce 19]\n"); }
|
;

/*
  Item 12
 */
Field:
VariableDecl { printf("[reduce 20]\n"); }
|
;

/*
  Item 13
 */
FunctionDecl:
Type _id _leftparen Formals _rightparen StmtBlock { printf("[reduce 21]\n"); }
; 

/*
  Item 14
 */
StmtBlock:
_leftbrace StmtDeclares Stmt _rightbrace { printf("[reduce 22]\n"); }
;


/*
  Item 15
 */
StmtDeclares:
VariableDecl { printf("[reduce 23]\n"); }
|
;


/*
  Item 16
 */
Stmt:
Expr _semicolon Stmt { printf("[reduce 24]\n"); }
| IfStmt
| WhileStmt
| ForStmt
| BreakStmt
| ReturnStmt
| PrintStmt
| StmtBlock
|
;


/*
  Item 17
 */
Expr: 
Lvalue _assignop Expr       { printf("[reduce 25]\n"); }
| Constant                  { printf("[reduce 26]\n"); }
| Lvalue                    { printf("[reduce 27]\n"); }
| Call                      { printf("[reduce 28]\n"); }
| Expr _plus Expr           { printf("[reduce 29]\n"); }
| Expr _minus Expr          { printf("[reduce 30]\n"); }
| Expr _multiplication Expr { printf("[reduce 31]\n"); }
| Expr _division Expr       { printf("[reduce 32]\n"); }
| Expr _mod Expr            { printf("[reduce 33]\n"); }
| _minus Expr               { printf("[reduce 34]\n"); }
| Expr _less Expr           { printf("[reduce 35]\n"); }    
| Expr _lessequal Expr      { printf("[reduce 36]\n"); }
| Expr _greater Expr        { printf("[reduce 37]\n"); }
| Expr _greaterequal Expr   { printf("[reduce 38]\n"); }
| Expr _equal Expr          { printf("[reduce 39]\n"); }
| Expr _notequal Expr       { printf("[reduce 40]\n"); }
| Expr _and Expr            { printf("[reduce 41]\n"); }
| Expr _or Expr             { printf("[reduce 42]\n"); }
| _not Expr                 { printf("[reduce 43]\n"); }
| _readln _leftparen _rightparen                            { printf("[reduce 44]\n"); }
| _newarray _leftparen _intconstant _comma Type _rightparen { printf("[reduce 45]\n"); }
;


/*
  Item 18
  TODO(Wallace): This is causing conflict with Expr -> Lvalue ! Expr is fine,
  Lvalue is left recursive, need to fix!
  
  Also add in Call too! Everything else is ok. (classes, interfaces, and variabledecls 
  are fine, hopefully they don't conflict with you).
 */
Lvalue:
_id LHelper                                 { printf("[reduce 46]\n"); }
;


LHelper:
_leftbracket Expr _rightbracket LHelper  { printf("[reduce 47]\n"); }
| _period _id LHelper                       { printf("[reduce 48]\n"); }
|
;


Call:
_id _leftparen Actuals _rightparen                  { printf("[reduce 50]\n"); }
| _id _period _id _leftparen Actuals _rightparen    { printf("[reduce 51]\n"); }
;


Actuals:
Expr    { printf("[reduce 52]\n"); }
;
/*
  Item 19
 */
Constant:
_intconstant        { printf("[reduce 53]\n"); }
| _doubleconstant   { printf("[reduce 54]\n"); }
| _stringconstant   { printf("[reduce 55]\n"); }
| _booleanconstant  { printf("[reduce 56]\n"); }
;


/*
Item 20
*/
IfStmt:
_if _leftparen Expr _rightparen Stmt
;//needs else

WhileStmt:
_while _leftparen Expr _rightparen Stmt
;

ForStmt:
_for _leftparen Expr _semicolon Expr _semicolon Expr _rightparen Stmt
;
BreakStmt:
_break _semicolon
;

ReturnStmt:
_return Expr _semicolon
| _return _semicolon
;

PrintStmt:
_println Expr
;


%%




//some thing                printf("reduce 28");
//y.tab.c add print shift statement
//will get overwritten use make file 
//sed "s/\/\* Shift the lookahead token. \*\//\/\/
// sed command can add code at those locations

//bison compiler option -v will show conflicts




void yyerror (char *s){fprintf (stderr, "%s\n", s);}


