  /*==================================================================*/
  /* description  : xml parser                                        */
  /* author       : Walter Schreppers                                 */
  /* created      : 9/1/2002                                          */
  /* modified     : /                                                 */
  /* bugs         : /                                                 */
  /*==================================================================*/  

%header{
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
%}

%name  Parser                
%union 
{
    int      i;
    double   d;
    string*  n;
    Time*    t;
};

%token  <n> NAME
%token  <i> INT
%token  <d> DOUBLE
%token  <i> HOUR
%token  <i> MIN
%token  <i> SEC


%type   <i> intExpr
%type   <d> doubleExpr
%type   <t> time
%type   <t> timeExpr


%left   '*' '+' '/' '-' NAME
%right  UnaryMinus



/*=============Parser class members=============*/
%define MEMBERS                                 \
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

  
  

/*==============Lexer body call=================*/
%define LEX_BODY { return lexer.yylex(); }

// ---------
// The error reporting funtion body
// ---------
%define ERROR_BODY { }

// ---------
// Constructor params + code
// ---------

%define CONSTRUCTOR_PARAM
%define CONSTRUCTOR_CODE {  \
  init();                   \
}

%%



lines:
    lines
    line
|
    line
;

line
: intExpr '\n'    {
                    assign("ans",$1);
                    cout << $1 << endl;
                  }
| doubleExpr '\n' {
                    assign("ans",$1);
                    cout << $1 << endl;
                  }
| timeExpr '\n' {
                    assign("ans",*$1);
                    cout << *$1 << endl;
                    delete $1;
                  }                  
| '\n'            {
                    //cout << "Good bye\n";
                    YYACCEPT;
                  }                  
| nameExpr '\n'   {
                  }
| error '\n'      {
                    cerr <<"invalid expression!"<<endl;
                  }
;

intExpr
: intExpr '*' intExpr {
                        $$ = $1 * $3;
                      }
| intExpr '+' intExpr {
                        $$ = $1 + $3;
                      }
| intExpr '/' intExpr {
                        $$ = $1 / $3;
                      }
| intExpr '-' intExpr {
                        $$ = $1 - $3;
                      }
                      
| '(' intExpr ')'     {
                        $$ = $2;
                      }
                      
| '-' intExpr         %prec UnaryMinus
                      {
                        $$ = -$2;
                      }
                      
| INT                 { 
                        $$=$1;
                      }
;

timeExpr
: timeExpr '+' timeExpr {
                          $$ = new Time( *$1 + *$3 );
                          delete $1;
                          delete $3;
                          
                      	}
| '(' timeExpr ')'      {
                          $$ = $2;
                        }
| time                  { 
                          $$ = $1;
                        }
;


time
: HOUR		{
			$$ = new Time( $1,0,0 );
		}
| HOUR MIN	{
			$$ = new Time( $1,$2,0 );
		}
| MIN		{
			$$ = new Time( 0,$1,0 );
		}
| SEC		{
			$$ = new Time( 0,0,$1 );
		}

| INT ':' INT	{
			$$ = new Time( $1,$3,0 );
		}
| INT ':' INT ':' INT	{
				$$ = new Time( $1, $3, $5 );
			}



doubleExpr
: doubleExpr '*' doubleExpr {
                              $$ = $1 * $3;
                            }
| doubleExpr '+' doubleExpr {
                              $$ = $1 + $3;
                            }
| doubleExpr '/' doubleExpr {
                              $$ = $1 / $3;
                            }
| doubleExpr '-' doubleExpr {
                              $$ = $1 - $3;
                            }



| doubleExpr '*' intExpr    {
                              $$ = $1 * $3;
                            }
| doubleExpr '+' intExpr    {
                              $$ = $1 + $3;
                            }
| doubleExpr '/' intExpr    {
                              $$ = $1 / $3;
                            }
| doubleExpr '-' intExpr    {
                              $$ = $1 - $3;
                            }
                            


| intExpr '*' doubleExpr    {
                              $$ = $1 * $3;
                            }
| intExpr '+' doubleExpr    {
                              $$ = $1 + $3;
                            }
| intExpr '/' doubleExpr    {
                              $$ = $1 / $3;
                            }
| intExpr '-' doubleExpr    {
                              $$ = $1 - $3;
                            }



| '(' doubleExpr ')'        {
                              $$ = $2;
                            }
                                                        
| '-' doubleExpr            %prec UnaryMinus
                            {
                              $$ = -$2;
                            }
                            
|   DOUBLE                  {
                              $$=$1;
                            }
|   NAME                    {
                              $$=getValue(*$1);
                              delete $1;
                            }
;



nameExpr
: NAME '=' doubleExpr       {
                              assign(*$1,$3);
                              delete $1;
                            }
| NAME '=' intExpr          {
                              assign(*$1,$3);
                              delete $1;
                            }


%%

#include "ParseFunctions.h"


