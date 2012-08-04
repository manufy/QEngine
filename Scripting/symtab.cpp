#include <stdio.h>
#include <string.h>
#include "symtab.h"

SymDesc::SymDesc (char *_name, SymType _type, char *_cont, int _line)    {
   name = _name; type = _type;
   cont = _cont; line = _line;
   next = NULL;
}

SymDesc::~SymDesc ()  {
   if (this == NULL)   return;
   if (name != NULL)   delete [] name;
   if (cont != NULL)   delete [] cont;
}

void SymDesc::Show ()   {
   if (type == STR_CONST)
      printf ("| %-20s | %4d | (= \"%s\")\n", name, line, cont);
   else
      printf ("| %-20s | %4d |\n", name, line);
}

SymTab::SymTab()   {
   start = NULL;
}

SymTab::~SymTab()   {
   delete start;
}

bool SymTab::Add (SymDesc *symb)  {
   if (Find (symb->name) != NULL)
      return false;
   if (start == NULL)
      start = symb;
   else  {
      SymDesc *search = start;
      while (search->next != NULL)
         search = search->next;
      search->next = symb;
   }
   return true;
}

SymDesc *SymTab::Find (char *name)   {
   SymDesc *search = start;
   while (search != NULL && strcmp (search->name, name) != 0)
      search = search->next;
   return search;
}

void SymTab::Show ()  {
   SymDesc *search = start;
   puts ("+----------------------+------+");
   puts ("| Name                 | Line |");
   puts ("+----------------------+------+");
   while (search != NULL)  {
      search->Show ();
      search = search->next;
   }
   puts ("+----------------------+------+");
}