#include <iostream>

using namespace std;

void roterVenstre(int a[] ,const int startIndex, const int endIndex) {
  int temp = a[startIndex];
  for(int i = startIndex ; i < endIndex;i++) {
    a[i] = a[i+1]; 
  }
  a[endIndex] = temp; 
}

int main(){
  const int N = 10; 

  int a[N] = {1,2,3,4,5,6,7,8,9,10};

  roterVenstre(a,5,8);
  for(int i = 0; i< N ;i++) {
    cout << a[i] << " , ";
  }
  cout << endl;
  return 0;
}


