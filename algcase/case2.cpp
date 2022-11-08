#include <iostream>
using namespace std;

const int maxArraySize = 30;


void printPerfectNumbers(const int amountOfNumbers){
  int currentAmountFound = 0;
  long int foundNumber = 1;
  long int divisibleNumbers[maxArraySize] ;
  while(currentAmountFound < amountOfNumbers) {
    int arrayIndex = 0;
    
    for(long int i = foundNumber; i > 0;i-- ){
      if(foundNumber != i && foundNumber % i == 0  ){
        divisibleNumbers[arrayIndex] = i;
        arrayIndex++;
      }
    }

    long int currentSum = 0 ;
    for(int j = 0 ; j < arrayIndex;j++) {
      currentSum += divisibleNumbers[j];
    }
    if(currentSum == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;

    // empty divisible numbers
    for(int i = 0; i < arrayIndex;i++){
      divisibleNumbers[i] = 0;
    }

  }        
}


void printPerfectNumbersTest(){
  int currentAmountFound = 0;
   int foundNumber = 33550336;
   int divisibleNumbers[maxArraySize] ;
    int arrayIndex = 0;
    
    for(int i = foundNumber; i > 0;i-- ){
      if( foundNumber != i && foundNumber % i == 0  ){
        divisibleNumbers[arrayIndex] = i;
        arrayIndex++;
        
      }
    }

    int currentSum = 0 ;
    for(int j = 0 ; j < arrayIndex;j++) {
      currentSum += divisibleNumbers[j];
    }
    if(currentSum == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
      cout << arrayIndex << endl;
    }

    
    // empty divisible numbers
    for(int i = 0; i < arrayIndex;i++){
      divisibleNumbers[i] = 0;
    }

}

void printPerfectNumbers2(const int amountOfNumbers){
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int divisibleNumbers[maxArraySize] = {} ;
    int arrayIndex = 0;
    
    for( int i = foundNumber; i > 0;i-- ){
      if(foundNumber != i && foundNumber % i == 0  ){
        divisibleNumbers[arrayIndex] = i;
        arrayIndex++;
      }
    }

    int currentSum = 0 ;
    for(int j = 0 ; j < arrayIndex;j++) {
      currentSum += divisibleNumbers[j];
    }
    if(currentSum == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;
  }        
}

void printPerfectNumbers3(const int amountOfNumbers){
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int divisibleNumbers[maxArraySize] = {} ;
    int arrayIndex = 0;
    
    for( int i = foundNumber/2; i > 0;i-- ){
      if( foundNumber % i == 0  ){
        divisibleNumbers[arrayIndex] = i;
        arrayIndex++;
      }
    }

    int currentSum = 0 ;
    for(int j = 0 ; j < arrayIndex;j++) {
      currentSum += divisibleNumbers[j];
    }
    if(currentSum == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;
  }        
}
bool sumOfArrayValid(int array[] , int lastIndex,int foundNumber){
  int currentSum = 0;
    for(int j = lastIndex; j  >= 0 ;j--) {
      currentSum += array[j];
      if(currentSum > foundNumber){
        return false;
      }     
    }
    return true;
}
void printPerfectNumbers4(const int amountOfNumbers){
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int divisibleNumbers[maxArraySize] = {} ;
    int arrayIndex = 0;
    
    for( int i = foundNumber/2; i > 0;i-- ){
      if( foundNumber % i == 0  ){
        divisibleNumbers[arrayIndex] = i;
        arrayIndex++;
      }
    }

    int currentSum = 0 ;
    for(int j = arrayIndex ; j  >= 0 ;j--) {
      currentSum += divisibleNumbers[j];
      if(currentSum > foundNumber){
        j= -1;
      } else if(j == 0 && currentSum == foundNumber){
        currentAmountFound++;
        cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
      }
    }
    foundNumber++;
  }        
}
//broken
void printPerfectNumbers5(const int amountOfNumbers){
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int divisibleNumbers[maxArraySize] = {} ;
    int arrayIndex = 0;
    int currentSum = 0;
    
    for( int i = foundNumber/2; i > 0;i-- ){
      if(currentSum > foundNumber){
        i = 0;
      }else {
        if( foundNumber % i == 0  ){
          divisibleNumbers[arrayIndex] = i;
          if(arrayIndex < maxArraySize){
            arrayIndex++;
          }
          currentSum+= i;
        }
      }
    }

    for(int j = arrayIndex ; j  >= 0 ;j--) {
      currentSum += divisibleNumbers[j];
      if(currentSum > foundNumber){
        j= -1;
      } else if(j == 0 && currentSum == foundNumber){
        currentAmountFound++;
        cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
      }
    }
    foundNumber++;
  }        
}

