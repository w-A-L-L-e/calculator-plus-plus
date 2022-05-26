

#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void usage(string name){
  cout<<"Usage: "<<name<<" [option] [\" EXPRESSION \"] "<<endl;
  cout<<"  options:"<<endl;
  cout<<"    --help          show this text"<<endl;
  cout<<"    EXPRESSION:     This is a mathematical expression"<<endl;
  cout<<"                    containing +, -, * or /."<<endl;
  cout<<"                    When the expression is invalid 'invalid expression!'"<<endl;
  cout<<"                    will be given on stderr"<<endl;
  cout<<"                    For valid expressions the result is given on stdout."<<endl<<endl;  
  cout<<"                    11/4/2006 added time expressions by using ex. 12h10 or 10m it makes a time variable and these can do basic operations"<<endl<<endl;  
  cout<<"   example 1: "<<name<<" 3+2 gives 5 on stdout"<<endl;
  cout<<"   example 2: "<<name<<" 2.0/3.0 gives 0.666667 on stdout"<<endl<<endl;
  cout<<"  When no option and no expression is given, the calculator will run"<<endl;
  cout<<"  in interactive mode."<<endl;
}


int main(int argc, char* argv[])
{
    Parser calc;

    if(argc==1){
      cout<< ".------------------------------------------------------."<<endl;
      cout<< "|                  Simple calculator                   |"<<endl;
      cout<< "|             Author: Walter Schreppers                |"<<endl;
      cout<< "`------------------------------------------------------'"<<endl;
      cout<< " Give empty line to exit                                "<<endl;
      cout<< " [a-zA-Z]* specifies a variable name for storing        "<<endl;
      cout<< " ANS is special variable which always stores last result"<<endl;
      cout<< " for float expressions add a decimal point in constants "<<endl;
      cout<< " start with option --help to see cmdline usage...       "<<endl;
      cout<< "--------------------------------------------------------"<<endl;

      return calc.parse();
    }
    else if(argc==2){
      string arg(argv[1]);
      if(arg=="--help"){
        usage(argv[0]);
        return 1; //error
      }
      return calc.parse(arg); //always returns 0, even if it was a bad expression
    }
    else{
      usage(argv[0]);
      return 1; //error
    }
}

