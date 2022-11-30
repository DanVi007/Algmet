/**
 *   Programeksempel nr 13 - Skriver linjer med ulikt antall stjerner/innrykk.
 *
 *   Eksempel som viser hvordan rekursivt skrive følgende/lage mønster:
 *
 *         *                        Dvs. ser vi dette ut fra 8-stjernene, 
 *         * *                      så skal det tegnes 4 stjerner startende
 *           *                      der 8'eren starter, og 4 stjerner fra
 *         * * * *                  midten av 8'eren.
 *             *                    For hver 4'er med stjerner, så skal det
 *             * *                  tegnes to stjerner der 4'eren starter,
 *               *                  og to stjerner fra midten av 4'eren.
 *         * * * * * * * *          For hver 2'er med stjerner, så skal det
 *                 *                tegnes en stjerne der 2'eren starter,
 *                 * *              og en stjerne fra midten av 2'eren
 *                   *              (der den altså slutter).
 *                 * * * *
 *                     *
 *                     * *
 *                       *
 *
 *   (Dette var oppg.nr.4 på eksamen 13/8-2001 i IMT2021-Algoritmiske metoder)
*/

#include <iostream>
using namespace std;
/**
* lager en rekursiv funksjon som traverserer inorder  
  */

void skrivStjerner(int antallStjerner,int antallTomme ){
  if(antallStjerner){
    skrivStjerner(antallStjerner/2,antallTomme) ;
    for(int i = 0; i < antallTomme;i++) {
      cout << "  ";
    }
    for(int i = 0; i < antallStjerner;i++) {
      cout << "* ";
    }
    cout << endl;
    skrivStjerner(antallStjerner/2,antallTomme+ antallStjerner/2) ;
  }
}

int main(){
  skrivStjerner(8,0) ;

  return 0;
}
