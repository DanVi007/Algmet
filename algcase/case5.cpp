#include<iostream>

using namespace std;

const int N = 3; // M > N, M og N må være positive heltall 
const int M = 5; // M > N, M og N må være positive heltall 

int gOnsker[N][3] = {{1,2,3} ,{1,2,3},{4,3,2}};
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

/*
 * 1. setter person til gGjenstand rekursivt. (permutering)
 *
 * 2. Dersom alle er satt blir det sjekket hva resultatet sammenlignet med 
 *    resultatet ble. Oppdaterer ettersom en bedre verdi er funnet.  
 *
 */
void finnBesteFordeling1(int person){
  // en permutering er nådd så gGjenstand blir sjekket 
  if(person == N+1){ // dersom det har nådd en ferdig permutering
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

    if(totalPrioritetNaa < besteTotalPrioritet){ // opdaterer 
      besteTotalPrioritet = totalPrioritetNaa;
      for(int i = 0; i < M; i++) {
        gBesteFordeling[i] = gGjenstand[i];
      }
    }
  } else {
    for(int i = 0; i < M; i++){
      if(gGjenstand[i] == 0){
        gGjenstand[i] = person;
        finnBesteFordeling1(person+1);
        gGjenstand[i] = 0; // backtracker
      }
    }
  }
}

bool ferdig = false;
/*
 * 1. setter person til gGjenstand rekursivt. (permutering)
 *
 * 2. Dersom alle er satt blir det sjekket hva resultatet sammenlignet med 
 *    resultatet ble. Oppdaterer ettersom en bedre verdi er funnet.  
 * very unfinished 
 *
 */
void finnBesteFordeling2(int person){
  // en permutering er nådd så gGjenstand blir sjekket 
  if(person == N+1){ // dersom det har nådd en ferdig permutering
    totalPrioritetNaa = 0; // resetter nåværende prioritet 
    if(totalPrioritetNaa < besteTotalPrioritet){ // opdaterer 
      besteTotalPrioritet = totalPrioritetNaa;
      for(int i = 0; i < M; i++) {
        gBesteFordeling[i] = gGjenstand[i];
      }
    }
  } else {
    for(int i = 0; i < M; i++){
      if(gGjenstand[i] == 0){
        gGjenstand[i] = person;
        for(int j = 0; j< 3;j++) {
          if(gOnsker[person][j] == i+1) {
            totalPrioritetNaa += j+1; 
          }

        }
        
        finnBesteFordeling2(person+1);
        gGjenstand[i] = 0; // backtracker
      }
    }
  }
}


// TESTING
void nullStillVariabler(){
  besteTotalPrioritet = INT_MAX;
  totalPrioritetNaa = 0;
  //gBesteFordeling
}

void printBestePrio(){
  cout << "Beste total prioritet " << endl;
  for(int i = 0;i < M; i++) {
    cout << "vare: " << i+1 << " , " << "eier: " << gBesteFordeling[i] << endl; 
  }
}

int main() {

  nullStillVariabler();
  finnBesteFordeling2(1);
  printBestePrio();
 cout << besteTotalPrioritet  << endl;

  return 0;
}
