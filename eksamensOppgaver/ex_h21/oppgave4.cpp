#include <iostream>

using namespace std;

void flettToSorterteArrayer(int a[], const int b[],
                            const int aLen, const int bLen){
  //setter b på tomme plasser i a
  int i = 0;
  for(int j = 0; j < bLen; j++) {
    while(i < aLen && a[i] != 0 ) i++;
    a[i] = b[j];
  }

  // sorterer arrayen a igjen med selection sort
  for(int i = 0; i < aLen;i++){
    int minimumFunnet = a[i];
    int minimumIndeks = i;
    for(int j = i +1; j < aLen; j++){
      if(a[j] < minimumFunnet){
        minimumFunnet = a[j];
        minimumIndeks = j;
      }
    }
    a[minimumIndeks] = a[i];
    a[i] = minimumFunnet;
  }

}

void flettToSorterteArrayer2(int a[], const int b[],
                            const int aLen, const int bLen){
  int aIndeks, bIndeks = 0;
  while(bIndeks< bLen){
    while(b[bIndeks] > a[aIndeks]) {
      aIndeks++;
    }

    int temp = b[bIndeks];
    int i = aIndeks;

    while(a[i] != 0 && i < aLen ) {
      int temp2 = a[i];
      a[i] = temp;
      temp = temp2;
      i++;
    }
    bIndeks++;
  }
}

void flettToSorterteArrayer3(int a[], const int b[],
                            const int aLen, const int bLen){
  int aIndeks  =0;
  int bIndeks  =0;
  int funnetNull = 0;


  while(bIndeks < bLen){
    funnetNull = 0;
    while(b[bIndeks] > a[aIndeks]) aIndeks++;
    while(a[funnetNull] != 0) funnetNull++;

    bool rotertFerdig = false;
    int retning = (funnetNull > aIndeks) ? -1 : 1;

    while(!rotertFerdig) {
      a[funnetNull] = a[funnetNull + retning];
      funnetNull += retning;
      if(funnetNull == aIndeks) rotertFerdig = true;
    }
    a[aIndeks] = b[bIndeks];
    bIndeks++;
  }
}

//så på fasit etter dette punktet
void flettToSorterteArrayer4(int a[], const int b[],
                            const int aLen, const int bLen){
  int aIndeks, bIndeks,forsteReelIndeks;
  aIndeks = bIndeks = 0;
  forsteReelIndeks = aLen-1;
  for(int i = aLen-1; i >= 0;i--){
    if(a[i] != 0 ) {
      a[forsteReelIndeks] = a[i];
      forsteReelIndeks--;
    }
  }

  while(aIndeks < aLen && bIndeks < bLen){
    if(a[forsteReelIndeks+1] < b[bIndeks]){
      a[aIndeks] = a[forsteReelIndeks +1 ];
      forsteReelIndeks++;
    } else {
      a[aIndeks] = b[bIndeks];
      bIndeks++;
    }
    aIndeks++;
  }
}

int main(){
  int a[15] = {-8,-4,0,0,-1,3,0,7,0,9,11,0,0,15,19};
  int b[6] = {-10,-3,-1,4,9,24};

  for(int i= 0;i < 15; i++) {
    cout << a[i] << " , "; 
  }
  cout << endl;

  flettToSorterteArrayer4(a,b,15,6);


  for(int i= 0;i < 15; i++) {
    cout << a[i] << " , "; 
  }
  cout << endl;

  return 0;
}

