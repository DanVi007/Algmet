#include<iostream>
using namespace std;

int main(){
  char aChar = 'b';
  string aString ;
  aString += aChar;
  aString = "";
  aString += 'c';
  cout << aString << endl;
  
  return 0;
}
