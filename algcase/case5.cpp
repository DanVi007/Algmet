#include<iostream>

using namespace std;

const int N = 3; // M > N, M og N må være positive heltall 
const int M = 5; // M > N, M og N må være positive heltall 

int gOnsker[N][3];
int gBesteFordeling[M]; //indeks er gjenstand -1. og verdi er nummer på person



/*
 * Tillegskriterier:
 *  dersom en person ikke får noen av sine onsker får han sum 4
 *
 *
 */

int gGjenstand[M]; //viser hvilke gjenstander som i øyeblikket er fordelt
                  //til hvilke personer. Indeks er gjenstand-1 og verdi er 
                  //nummer på person

int besteTotalPrioritet;

int totalPrioritetNaa;


void finnBesteFordeling(int person){
  if(person == 4){ // dersom det har nådd en ferdig permutering
    totalPrioritetNaa = 0; // resetter nåværende prioritet 
    for(int i = 0; i < M;i++) { // går gjennom gGjenstand
      int person = gGjenstand[i]; 
      if(person != 0){ // sjekker om en person var funnet 
        int onskeVerdi = 4; 
        for(int j= 0; j < 3;j++) {// finner ønske verdi til personen 
          if(gOnsker[person][j] == i+1 ){
            onskeVerdi = j+1;
          }
        }
        totalPrioritetNaa += onskeVerdi;
      }
    }

    if(totalPrioritetNaa < besteTotalPrioritet){
      besteTotalPrioritet = totalPrioritetNaa;
      for(int i = 0; i < M; i++) {
        gBesteFordeling = gGjenstand[i];
      }
    }
  } else {
    for(int i = 0; i < M; i++){
      if(gGjenstand[i] == 0){
        gGjenstand[i] = person;
        finnBesteFordeling(person++);
      }
      gGjenstand[i] = 0;
    }
  }
}


// TESTING
void nullStillVariabler(){
  besteTotalPrioritet = INT_MAX;
  totalPrioritetNaa = 0;
  gOnsker = {};
  gBesteFordeling = {};
}


int main() {


  return 0;
}
