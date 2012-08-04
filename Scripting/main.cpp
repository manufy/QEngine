#include <stdio.h>
#include <iostream.h>
#include <stdarg.h>
#include "lex.h"
#include "parse.h"
#include "symtab.h"
#include "synttree.h"

int errors = 0;

// Function used to report errors
void Error (char *format, ...)   {
   va_list args;

   errors++;
   printf ("Line %d: ", lineno);
   va_start(args, format);
   vfprintf(stdout, format, args);
   va_end(args);
   printf("\n");
}

// Show an error count
void ErrorSummary ()  {
   printf ("%d error(s) were found.\n", errors);
}

// Function called by the parser when an error occurs while parsing
// (parse error or stack overflow)
void yyerror(char *msg) {
   Error (msg);
}

// This function is called by the lexer when the end-of-file
// is reached; you can reset yyin (the input FILE*) and return 0
// if you want to process another file; otherwise just return 1.
extern "C" int yywrap(void) {
  return 1;
}

extern SymTab st;
extern SyntTree tree;

// The main program: just report all tokens found
main (int argc, char *argv[])  {
   // Set the input stream (either a file from the command line or stdin)
   yyin = NULL;
   if (argc == 2)
      yyin = fopen (argv[1], "rt");
   if (yyin == NULL)
      yyin = stdin;

   yyparse (); // call the parser
   
   ErrorSummary ();

   st.Show();
   tree->Show();
   return errors ? 1 : 0;
}

