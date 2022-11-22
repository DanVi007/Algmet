#include <iostream> 
#include <stdio.h>

using namespace std;

const int NUMBERS = 100;
int numbers[NUMBERS];


bool checkNumber(int number) {
  if(number == 7 || number % 7 == 0) {
    return false;
  }
  
  while(number != 0 ){
    int numberToCheck = number %10;
    if(numberToCheck == 7 ) {
      return false;
    }
    number /= 10;
  }
  return true;
}

void replaceNumbers(){
  int replaceArray[NUMBERS] = {};
  for(int i = 0; i < NUMBERS;i++) {
    int index = 0;
    while(!checkNumber(numbers[i])){
      replaceArray[index]++;
      numbers[i] = replaceArray[index];
      index++;
    }
    cout <<  numbers[i] << " , ";
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

  printNumbers();

  return 0;
}
