
#include <iostream>
#include "Time.h"
using namespace std;

int main(){
  Time a(1,40,0);
  Time b(2,43,0);
  Time c=a+b;
  
  Time total(0,0,0);
  cout << "c="<<c<<endl;
  

  int h=0, m=0;
  while( h>=0 ){
    total = total + Time( h,m,0);
    cout <<"total time = " << total << endl;
    cout <<" add hour, min:"<<endl;
    cin >> h;
    cin >> m;
  }
  
  return 0;
  
}


