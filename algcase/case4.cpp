#include<iostream>

using namespace std;



int snuOppNed(const int n){
  string intString = to_string(n);
  const int lengthOfInt = intString.length();

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


  return stoi(intString); 
}

int main(){
  for(int i =1; i < 100001;i++){
    int snudd = snuOppNed(i);
    if(snudd != 0 && snudd == i) {
      cout << i << " blir " << snudd << endl;
    }
  }

  return 0;
}
