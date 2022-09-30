#include <iostream>

using namespace std;

const int N = 10 ;

int row[N];

void buildRow(){
    for(int i = 0; i < N;i++){
        row[i] = i +1;
    }
}

void permutateClass(){

}

int main(){
    buildRow();

    return 0;
}