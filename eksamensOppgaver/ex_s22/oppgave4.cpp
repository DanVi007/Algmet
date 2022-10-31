#include <iostream> 
#include <random>
#include <fstream>
#include <iomanip>
using namespace std;

int tallene[1000000] ;

void skrivSum(){
    int tallHittil = tallene[0];
    int totalSum = tallHittil;
    int antallTall = 1;
    for(int i = 1; i < 1000000; i++) {
        if(tallene[i] >= tallHittil ) {
            tallHittil = tallene[i];
            totalSum += tallHittil;
            antallTall++;
        }
    }
    cout << "Totalsum: " << totalSum << endl;
    cout << "Antall summert: " << antallTall << endl;
}
// test

void skrivSumTest(int testArray[], int storelse){
    int totalSum = testArray[0];
    int tallHittil = testArray[0];
    int antallTall = 1;
    for(int i = 1; i < storelse; i++) {
        if(testArray[i] >= tallHittil ) {
            totalSum += testArray[i];
            tallHittil = testArray[i];
            antallTall++;
        }
    }
    cout << "Totalsum: " << totalSum << endl;
    cout << "Antall summert: " << antallTall << endl;
}
// test

void genererTallene(int tallArray[], int storelse) {
    random_device rd; 
    mt19937 mt(rd());
    uniform_int_distribution dist(0,10);

    for(int i = 0; i < storelse;i++){
        tallArray[i] = dist(mt);
   }

}

void skrivTalleneFor(int tallArray[],int storelse ){
    for(int i = 0; i < storelse;i++){
        cout << tallArray[i] << " , ";
   }
   cout << endl;

}

int main() {

    const int testStorelse = 20;
    int testTall[testStorelse];
    genererTallene(testTall, testStorelse);
    skrivTalleneFor(testTall,testStorelse);
    skrivSumTest(testTall,20);

    // test frode
   ifstream innfil("losninger/ex_s22_4.dta");      //  Åpner aktuell vil med
   int tall;                                      //    1 million tall.
   int i = 0;
   if (innfil)  {                        //  Filen finnes.
      innfil >> tall;                    //  Leser (om mulig) ETT tall.
      while (!innfil.eof())  {           //  Ennå ikke nådd filslutt:
        tallene[i++] = tall;             //  Lagrer unna innlest tall.
        innfil >> tall;                  //  Leser (om mulig) NESTE tall.
      }
   } else                                //  Filen lot seg ikke finne/åpne:
     cout << "\n\nFant ikke filen 'EX_S22_4.DTA'!\n\n";

   
   skrivSum();

    
    return 0;
}
