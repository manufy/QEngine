#include <stdio.h>
#include "synttree.h"
#include "symtab.h"

// Node names        
char *name[] = {
   "statement list",
   "empty statement",
   "expression statement",
   "print statement",
   "input statement",
   "if..then statement",
   "if..then..else statement",
   "error statement",

   "equals",
   "assign",
   "concatenate",
   "identifier",
   "string constant"
};

// Numbers of children per node type
int children[] = {
   2, 0, 1, 1, 0, 2, 3, 0, 2, 1, 2, 0, 0
};

// Recursively show the contents of the syntax tree
void TreeNode::Show (int level)   {
   int i,nl;
   if (type != STMT_LIST)   {
      for (i = 0; i < level; i++)   printf ("   ");
      printf ("%s", name[type]);
      switch (type)  {
      case INPUT_STMT: case ASSIGN_EXPR: case IDENT_EXPR:
         printf (" (%s)", symbol->name); break;
      case STR_EXPR:
         printf (" (\"%s\")", symbol->cont); break;
      }
      nl = level + 1;
      printf ("\n");
   } else nl = level;
   for (i = 0; i < children[type]; i++)   child[i]->Show(nl);
}

// Check the semantics of this node
