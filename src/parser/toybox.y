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

/*descriptions of expected inputs       correspoinding actions (in C)*/

 /*
   Progrma ::= Decl+
  */
Program : Decl        {printf("reduce ");}
  | Program Decl      {printf("reduce ");}
  ;

/*
  Decl ::= VariableDecl 
        | FunctionDecl
	| ClassDecl
	| InterfaceDecl
 */
Decl: VariableDecl         {printf("reduce ");}
  | FunctionDecl           {printf("reduce ");}         
  | ClassDecl              {printf("reduce ");}
  | InterfaceDecl          {printf("reduce ");} 
  ;

/*
  Variable ::= Variable ;
 */
VariableDecl:   Variable _semicolon

/*
  Variable ::= Type id
 */
Variable:   Type _id 


/*
  Type ::= int
        | double
	| boolean 
	| string
	| Type []
	| id
 */
Type:   _int   
  |   _double   
  |   _boolean 
  |   _string  
  |   Type _leftbracket _rightbracket
  |   _id      
  ;

/* FunctionDecl ::= Type id (Formals) StmtBlock 
                 | void id (Formals) StmtBlock 
*/
FunctionDecl:   Type _id _leftparen Formals _rightparen StmtBlock 
  |   _void _id _leftparen Formals _rightparen StmtBlock
  ;

/* Formals ::= Variable+, | epsilon(nothing) */
Formals:   Variable _plus ';'
  |  ""
  ;

/* ClassDecl ::= class id <extends id> <implements id+,> { Field* } */
ClassDecl: _class _id _leftbrace Field _rightbrace 
  | _class _id _extends _id _leftbrace Field _rightbrace 
  | _class _id _extends _id _implements ClassIds _leftbrace Field _rightbrace 
  ;

ClassIds: _id
  | ',' ClassIds
  ;


/* 
   Field ::= VariableDecl ;
          | FunctionDecl ;
*/
Field: VariableDecl _semicolon
  | FunctionDecl _semicolon
  ;

/*
  InterfaceDecl ::= interface id { Protype* }
 */
InterfaceDecl:   _interface _id _leftbrace Prototype _rightbrace
  ;

/*
  Prototype ::= Type id (Formals); 
             | void id (Formals);
*/
Prototype: Type _id _leftparen Formals _rightparen _semicolon
  | _void _id _leftparen Formals _rightparen _semicolon
  ;

/*
  StmtBlock ::= { VariableDecl* Stmt* }
 */
StmtBlock: _leftbrace VariableDecl Stmt _rightbrace
  ;


/*
  Stmt ::= <Expr> ;
        | IfStmt
        | WhileStmt
	| ForStmt
	| BreakStmt
	| ReturnStmt  
	| PrintStmt
	| StmtBlock
 */
Stmt:  Expr _semicolon
  |  IfStmt 
  |  WhileStmt
  |  ForStmt 
  |  BreakStmt
  |  ReturnStmt
  |  PrintStmt 
  |  StmtBlock 
  ;

/* 
   if (Expr) Stmt <else Stmt> 
*/
IfStmt: _if Expr Stmt _else Stmt
  | _if Expr Stmt
  ;


/*
  WhileStmt ::= while (Expr) Stmt
 */
WhileStmt: _while _leftparen Expr _rightparen Stmt 
  ;


/*
  ForSmt ::= for (<Expr> ; Expr; <Expr>) Stmt
 */
ForStmt: _for _leftparen ForExpr _semicolon Expr _semicolon ForExpr _rightparen Stmt
  ;


ForExpr: Expr
  | /*NULL*/
  ;


/*
  BreakStmt ::= break ;
 */
BreakStmt: _break _semicolon 
  ;


/*
  ReturnStmt ::= return <Expr>;
 */
ReturnStmt : _return Expr _semicolon
  | _return _semicolon
  ;

/*
  PrintStmt ::= println(Expr+,);
 */
PrintStmt: _println _leftparen PrintEnc _rightparen _semicolon 
  ;


PrintEnc: Expr
  | PrintEnc _comma Expr
  ;


/*
  Expr ::= Lvalue = Expr 
        | Constant
	| Lvalue
	| Call
	| ( Expr )
	| Expr + Expr 
	| Expr - Expr
	| Expr * Expr
	| Expr / Expr
	| Expr % Expr
	| -Expr
	| Expr < Expr
	| you get the point...
 */
Expr: Lvalue _assignop Expr 
  | Constant 
  | Lvalue 
  | Call 
  | _leftparen Expr _rightparen 
  | Expr _plus Expr 
  | Expr _minus Expr 
  | Expr _multiplication Expr  
  | Expr _division Expr  
  | Expr _mod Expr 
  | _minus Expr 
  | Expr _less Expr 
  | Expr _lessequal Expr 
  | Expr _greater Expr 
  | Expr _greatereequal Expr 
  | Expr _equal Expr 
  | Expr _notequal Expr 
  | Expr _and Expr 
  | Expr _or Expr 
  | Expr 
  | _not Expr 
  | _readln _leftparen _rightparen 
  | _newarray _leftparen _intconstant _comma Type _rightparen 
  ;

/*
  Lvalue ::= id 
          | Lvalue [ Expr ]
	  | Lvalue . id
 */
Lvalue: _id 
  | Lvalue _leftbracket Expr _rightbracket 
  | Lvalue _period _id 
  ;

/*
  Call ::= id (Actuals) 
        | id . id (Actuals)
 */
Call: _id _leftparen Actuals _rightparen 
  | _id _period _id _leftparen Actuals _rightparen
  ;

/*
  Actuals ::= Expr+,
           | epsilon
 */
Actuals : Expr
        | Actuals _comma Expr
        |  
        ;

/*
  Constant ::= intconstant
            | doubleconstant
	    | stringconstant
	    | booleanconstant
 */
Constant : _intconstant 
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


