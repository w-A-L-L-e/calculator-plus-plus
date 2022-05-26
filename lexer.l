%option noyywrap

%{ 
// simple flex++ example by Walter Schreppers
// the above option noyywrap avoids having to link against -lfl which does not exist on macOS
#include "parser.h"
#include <sstream>

Parser* pars;
void setParser(Parser* p){
  pars=p;
}

%}

EXP   ([eE][+-]?[0-9]+)

FA    [0-9]+("."[0-9]*)?
FB    [0-9]*("."[0-9]+)?
FLOAT ({FA}|{FB})
INT   [0-9]+
HOUR	({INT}[h])
MIN	  ({INT}[m])
SEC	  ({INT}[s])
%%

  /* "."[0-9]*EXP?| */
  /* [0-9]+("."[0-9]*)?EXP? */
  

[a-zA-Z_]*      {
                  pars->yylval.n = new string(yytext);
                  return(Parser::NAME);
                }
[ \t]           {}
{INT}           {
		  #ifdef _DEBUG_     
                  	std::cout << "int = " << yytext << std::endl;                             
                  #endif
                  pars->yylval.i = atol(yytext);
                  return(Parser::INT);
                }
{HOUR}		{
			std::istringstream hStream( yytext );
			int hour;
			hStream >> hour;
			#ifdef _DEBUG_
				std::cout <<"hour = " << hour << std::endl;
			#endif
			pars->yylval.i = hour;
			return( Parser::HOUR );	
		}
{MIN}		{
			std::istringstream minStream( yytext );
			int min;
			minStream >> min;
			#ifdef _DEBUG_
				std::cout <<"min = " << min << std::endl;
			#endif
			pars->yylval.i = min;
			return( Parser::MIN );
		}
{SEC}		{
			std::istringstream secStream( yytext );
			int sec;
			secStream >> sec;
			#ifdef _DEBUG_
				std::cout <<"sec = " << sec << std::endl;
			#endif
			pars->yylval.i = sec;
			return( Parser::SEC );
		}
{FLOAT}{EXP}?   {
		  #ifdef _DEBUG_
                  	std::cout << "double = " << yytext << std::endl;
                  #endif
                  pars->yylval.d = atof(yytext);
                  return(Parser::DOUBLE);
                }                
.|\n            {
		  #ifdef _DEBUG_
                  	std::cout << "operation = " << yytext << std::endl;
                  #endif
                  return (*yytext);
                }

%%

 /* source is allowed here ...*/
