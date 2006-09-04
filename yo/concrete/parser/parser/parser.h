#ifndef YY_Parser_h_included
#define YY_Parser_h_included

#line 1 "/usr/local/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/usr/local/lib/bison.h" */
#line 2 "gramspec/grammar"

#line 2  "header.gr0"
    #include "../scanner/scanner.h"
    #include <cstdlib>
    #include <iostream>
    #include <sstream>
    #include <fbb/a2x.h>

    using FBB::A2x;
    using std::cerr;
    using std::cout;
    using std::endl;

#line 26 "gramspec/grammar"
typedef union {
#line 4  "tokens.gr0"
    int i;
    double d;
} yy_Parser_stype;
#define YY_Parser_STYPE yy_Parser_stype
#define YY_Parser_LEX_BODY  {return d_scanner.yylex();}
#define YY_Parser_ERROR_BODY  { std::cerr << "error encountered\n"; }
#define YY_Parser_MEMBERS                                          \
    virtual ~Parser()   {}                              \
    private:                                            \
        std::ostringstream d_rpn;                       \
        Scanner d_scanner;
#define YY_Parser_DEBUG  1

#line 14 "/usr/local/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_Parser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_Parser_COMPATIBILITY 1
#else
#define  YY_Parser_COMPATIBILITY 0
#endif
#endif

#if YY_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_Parser_LTYPE
#define YY_Parser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_Parser_STYPE
#define YY_Parser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_Parser_DEBUG
#define  YY_Parser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_Parser_STYPE
#ifndef yystype
#define yystype YY_Parser_STYPE
#endif
#endif
#endif

#ifndef YY_Parser_PURE

/* #line 54 "/usr/local/lib/bison.h" */

#line 54 "/usr/local/lib/bison.h"
/* YY_Parser_PURE */
#endif

/* #line 56 "/usr/local/lib/bison.h" */

#line 56 "/usr/local/lib/bison.h"
/* prefix */
#ifndef YY_Parser_DEBUG

/* #line 58 "/usr/local/lib/bison.h" */

#line 58 "/usr/local/lib/bison.h"
/* YY_Parser_DEBUG */
#endif
#ifndef YY_Parser_LSP_NEEDED

/* #line 61 "/usr/local/lib/bison.h" */

#line 61 "/usr/local/lib/bison.h"
 /* YY_Parser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_Parser_LSP_NEEDED
#ifndef YY_Parser_LTYPE
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

#define YY_Parser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_Parser_STYPE
#define YY_Parser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_Parser_PARSE
#define YY_Parser_PARSE yyparse
#endif
#ifndef YY_Parser_LEX
#define YY_Parser_LEX yylex
#endif
#ifndef YY_Parser_LVAL
#define YY_Parser_LVAL yylval
#endif
#ifndef YY_Parser_LLOC
#define YY_Parser_LLOC yylloc
#endif
#ifndef YY_Parser_CHAR
#define YY_Parser_CHAR yychar
#endif
#ifndef YY_Parser_NERRS
#define YY_Parser_NERRS yynerrs
#endif
#ifndef YY_Parser_DEBUG_FLAG
#define YY_Parser_DEBUG_FLAG yydebug
#endif
#ifndef YY_Parser_ERROR
#define YY_Parser_ERROR yyerror
#endif

#ifndef YY_Parser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_Parser_PARSE_PARAM
#ifndef YY_Parser_PARSE_PARAM_DEF
#define YY_Parser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_Parser_PARSE_PARAM
#define YY_Parser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_Parser_PURE
extern YY_Parser_STYPE YY_Parser_LVAL;
#endif


/* #line 134 "/usr/local/lib/bison.h" */
#define DONE    258
#define INT     259
#define DOUBLE  260
#define UnaryMinus      261


#line 134 "/usr/local/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_Parser_CLASS
#define YY_Parser_CLASS Parser
#endif

#ifndef YY_Parser_INHERIT
#define YY_Parser_INHERIT
#endif
#ifndef YY_Parser_MEMBERS
#define YY_Parser_MEMBERS
#endif
#ifndef YY_Parser_LEX_BODY
#define YY_Parser_LEX_BODY
#endif
#ifndef YY_Parser_ERROR_BODY
#define YY_Parser_ERROR_BODY
#endif
#ifndef YY_Parser_CONSTRUCTOR_PARAM
#define YY_Parser_CONSTRUCTOR_PARAM
#endif

class YY_Parser_CLASS YY_Parser_INHERIT
{
public: /* static const int token ... */

/* #line 160 "/usr/local/lib/bison.h" */
static const int DONE;
static const int INT;
static const int DOUBLE;
static const int UnaryMinus;


#line 160 "/usr/local/lib/bison.h"
 /* decl const */
public:
 int YY_Parser_PARSE(YY_Parser_PARSE_PARAM);
 virtual void YY_Parser_ERROR(char *msg) YY_Parser_ERROR_BODY;
#ifdef YY_Parser_PURE
#ifdef YY_Parser_LSP_NEEDED
 virtual int  YY_Parser_LEX(YY_Parser_STYPE *YY_Parser_LVAL,YY_Parser_LTYPE *YY_Parser_LLOC) YY_Parser_LEX_BODY;
#else
 virtual int  YY_Parser_LEX(YY_Parser_STYPE *YY_Parser_LVAL) YY_Parser_LEX_BODY;
#endif
#else
 virtual int YY_Parser_LEX() YY_Parser_LEX_BODY;
 YY_Parser_STYPE YY_Parser_LVAL;
#ifdef YY_Parser_LSP_NEEDED
 YY_Parser_LTYPE YY_Parser_LLOC;
#endif
 int YY_Parser_NERRS;
 int YY_Parser_CHAR;
#endif
#if YY_Parser_DEBUG != 0
public:
 int YY_Parser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_Parser_CLASS(YY_Parser_CONSTRUCTOR_PARAM);
public:
 YY_Parser_MEMBERS
};
/* other declare folow */
#endif


#if YY_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_Parser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_Parser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_Parser_DEBUG
#define YYDEBUG YY_Parser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 209 "/usr/local/lib/bison.h" */
#endif