void printPerfectNumbers6(const int amountOfNumbers){
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers){
    int sumOfNumbers = 0;
    for(int i = foundNumber/2 ; i > 0; i--){
      if(foundNumber % i == 0 ){
        sumOfNumbers+= i;
      }
      if(sumOfNumbers > foundNumber){
        i = 0;
      } else if(i== 1 && sumOfNumbers == foundNumber ){
        currentAmountFound++;
        cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
        i = 0;
      }
    }
    foundNumber++;

  }
}

void printPerfectNumbers7(const int amountOfNumbers) {
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int sumOfNumbers = 0;
    for(int i = foundNumber/2 ; i > 0; i--){
      if(foundNumber % i == 0 ){
        sumOfNumbers+= i;
        if(sumOfNumbers > foundNumber){
          i = 0;
        }       
      } 
    }
    if(sumOfNumbers == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;
  }
}

void printPerfectNumbersTest7(const int amountOfNumbers) {
  int currentAmountFound = 0;
  int foundNumber = 33550000;
  while(currentAmountFound < amountOfNumbers) {
    int sumOfNumbers = 0;
    for(int i = foundNumber/2 ; i > 0; i--){
      if(foundNumber % i == 0 ){
        sumOfNumbers+= i;
        if(sumOfNumbers > foundNumber){
          i = 0;
        }       
      } 
    }
    if(sumOfNumbers == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;
  }
}
// broken logic 
void printPerfectNumbers8(const int amountOfNumbers) {
  int currentAmountFound = 0;
  int foundNumber = 1;
  while(currentAmountFound < amountOfNumbers) {
    int sumOfNumbers = 0;
    int tempNum = foundNumber;
    for(int i = foundNumber/2 ; i > 0; i--){
      if(tempNum % i == 0 ){
        sumOfNumbers+= i;
        tempNum = tempNum/i;
        if(sumOfNumbers > foundNumber){
          i = 0;
        }       
      } 
    }
    if(sumOfNumbers == foundNumber){
      currentAmountFound++;
      cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
    }
    foundNumber++;
    cout << foundNumber << endl;
  }
}

//not finished
// void printPerfectNumbers5(const int amountOfNumbers){
//   int currentAmountFound = 0;
//   int foundNumber = 1;
//   while(currentAmountFound < amountOfNumbers) {
//     int divisibleNumbers[maxArraySize] = {} ;
//     int arrayIndex = 0;
//
//     bool done = false;
//     while(!done){
//       int currentNumber = foundNumber/2 +1;
//     }    
//
//     int currentSum = 0 ;
//     for(int j = arrayIndex ; j  >= 0 ;j--) {
//       currentSum += divisibleNumbers[j];
//       if(currentSum > foundNumber){
//         j= -1;
//       } else if(j == 0 && currentSum == foundNumber){
//         currentAmountFound++;
//         cout << currentAmountFound <<" perfect number is "<< foundNumber << endl; 
//       }
//     }
//     foundNumber++;
//   }        


int main(){
 //printPerfectNumbers(5);
 //printPerfectNumbers2(5);
 //printPerfectNumbers3(5);
 // printPerfectNumbers4(5);
 // printPerfectNumbers5(5);
  //printPerfectNumbersTest();
  // printPerfectNumbers6(5);
//printPerfectNumbers7(5);
printPerfectNumbersTest7(1);
//printPerfectNumbers8(5);
  return 0;
}
