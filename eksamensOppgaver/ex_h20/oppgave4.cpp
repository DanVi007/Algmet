#include <iostream>

using namespace std;

// Vi forutsetter at n >= 0, samt at a[0] != a[1].
// Antagelig bør koden spesialbehandle når n er 0 (null) eller 1.

int fjernDuplikater(int a[], const int n){
  int antallUnike = n;
  if(n == 0){
    return 0;
  }

  int i = 0;
  int j = 1;

  while(i < n){
    while(a[i] == a[j]){
      a[j] = 0;
      antallUnike--;
      j++;
    }
    i = j;
    j = i+1;
  }

  i = 0;
  j = 0;
  while(i < n){
    while(a[j] == 0){
      j++;
    }
    a[i] = a[j];
    a[j] = 0;
    i++;
  }
  return antallUnike;
}

// not optimal?
void roterArray(int a[], const int start, const int end) {
  for(int i = start;i < end; i++) {
    a[start] = a[start+1];
  }
}
int fjernDuplikater2(int a[],const int n) {
  int antallUnike = n;
  if(n != 0){
    for(int i = 1;i < n;i++ ){
      if(a[i] == a[i+1]){
        antallUnike--;
        roterArray(a, i+1, n);
      }
    }
  }
  return antallUnike;
} 

// etter eksamens tiden så på løsningen til frode.
int fjernDuplikaterFrode(int a[] , const int n) {
  int antallUnike = 0;
  if(n <= 1) {
    return n;
  }
  for(int i = 1; i <=n;i++){
    if(a[i-1] != a[i]) {
      antallUnike++;
      a[antallUnike] = a[i];
    }
  }
  for(int i = antallUnike +1 ; i <= n; i++){
    a[i] = 0;
  }
  return antallUnike;
}

int fjernDuplikater3(int a[], const int n) {
  if(n != 0){
    return 0;
  }
  int antallUnike = 1;
  for(int i = 1 ; i < n; i++) {
    if(a[i] != a[i+1]) {
      antallUnike++;
    } else {
      a[i+1] = a[antallUnike];
    }
  }
  return antallUnike;
}
