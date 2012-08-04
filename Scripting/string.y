/** \file string.y
    \author Manuel Fernández Yáñez
    \date Octubre 2003
    \brief Definición de la gramática para el lengueje de script generado.
    
	Contiene definiciones que se pasan a bison. Se genera un fichero de salida, parser.cpp, que está
	integrado con lex.cpp y forman parte del parser del lenguaje de script implementado.
**/

%{

/* ------------------------------------------------------------------
   Initial code (copied verbatim to the output file)
   ------------------------------------------------------------------ */

// Includes
#include <malloc.h>  // _alloca es usado por el parser
#include <string.h>  // strcpy

#include "lex.h"       // El analizador léxico
#include "symtab.h"    // La tabla de símbolos
#include "synttree.h"  // El árbol sintáctico

SymTab st;     // Crea la tabla de símbolos
SyntTree tree; // Crea el árbol sintáctico

// Definiciones de yacc (bison)
#define YYDEBUG 1	      // Genera código de depuración; Usado por YYERROR_VERBOSE
#define YYERROR_VERBOSE   // Dar mensaje de error detallado

// La función de manejo de errores debe ser definida por el llamador
void Error (char *format, ...);

// Referencias forward
void yyerror (char *msg);
char *MakeName ();

%}

// Declaraciones Yacc / Bison

// Estructura para el paso de valores entre el analizador léxico y el parser 

%union {
   char    *str;     // Una cadena de caracteres
   SymDesc *symbol;  // Entrada en la tabla de símbolos
   TreeNode *tnode;  // Nodo en el árbol sintáctico
}

// Definiciones de Tokens 

%token ERROR_TOKEN IF ELSE PRINT INPUT ASSIGN EQUAL
%token CONCAT END_STMT OPEN_PAR CLOSE_PAR
%token BEGIN_CS END_CS 
%token <str> ID STRING

// Reglas

%type <symbol> identifier string
%type <tnode>  program statement_list statement
%type <tnode>  if_statement optional_else_statement compound_statement
%type <tnode>  expression equal_expression assign_expression
%type <tnode>  concat_expression simple_expression

%expect 1	//conflicto shift/reduce: dangling ELSE */
           
%%


// Reglas de grámatica Yacc / Bison


program
      : statement_list              {tree = $1;}
		;

statement_list
      : statement_list statement    {$$ = new TreeNode (STMT_LIST, $1, $2);}
      | /* empty */                 {$$ = new TreeNode (EMPTY_STMT);}
      ;

statement
      : END_STMT                    {$$ = new TreeNode (EMPTY_STMT);}
      | expression END_STMT         {$$ = new TreeNode (EXPR_STMT, $1);}
      | PRINT expression END_STMT   {$$ = new TreeNode (PRINT_STMT, $2);}
      | INPUT identifier END_STMT   {$$ = new TreeNode (INPUT_STMT); $$->symbol = $2;}
      | if_statement                {$$ = $1;}
      | compound_statement          {$$ = $1;}
      | error END_STMT              {$$ = new TreeNode (ERROR_STMT);}
      ;

/* NOTE: This rule causes an unresolvable shift/reduce conflict;
   That's why %expect 1 was added (see above) */
if_statement
      : IF OPEN_PAR expression CLOSE_PAR statement optional_else_statement
        {
           if ($6 != NULL)
              $$ = new TreeNode (IFTHENELSE_STMT, $3, $5, $6);
           else
              $$ = new TreeNode (IFTHEN_STMT, $3, $5);
        }
      ;

optional_else_statement
      : ELSE statement     {$$ = $2;}
      | /* empty */        {$$ = NULL;}
      ;

compound_statement
      : BEGIN_CS statement_list END_CS   {$$ = $2;}
      ;

expression
      : equal_expression               {$$ = $1;}
      ;

equal_expression
      : expression EQUAL assign_expression   {$$ = new TreeNode (EQUAL_EXPR, $1, $3);}
      | assign_expression                    {$$ = $1;}
      ;

assign_expression
      : identifier ASSIGN assign_expression  {$$ = new TreeNode (ASSIGN_EXPR, $3); $$->symbol = $1;}
      | concat_expression                    {$$ = $1;}
      ;

concat_expression
      : concat_expression CONCAT simple_expression  {$$ = new TreeNode (CONCAT_EXPR, $1, $3);}
      | simple_expression                           {$$ = $1;}
      ;

simple_expression
      : identifier     {$$ = new TreeNode (IDENT_EXPR); $$->symbol = $1;}
      | string         {$$ = new TreeNode (STR_EXPR); $$->symbol = $1;}
      | OPEN_PAR expression CLOSE_PAR  {$$ = $2;}
      ;

identifier
      : ID
        {
           $$ = st.Find ($1);
           if ($$ == NULL)   { // doesn't exist yet; create it
              $$ = new SymDesc ($1, STR_VAR, NULL, lineno);
              st.Add ($$);
           }
        }
      ;

string
      : STRING
        {
           $$ = new SymDesc (MakeName(), STR_CONST, $1, lineno);
           st.Add ($$);
        }
      ;

%%

// Código adicional

// Genera un nombre único para una constante de cadena

char *MakeName ()  {
   char *name = new char [10], num[4];
   static n = 0;
   sprintf (num, "%d", ++n);
   strcpy (name, "strconst"); strcat (name, num);
   return name;
}
