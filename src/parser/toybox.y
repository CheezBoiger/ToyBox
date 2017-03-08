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
Decl    : VariableDecl      ';'         {printf("reduce ");}
        | FunctionDecl      ';'         {printf("reduce ");}         
        | ClassDecl         ';'         {printf("reduce ");}
        | interfaceDecl     ';'         {printf("reduce ");}
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
            |   _void _id _leftparen Formals _rightParen StmtBlock';'
            ;

Formals     :   Variable _plus ';'
            |   _epsilon       ';'
            ;

ClassDecl: _class _id _less _extends _id _greater _less _implements _id _plus _comma _greater _leftbrace Field _multiplication _rightbrace ';'
         ;

Field   : VariableDecl ';'
        | FunctionDecl ';'
        ;


/*


InterfaceDecl ::= interface id { Prototype* }
Prototype ::= Type id ( Formals ) ; | void id ( Formals ) ;
StmtBlock ::= { VariableDecl* Stmt* }
Stmt ::= <Expr> ; | IfStmt | WhileStmt | ForStmt | BreakStmt | ReturnStmt | PrintStmt | StmtBlock
IfStmt ::= if ( Expr ) Stmt <else Stmt>
WhileStmt ::= while ( Expr ) Stmt
ForStmt ::= for ( <Expr> ; Expr ; <Expr> ) Stmt
BreakStmt ::= break ;
ReturnStmt ::= return <Expr> ;
PrintStmt ::= println ( Expr+, ) ;
Expr ::= Lvalue = Expr | Constant | Lvalue | Call | ( Expr ) |
Expr + Expr | Expr – Expr | Expr * Expr | Expr / Expr | Expr % Expr | - Expr |
Expr < Expr | Expr <= Expr | Expr > Expr | Expr >= Expr |
Expr == Expr | Expr != Expr | Expr && Expr | Expr || Expr | ! Expr
readln () | newarray ( intconstant , Type )
Lvalue ::= id | Lvalue [ Expr ] | Lvalue . id
Call ::= id ( Actuals ) | id . id ( Actuals )
Actuals ::= Expr+, | 
Constant ::= intconstant | doubleconstant | stringconstant | booleanconstant
*/
%%




//some thing                printf("reduce 28");
//y.tab.c add print shift statement
//will get overwritten use make file 
//sed "s/\/\* Shift the lookahead token. \*\//\/\/
// sed command can add code at those locations

//bison compiler option -v will show conflicts




void yyerror (char *s){fprintf (stderr, "%s\n", s);}
