#include <iostream>

using namespace std;

int fjernDuplikater(int a[], const int n){
  if(n== 0 || n== 1) {
    return n;
  } 
  int unikInt = a[1];
  int antallUnike = 1;

  for(int i = 1; i < n;i++){
    if(unikInt != a[i+1]){
      unikInt = a[i+1];
      antallUnike++;
      a[antallUnike] = unikInt;
    }else {
      a[i+1] = 0;
    }
  }
  return antallUnike;
}

int main(){

}
