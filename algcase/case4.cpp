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
  for(int i = 0; i < lengthOfInt; i ++){
    char number = intString[i];
    switch(number){
      case '6':
       intString[i] = '9'; 
       break;
      case '9':
       intString[i] = '6';
       break;
      case '1':
       break;
      case '0':
       break;
      case '8':
       break;
      default:
       return 0;
    }
  }
  
  return stoi(intString); 
}

int main(){
  snuOppNed(5);

  return 0;
}
