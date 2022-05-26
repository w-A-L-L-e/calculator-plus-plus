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
#line 21 "parser.h"
#line 9 "parser.y"

        #include <stdio.h>
        #include <string> 
        #include <list>
        #include <iostream>
        #include <fstream>
      #ifndef yyFlexLexer
        #include <FlexLexer.h>
      #endif
        #include <vector>
        #include <sstream>
        #include "var.h"
        #include "Time.h"
        using std::vector;
        using std::cout;
        using std::cerr;
        using std::endl;
        using std::istringstream;
        using std::ifstream;
        using std::ofstream;
        using std::list;

#line 33 "parser.y"
typedef union 
{
    int      i;
    double   d;
    string*  n;
    Time*    t;
} yy_Parser_stype;
#define YY_Parser_STYPE yy_Parser_stype
#define YY_Parser_MEMBERS                                  \
  vector<var> vars;                             \
  virtual ~Parser(void) {;}                     \
  int parse( string );                          \
  int parse( ifstream* );                       \
  int parse();                                  \
  void init();                                  \
  void assign( const string&, double );         \
  void assign( const string&, const Time& t );  \
  double getValue(const string&);               \
  Time   getTimeValue( const string& );		\
  yyFlexLexer lexer;                            
#define YY_Parser_LEX_BODY  { return lexer.yylex(); }
#define YY_Parser_ERROR_BODY  { }
#define YY_Parser_CONSTRUCTOR_PARAM 
#define YY_Parser_CONSTRUCTOR_CODE  {  \
  init();                   \
}

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
/* use goto to be compatible */
#ifndef YY_Parser_USE_GOTO
#define YY_Parser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_Parser_USE_GOTO
#define YY_Parser_USE_GOTO 0
#endif

#ifndef YY_Parser_PURE

/* #line 63 "/usr/local/lib/bison.h" */
#line 125 "parser.h"

#line 63 "/usr/local/lib/bison.h"
/* YY_Parser_PURE */
#endif

/* #line 65 "/usr/local/lib/bison.h" */
#line 132 "parser.h"

#line 65 "/usr/local/lib/bison.h"
/* prefix */
#ifndef YY_Parser_DEBUG

/* #line 67 "/usr/local/lib/bison.h" */
#line 139 "parser.h"

#line 67 "/usr/local/lib/bison.h"
/* YY_Parser_DEBUG */
#endif
#ifndef YY_Parser_LSP_NEEDED

/* #line 70 "/usr/local/lib/bison.h" */
#line 147 "parser.h"

#line 70 "/usr/local/lib/bison.h"
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


/* #line 143 "/usr/local/lib/bison.h" */
#line 225 "parser.h"
#define	NAME	258
#define	INT	259
#define	DOUBLE	260
#define	HOUR	261
#define	MIN	262
#define	SEC	263
#define	UnaryMinus	264


#line 143 "/usr/local/lib/bison.h"
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
/* choose between enum and const */
#ifndef YY_Parser_USE_CONST_TOKEN
#define YY_Parser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_Parser_USE_CONST_TOKEN != 0
#ifndef YY_Parser_ENUM_TOKEN
#define YY_Parser_ENUM_TOKEN yy_Parser_enum_token
#endif
#endif

class YY_Parser_CLASS YY_Parser_INHERIT
{
public: 
#if YY_Parser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/usr/local/lib/bison.h" */
#line 277 "parser.h"
static const int NAME;
static const int INT;
static const int DOUBLE;
static const int HOUR;
static const int MIN;
static const int SEC;
static const int UnaryMinus;


#line 182 "/usr/local/lib/bison.h"
 /* decl const */
#else
enum YY_Parser_ENUM_TOKEN { YY_Parser_NULL_TOKEN=0

/* #line 185 "/usr/local/lib/bison.h" */
#line 293 "parser.h"
	,NAME=258
	,INT=259
	,DOUBLE=260
	,HOUR=261
	,MIN=262
	,SEC=263
	,UnaryMinus=264


#line 185 "/usr/local/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
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
 int YY_Parser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
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

/* #line 236 "/usr/local/lib/bison.h" */
#line 357 "parser.h"
#endif
