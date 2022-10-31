#include <iostream> 
using namespace std;

int tallene[1000000] ;

void skrivSum(){
    int totalSum = 0;
    int tallHittil = tallene[0];
    int antallTall = 0;
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
int main() {
    skrivSum();
    return 0;
}