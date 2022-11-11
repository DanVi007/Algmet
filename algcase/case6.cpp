#include <iostream> 
#include <stdio.h>

using namespace std;


int numbers[100];


bool checkNumber(int number) {
  
  if(number == 7 || number % 7 == 0) {
    return false;
  }
  char numberAsChar[3];
  itoa(number, numberAsChar,10);
  for(int i = 0; i < 3;i++){
    if(numberAsChar[i] == '7' ) {
      return false;
    }
  }
  return true;

}
void replaceNumbers(){
  int replaceNumber = 0;
  int altReplaceNumber = 0;
  for(int i = 0; i < 100; i++) {
    if(!checkNumber(numbers[i])){
      replaceNumber++;
      if(!checkNumber(replaceNumber)){
        altReplaceNumber++;
        numbers[i] = altReplaceNumber;
        
      } else {
        numbers[i] = replaceNumber;
      }
      cout << numbers[i] << ", " ;
    }
  }
}

void initNumbers(){
  for(int i = 1;i <= 100; i++) {
    numbers[i-1] = i;
  }
}

void printNumbers(){
  for(int i = 0 ;i < 100; i++) {
    cout << numbers[i] << ", ";
  }
}

int main(){
  initNumbers();

  replaceNumbers();

  //printNumbers();

  return 0;
}
