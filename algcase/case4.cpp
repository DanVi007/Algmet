#include<iostream>

using namespace std;



int snuOppNed(const int n){
  string intString = to_string(n);
  const int lengthOfInt = intString.length();
  const int arrayStorelse = lengthOfInt; 
  int hoyrePunkt; 
  int venstrePunkt;
  if(lengthOfInt % 2 == 0){
    hoyrePunkt = lengthOfInt/2; 
    venstrePunkt = hoyrePunkt-1;
  } else {
    hoyrePunkt = lengthOfInt/2;
    venstrePunkt = hoyrePunkt;
  }

  for( hoyrePunkt; hoyrePunkt <lengthOfInt;hoyrePunkt++ ){
    int midlertidlig = intString[venstrePunkt] ;
    intString[venstrePunkt] = intString[hoyrePunkt];
    intString[hoyrePunkt] = midlertidlig;
    venstrePunkt--;
  }


  // snu alle tallene i intString ork å gjøre men ha en haug med switch
  // hvis det ikke er mulig return 0
  
  return stoi(intString); 
}

int main(){
  snuOppNed(5);

  return 0;
}
