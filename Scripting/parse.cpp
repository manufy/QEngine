
/*  A Bison parser, made from .\scripting\string.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ERROR_TOKEN	258
#define	IF	259
#define	ELSE	260
#define	PRINT	261
#define	INPUT	262
#define	ASSIGN	263
#define	EQUAL	264
#define	CONCAT	265
#define	END_STMT	266
#define	OPEN_PAR	267
#define	CLOSE_PAR	268
#define	BEGIN_CS	269
#define	END_CS	270
#define	ID	271
#define	STRING	272

#line 10 ".\scripting\string.y"


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


#line 44 ".\scripting\string.y"
typedef union {
   char    *str;     // Una cadena de caracteres
   SymDesc *symbol;  // Entrada en la tabla de símbolos
   TreeNode *tnode;  // Nodo en el árbol sintáctico
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		47
#define	YYFLAG		-32768
#define	YYNTBASE	18

#define YYTRANSLATE(x) ((unsigned)(x) <= 272 ? yytranslate[x] : 31)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     6,     8,    11,    15,    19,    21,    23,
    26,    33,    36,    37,    41,    43,    47,    49,    53,    55,
    59,    61,    63,    65,    69,    71
};

static const short yyrhs[] = {    19,
     0,    19,    20,     0,     0,    11,     0,    24,    11,     0,
     6,    24,    11,     0,     7,    29,    11,     0,    21,     0,
    23,     0,     1,    11,     0,     4,    12,    24,    13,    20,
    22,     0,     5,    20,     0,     0,    14,    19,    15,     0,
    25,     0,    24,     9,    26,     0,    26,     0,    29,     8,
    26,     0,    27,     0,    27,    10,    28,     0,    28,     0,
    29,     0,    30,     0,    12,    24,    13,     0,    16,     0,
    17,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    74,    78,    79,    83,    84,    85,    86,    87,    88,    89,
    95,   105,   106,   110,   114,   118,   119,   123,   124,   128,
   129,   133,   134,   135,   139,   150
};

static const char * const yytname[] = {   "$","error","$undefined.","ERROR_TOKEN",
"IF","ELSE","PRINT","INPUT","ASSIGN","EQUAL","CONCAT","END_STMT","OPEN_PAR",
"CLOSE_PAR","BEGIN_CS","END_CS","ID","STRING","program","statement_list","statement",
"if_statement","optional_else_statement","compound_statement","expression","equal_expression",
"assign_expression","concat_expression","simple_expression","identifier","string",
""
};
#endif

static const short yyr1[] = {     0,
    18,    19,    19,    20,    20,    20,    20,    20,    20,    20,
    21,    22,    22,    23,    24,    25,    25,    26,    26,    27,
    27,    28,    28,    28,    29,    30
};

static const short yyr2[] = {     0,
     1,     2,     0,     1,     2,     3,     3,     1,     1,     2,
     6,     2,     0,     3,     1,     3,     1,     3,     1,     3,
     1,     1,     1,     3,     1,     1
};

static const short yydefact[] = {     3,
     0,     0,     0,     0,     0,     4,     0,     3,    25,    26,
     2,     8,     9,     0,    15,    17,    19,    21,    22,    23,
    10,     0,     0,     0,     0,     0,     0,     5,     0,     0,
     0,     6,     7,    24,    14,    16,    20,    22,    18,     0,
    13,     0,    11,    12,     0,     0,     0
};

static const short yydefgoto[] = {    45,
     1,    11,    12,    43,    13,    14,    15,    16,    17,    18,
    19,    20
};

static const short yypact[] = {-32768,
     6,    -9,     2,    -1,   -13,-32768,    -1,-32768,-32768,-32768,
-32768,-32768,-32768,    35,-32768,-32768,    -2,-32768,    13,-32768,
-32768,    -1,    40,    15,    -4,    24,    -1,-32768,    -1,    -1,
    20,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    41,
    22,    41,-32768,-32768,    32,    43,-32768
};

static const short yypgoto[] = {-32768,
    42,    14,-32768,-32768,-32768,    -3,-32768,     7,-32768,    30,
    -5,-32768
};


#define	YYLAST		59


static const short yytable[] = {    24,
    23,    21,     9,    25,    27,    -1,     2,    29,    34,     3,
     7,     4,     5,    22,     9,    10,     6,     7,    31,     8,
    30,     9,    10,    38,     2,    33,    42,     3,    27,     4,
     5,    46,    40,    36,     6,     7,    39,     8,    35,     9,
    10,     2,    47,    27,     3,    28,     4,     5,    27,    26,
    32,     6,     7,    41,     8,    44,     9,    10,    37
};

static const short yycheck[] = {     5,
     4,    11,    16,     7,     9,     0,     1,    10,    13,     4,
    12,     6,     7,    12,    16,    17,    11,    12,    22,    14,
     8,    16,    17,    29,     1,    11,     5,     4,     9,     6,
     7,     0,    13,    27,    11,    12,    30,    14,    15,    16,
    17,     1,     0,     9,     4,    11,     6,     7,     9,     8,
    11,    11,    12,    40,    14,    42,    16,    17,    29
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 74 ".\scripting\string.y"
{tree = yyvsp[0].tnode;;
    break;}
case 2:
#line 78 ".\scripting\string.y"
{yyval.tnode = new TreeNode (STMT_LIST, yyvsp[-1].tnode, yyvsp[0].tnode);;
    break;}
case 3:
#line 79 ".\scripting\string.y"
{yyval.tnode = new TreeNode (EMPTY_STMT);;
    break;}
case 4:
#line 83 ".\scripting\string.y"
{yyval.tnode = new TreeNode (EMPTY_STMT);;
    break;}
case 5:
#line 84 ".\scripting\string.y"
{yyval.tnode = new TreeNode (EXPR_STMT, yyvsp[-1].tnode);;
    break;}
case 6:
#line 85 ".\scripting\string.y"
{yyval.tnode = new TreeNode (PRINT_STMT, yyvsp[-1].tnode);;
    break;}
case 7:
#line 86 ".\scripting\string.y"
{yyval.tnode = new TreeNode (INPUT_STMT); yyval.tnode->symbol = yyvsp[-1].symbol;;
    break;}
case 8:
#line 87 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 9:
#line 88 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 10:
#line 89 ".\scripting\string.y"
{yyval.tnode = new TreeNode (ERROR_STMT);;
    break;}
case 11:
#line 96 ".\scripting\string.y"
{
           if (yyvsp[0].tnode != NULL)
              yyval.tnode = new TreeNode (IFTHENELSE_STMT, yyvsp[-3].tnode, yyvsp[-1].tnode, yyvsp[0].tnode);
           else
              yyval.tnode = new TreeNode (IFTHEN_STMT, yyvsp[-3].tnode, yyvsp[-1].tnode);
        ;
    break;}
case 12:
#line 105 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 13:
#line 106 ".\scripting\string.y"
{yyval.tnode = NULL;;
    break;}
case 14:
#line 110 ".\scripting\string.y"
{yyval.tnode = yyvsp[-1].tnode;;
    break;}
case 15:
#line 114 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 16:
#line 118 ".\scripting\string.y"
{yyval.tnode = new TreeNode (EQUAL_EXPR, yyvsp[-2].tnode, yyvsp[0].tnode);;
    break;}
case 17:
#line 119 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 18:
#line 123 ".\scripting\string.y"
{yyval.tnode = new TreeNode (ASSIGN_EXPR, yyvsp[0].tnode); yyval.tnode->symbol = yyvsp[-2].symbol;;
    break;}
case 19:
#line 124 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 20:
#line 128 ".\scripting\string.y"
{yyval.tnode = new TreeNode (CONCAT_EXPR, yyvsp[-2].tnode, yyvsp[0].tnode);;
    break;}
case 21:
#line 129 ".\scripting\string.y"
{yyval.tnode = yyvsp[0].tnode;;
    break;}
case 22:
#line 133 ".\scripting\string.y"
{yyval.tnode = new TreeNode (IDENT_EXPR); yyval.tnode->symbol = yyvsp[0].symbol;;
    break;}
case 23:
#line 134 ".\scripting\string.y"
{yyval.tnode = new TreeNode (STR_EXPR); yyval.tnode->symbol = yyvsp[0].symbol;;
    break;}
case 24:
#line 135 ".\scripting\string.y"
{yyval.tnode = yyvsp[-1].tnode;;
    break;}
case 25:
#line 140 ".\scripting\string.y"
{
           yyval.symbol = st.Find (yyvsp[0].str);
           if (yyval.symbol == NULL)   { // doesn't exist yet; create it
              yyval.symbol = new SymDesc (yyvsp[0].str, STR_VAR, NULL, lineno);
              st.Add (yyval.symbol);
           }
        ;
    break;}
case 26:
#line 151 ".\scripting\string.y"
{
           yyval.symbol = new SymDesc (MakeName(), STR_CONST, yyvsp[0].str, lineno);
           st.Add (yyval.symbol);
        ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}


#line 157 ".\scripting\string.y"


// Código adicional

// Genera un nombre único para una constante de cadena

char *MakeName ()  {
   char *name = new char [10], num[4];
   static n = 0;
   sprintf (num, "%d", ++n);
   strcpy (name, "strconst"); strcat (name, num);
   return name;
}
