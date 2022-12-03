#include <fstream>
#include <iostream>

using namespace std;

//siden 9*9 = 81
int brett[9][9] = {};

void initBoard(){
  brett[0][0] = 5;
}

void settFunnetTall(const int x , const int y,bool gyldigeTall[]) {
  if(brett[x][y] != 0) {
    gyldigeTall[brett[x][y]] = false;
  } 
}

void printBrett(){
  cout << "Losning" << endl;
  for(int y = 0; y < 9; y++) {
    for(int x = 0; x <  9; x++) {
      cout << brett[x][y] << " , ";
    }
    cout << endl;
  }
  cout << endl;
}

void finnLosning(const int n){
  int y = n/9;
  int x = n %9;
  if(n == 82) {
    printBrett();
  } else if(brett[x][y] == 0) {
    bool gyldigeTall[10] = {false,true,true,true,true,true,true,true,true,true};

    //horisontal
    for(int i = 0; i < 9; i++){
      settFunnetTall(i,y,gyldigeTall);
    }

    // vertikal
    for(int i = 0; i < 9;i++) {
      settFunnetTall(x,i,gyldigeTall);
    }

    // i boks
    int xPosisjonIboks = x%3;
    int yPosisjonIboks = y%3;
    int xSomSjekkes[2] = {} ;
    int ySomSjekkes[2] = {} ;


    switch (xPosisjonIboks) {
      case 0: xSomSjekkes[0] = 1; xSomSjekkes[1] = 2; break; 
      case 1: xSomSjekkes[0] = 0; xSomSjekkes[1] = 2; break;
      case 2: xSomSjekkes[0] = 0; xSomSjekkes[1] = 1; break;
    }

    switch (yPosisjonIboks) {
      case 0: ySomSjekkes[0] = 1; ySomSjekkes[1] = 2; break;
      case 1: ySomSjekkes[0] = 0; ySomSjekkes[1] = 2; break;
      case 2: ySomSjekkes[0] = 0; ySomSjekkes[1] = 1; break;
    }
    // int ekteXposisjon = x-xPosisjonIboks + xSomSjekkes[0];
    // int ekteYposisjon =  y-yPosisjonIboks + ySomSjekkes[0];
    // ekteXposisjon = x-xPosisjonIboks + xSomSjekkes[1];
    // ekteYposisjon =  y-yPosisjonIboks + ySomSjekkes[1]; 
    // settFunnetTall(ekteXposisjon,ekteYposisjon,gyldigeTall);
    // settFunnetTall(ekteXposisjon,ekteYposisjon,gyldigeTall);
    //
    settFunnetTall(x-xPosisjonIboks + xSomSjekkes[0], y-yPosisjonIboks + ySomSjekkes[0],gyldigeTall);
    settFunnetTall(x-xPosisjonIboks + xSomSjekkes[0], y-yPosisjonIboks + ySomSjekkes[1],gyldigeTall);
    settFunnetTall(x-xPosisjonIboks + xSomSjekkes[1], y-yPosisjonIboks + ySomSjekkes[0],gyldigeTall);
    settFunnetTall(x-xPosisjonIboks + xSomSjekkes[1], y-yPosisjonIboks + ySomSjekkes[1],gyldigeTall);

    for(int i = 1; i < 10; i++){
      if(gyldigeTall[i]){
        brett[x][y] = i;
        finnLosning(n+1) ;
        brett[x][y] = 0;
      }
    }
  } else  {
    finnLosning(n+1);
  }


}
const int ANTX   = 9, ANTY = 9,  ///<  Brettets dimensjoner/størrelse.
          N      = ANTX*ANTY,    ///<  Totalt antall ruter på brettet.
          STRLEN = 80;           ///<  "-----------"-linje fra/på filen.
/**
 *  Leser inn HELE det INITIELLE brettet fra fil.
 */
void lesFraFil()  {
//  ifstream innfil("eks_40_SUDOKU.dta");
  ifstream innfil("case1_data.dta");
  int i, j;
  char dummy;               //  For å lese inn/skippe '|' mellom 9x9-rutene.
  char buffer[STRLEN];      //  For å lese inn/skippe "-------------"-linje.

  if (innfil)  {            //  Filen finnes:
   cout << "\n\nLeser fra filen 'EKS_40_SUDOKU.DTA' .....\n";
   for (i = 0;  i < ANTX;  i++)  {
      for (j = 0;  j < ANTY;  j+=3) {        //  Leser 3 og 3 tall ad gangen:
        innfil >> brett[i][j] >> brett[i][j+1] >> brett[i][j+2];
        if (j+2 < ANTY-1) innfil >> dummy;   //  Skipper '|' inne på brettet.
      }
      innfil.ignore();                       //  Skipper prikket linje:
      if ((i==2  ||  i==5)) innfil.getline(buffer, STRLEN);
   }
  } else
    cout << "\n\n\tFant ikke filen 'EKS_40_SUDOKU.DTA'!\n\n";
}
int main(){
  lesFraFil();

  finnLosning(0);
  return 0;
}


