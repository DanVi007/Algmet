#include <iostream> 
#include <cstdlib>

using namespace std;

/**
* sorts an array of ints from smallest to largest
*/
void insertionSort(int array[] ,const int lenArray){
  if(lenArray != 0) {
    for(int i = 1; i < lenArray; i++) {
      int j = i;
      int currentValue = array[i];
      while(j > 0 && currentValue < array[j-1]) {
        array[j] = array[j-1];
        j--;
      }
      array[j] = currentValue;
    }
  }
}

void printArray(int array[], const int lenArray) {
  cout << "Array " << endl;
  for(int i = 0; i < lenArray;i++) {
    cout << array[i] << " , " ;
  }
  cout << endl << endl;
}

void generateArray(int array[] ,const int lenArray) {
  for(int i = 0; i < lenArray;i++ ) {
    array[i] = rand();
  }
}


int main(){
  const int N = 20;
  int testArray[N ];
  generateArray(testArray,N);
  printArray(testArray,N);
  insertionSort(testArray,N);
  printArray(testArray,N);
  return 0;
}
