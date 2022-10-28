#include <iostream> 
using namespace std;

int tallene[1000000] ;

void skrivSum(){
    int totalSum = 0;
    int tallHittil = tallene[0];
    for(int i = 1; i < 1000000; i++) {
        if(tallene[i] >= tallHittil ) {
            totalSum += tallene[i];
            tallHittil = tallene[i];
        }
    }
    cout << totalSum << endl;
}
int main() {
    skrivSum();
    return 0;
}