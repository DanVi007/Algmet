#include <iostream>

using namespace std;

int solutionCounter = 0;

const int N = 10;            ///<  Antall noder i grafen.

                             ///   Nabomatrisen:
         // Node nr:  0  1  2  3  4  5  6  7  8  9       Node nr: 
int gNabo[N][N] = { { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },    //  0
                    { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0 },    //  1
                    { 1, 0, 0, 0, 1, 1, 1, 0, 0, 0 },    //  2
                    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },    //  3
                    { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },    //  4
                    { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0 },    //  5
                    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 },    //  6
                    { 1, 0, 0, 0, 1, 1, 1, 0, 0, 1 },    //  7
                    { 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },    //  8
                    { 0, 0, 0, 0, 1, 0, 1, 1, 1, 0 } };  //  9
int gSum[N] = { 21, 33, 14, 27, 1, 14, 20, 12, 28, 20 }; ///< Nodenes nabosum.
int gArray[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };   ///<  Nodenes aktuelle ID.
/// index er referanse 

void printGarray() {
  for(int i = 0; i < 10;i++){
    cout << gArray[i ] << " , " ;
  }
  cout << endl;
}

void swap(int & a, int & b){
  int tmp = a;
  a = b;
  b = tmp;
}

bool checkSolution() {
  for(int i = 0;i < 10;i++) {
    int sum = 0;
    for(int j = 0; j < 10;j ++) {
      if(gNabo[i][j] == 1){
        sum += gArray[j]; // henter ekte id med referanse
      }
    }
    if(sum != gSum[gArray[i]]) {
      return false;
    }
  }
  return true;
}

void printAnswer(const int node ){
  if(node == 9 ) {
    if( checkSolution()){
      solutionCounter++;
      cout << "Solution" << endl;
      printGarray();
    }
  } else{
    for(int i = node; i < 10;i++){
      swap(gArray[node] , gArray[i]);
      printAnswer(node+1);
      swap(gArray[node] , gArray[i]);
    }
  }
}

int main(){
  printAnswer(0);
  cout << solutionCounter << endl;
  return 0;
}
