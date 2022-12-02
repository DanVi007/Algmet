#include <iostream>

using namespace std;

int fjernDuplikater(int a[], const int n){
  if(n== 0 || n== 1) {
    return n;
  } 
  int unikInt = a[1];//Verdien til en unik int.
  int antallUnike = 1;// antall unike, brukes også som ny indeks til unik verdi.

  for(int i = 1; i < n;i++){
    if(unikInt != a[i+1]){ // er den neste unik? 
      unikInt = a[i+1]; // da setter vi en ny unik
      antallUnike++; // inkrementerer antall unike.
      a[antallUnike] = unikInt;//setter den unike etter den forrige unike

    } 
    if(antallUnike != i+1 ){ // har vi overkjørt antallUnike?
      a[i+1] = 0; // da fjerner vi den neste 
    }
  }
  return antallUnike; // returnerer antall unike funnet.
}

// etter å ha sett på fasit
int fjernDuplikater2(int a[], const int n){
  if(n== 0 || n== 1) {
    return n;
  } 
  int antallUnike = 1;// antall unike, brukes også som indeks til unik verdi.

  for(int i = 1; i < n;i++){
    if(a[antallUnike]!= a[i+1]){ // er den neste unik? 
      antallUnike++; // inkrementerer antall unike.
      a[antallUnike] = a[i+1] ;//setter den unike etter den forrige unike
    } 
    if(antallUnike != i+1 ){ // har vi overkjørt antallUnike?
      a[i+1] = 0; // da fjerner vi den neste 
    }
  }
  return antallUnike; // returnerer antall unike funnet.
}

void printArray(int a[],const int len ) {
  for(int i = 0; i < len;i++) {
    cout << a[i] << " , ";
  }
  cout << endl;
}

int main(){
  int tall[15] = {0,1,2,2,2,3,4,5,5,5,7,9,10,11,11};
  printArray(tall,15);
  cout << fjernDuplikater2(tall,14) << endl;
  printArray(tall,15);




}
