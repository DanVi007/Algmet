#include <iostream>

using namespace std;

const int N = 8;

//  Brukes for å teste  prefixB:
int num[][N]= {{ 113, 403, 1143, 5043, 5047,  11612345, 11812345, 62529903 },
               { 113, 403, 1134, 5043, 5047,  11612345, 11812345, 62529903 },
               { 113, 403, 1143, 5043, 50437, 11612345, 11812345, 62529903 }};

/**
* Arrayen kommer inn sortert etter størelse, fra liten til stor
*/
bool prefix(int array[] ,const int lenArray ) {
  for(int i = 0; i < lenArray;i++) {
    for(int j = i+1 ; j < lenArray;j++) {
      int largerNumber = array[j];
      while(largerNumber >= array[i] ) {
        if (largerNumber == array[i]) {
          cout << array[j] << " ,  " << array[i] << endl;
          return true;
        }
        largerNumber /= 10;
      }
    }
  }
  return false;
}

int main(){

  cout << "num[0] er " << ((prefix(num[0],N)) ? "IKKE " : "") << "OK\n\n";
  cout << "num[1] er " << ((prefix(num[1],N)) ? "IKKE " : "") << "OK\n\n";
  cout << "num[2] er " << ((prefix(num[2],N)) ? "IKKE " : "") << "OK\n\n";
  cout << "\n\n";
  return 0;
}
