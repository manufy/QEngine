/** \file string.l
    \author Manuel Fernández Yáñez
    \date Octubre 2003
    \brief Definición del léxico para el lenguaje de script generado.
    
	Contiene definiciones que se pasan a flex. Se genera un fichero de salida, lex.cpp, que posteriormente se 
	integra con el parser. 	    
**/
%{

	// Includes

#include <string.h> 		 	// strcpy, strncpy
#include <io.h>       			// isatty
#ifdef MSVC
#define  isatty _isatty 		//  isatty se llama _isatty en vc++
#endif

	// Definiciones Forward de algún include

class TreeNode;
class SymDesc;

#define  _LEX_CPP_  			// Asegurarse de que se crean las variables
#include "lex.h"
#include "lexsymb.h"

extern "C" int yywrap (); 		// La función yywrap es declarada por el llamador

	// Referencias Forward

void Identifier ();
void StringConstant ();
void EatComment ();

%}

	
/*	Definiciones del analizador Léxico

	Dígitos, Letras, Espacios, Tabulaciones, Identificadores
	Son expresiones regulares standard
*/


LETTER   [a-zA-Z_]
DIGIT    [0-9]
IDENT    {LETTER}({LETTER}|{DIGIT})*
STR      \"[^\"]*\"
WSPACE   [ \t]+
	
/*	Reglas del analizador Léxico */

%%

"if"     {return IF;}
"else"   {return ELSE;}
"print"  {return PRINT;}
"input"  {return INPUT;}
"="      {return ASSIGN;}
"=="     {return EQUAL;}
"+"      {return CONCAT;}
";"      {return END_STMT;}
"("      {return OPEN_PAR;}
")"      {return CLOSE_PAR;}
"{"      {return BEGIN_CS;}
"}"      {return END_CS;}
{IDENT}  {Identifier ();             /* identifier: copy name */
          return ID;}
{STR}    {StringConstant ();         /* string constant: copy contents */
          return STRING;}
"//"     {EatComment();}             /* comment:    skip */
\n       {lineno++;}                 /* newline:    count lines */
{WSPACE} {}                          /* whitespace: (do nothing) */
.        {return ERROR_TOKEN;}       /* other char: error, illegal token */

%%

// Código adicional del analizador léxico 
 
// Saltar comentarios (hasta final de línea)
 
void EatComment()  {
	char c;

   while ((c = yyinput()) != '\n' && c != 0);
	lineno++;
}

// Pasar el ID del nombre

void Identifier ()  {
   yylval.str = new char[strlen(yytext)+1];
   strcpy (yylval.str, yytext);
}

// Pasar la constante de cadena

void StringConstant()  {
   int l = strlen(yytext)-2;
   yylval.str = new char[l+1];
   strncpy (yylval.str, &yytext[1], l); yylval.str[l] = 0;
}
