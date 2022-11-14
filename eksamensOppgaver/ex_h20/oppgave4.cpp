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
