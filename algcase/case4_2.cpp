#include <iostream>

using namespace std;

int snuOppNed(const int n ) {
  int endeTall = 0;
  int startTall = n;

  while(startTall > 0) {
    int tallSomSnus = startTall % 10;

    switch(tallSomSnus) {
      case 6: tallSomSnus = 9; break;
      case 9: tallSomSnus = 6; break;
      case 2: return 0; break;
      case 3: return 0; break;
      case 4: return 0; break;
      case 5: return 0; break;
      case 7: return 0; break;
    }
    endeTall = 10* endeTall + tallSomSnus;

    startTall /= 10;
  }
  return endeTall;
}

int main(){
  int teller = 0;
  for(int i = 1; i <= 100000;i++){
    if(snuOppNed(i) == i) {
      cout << i << endl;
      teller++;
    }
  }
  cout << "Antall: " << teller<< endl;
  return 0;
}

