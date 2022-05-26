
#ifndef VAR_H
#define VAR_H

#include "Time.h"

//better to use a map... make a symboltable class instead...
//for now this works :)
#include <string>
using std::string;

class var{
  public:
    var(const string& n,double d){
      name=n;
      dval=d;
      isInt=false;
    }
    var(const string& n,int i){
      name=n;
      ival=i;
      isInt=true;
    }
    var(const string& n,Time t){
      name=n;
      tval=t;
      isInt = false;
    }
    
    string name;
    int    ival;
    double dval;
    Time   tval;
    bool   isInt;
};

#endif

