#include <iostream>

using namespace std;



int main(){
  const int N = 1000000;
  int tallene[N]; 

  int storsteTall  =tallene[0];
  int sum = storsteTall;
  int antallSum = 1;
  for(int i = 1; i < N;i++){
    if(tallene[i] >= storsteTall){
      sum += tallene[i];
      storsteTall = tallene[i];
      antallSum++;
    }
  }

  cout << "Totalsum: " <<  sum << endl;
  cout << "Antall summert: " <<  antallSum << endl;
  return 0;


}

