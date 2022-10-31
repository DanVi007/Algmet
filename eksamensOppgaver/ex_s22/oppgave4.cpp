#include <iostream> 
#include <random>
using namespace std;

int tallene[1000000] ;

void skrivSum(){
    int totalSum = 0;
    int tallHittil = tallene[0];
    int antallTall = 1;
    for(int i = 1; i < 1000000; i++) {
        if(tallene[i] >= tallHittil ) {
            totalSum += tallene[i];
            tallHittil = tallene[i];
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
    return 0;
}