#ifndef PARSEFUNCTIONS_H
#define PARSEFUNCTIONS_H

extern void setParser(Parser*);

/*
QString Parser::parse(QString iString) {
  // Delete previous result and inputstream
  if ( mString!=0 )
    delete mString;
  		
  iString=iString+"\n";
  istringstream *mInput=new istringstream( (char*) iString.latin1() ); 
  mLexer.switch_streams(mInput, 0);
  if (yyparse()) 
    return *mString;
  else return "";
}		
*/


int Parser::parse(string in){
  in=in+"\n\n";
  setParser(this);
  istringstream* input=new istringstream( in.c_str() );
  lexer.switch_streams(input, 0);
  return yyparse();
}

int Parser::parse(ifstream* in){
  //set new input stream for lexer
  setParser(this);
  lexer.switch_streams(in,0);
  return yyparse ();
}

int Parser::parse(){
  setParser(this);
  //lexer.switch_streams(in,0);
  return yyparse ();
}


void Parser::init(){
  vars.clear();
  var v("ans",0);
  vars.push_back(v);
}

void Parser::assign(const string& name,double val){
  //cout<<val<<endl;
  for(vector<var>::iterator i=vars.begin();i!=vars.end();i++){
    if(name==i->name){
      i->dval=val;
      i->isInt=false;
      return;
    }
  }
  var v(name,val);
  vars.push_back(v);
}

//ouch code duplication... refactor this... see var.h 
void Parser::assign(const string& name, const Time& t){
  for(vector<var>::iterator i=vars.begin();i!=vars.end();i++){
    if(name==i->name){
      i->tval=t;
      i->isInt=false;
      return;
    }
  }
  var v(name,t);
  vars.push_back(v);
}


double Parser::getValue(const string& name){
  for(vector<var>::iterator i=vars.begin();i!=vars.end();i++){
    if(name==i->name){
      return i->dval;
    }
  }
  return 0;
}

Time Parser::getTimeValue(const string& name){
  for(vector<var>::iterator i=vars.begin();i!=vars.end();i++){
    if(name==i->name){
      return i->tval;
    }
  }
  return Time(0,0,0);
}

#endif


