/**
* slower than v2 but easier to come up with
*/
#include <iostream>

using namespace std;
const int N = 9; 

int gKlasse[N];
int soulutionCounter = 0; 

void initKlasse(){
  for(int i = 1; i <= N;i ++) {
    gKlasse[i-1] = i;
  }
}


void printKlasse(int klasse[N]){
  for(int i= 0; i< N;i++) {
    cout << klasse[i] << " " ;
  }
  cout << endl;
}

bool sjekkUvenner(int klasse[N] ){
  for(int i = 0; i< N-1; i++) {
    if(klasse[i ] - klasse[i+1] == 1 ||
       klasse[i+1] - klasse[i] == 1  ) {
      return false;
    }
  }
  return true;
}


void permuterKlasse(int klasse[N],int start,int slutt){
  if(start == slutt && sjekkUvenner(klasse)) {
    printKlasse(klasse);
    soulutionCounter++;
  } else{
    for(int i = start; i <= slutt;i++) {
      // bytter
      int tmp = klasse[start];
      klasse[start] = klasse[i] ;
      klasse[i] = tmp;
      permuterKlasse(klasse,start+1,slutt);

      //back track
      klasse[i] = klasse[start] ;
      klasse[start] = tmp;
    }
  }

}


int main (){
  initKlasse();
  permuterKlasse(gKlasse,0,N-1);
  cout << "Antall losninger: " << soulutionCounter << endl; 

  return 0;
}

