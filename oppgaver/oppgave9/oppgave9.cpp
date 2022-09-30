#include <iostream>

using namespace std;

const int N = 10 ;

int row[N];

void buildRow(){
    for(int i = 0; i < N;i++){
        row[i] = i +1;
    }
}

void display(const int row[]){
    for(int i = 0 ; i < sizeof(row)/sizeof(int); i++){
        cout <<  row[i] << " ";
    }
    cout << endl; 
}

void permutateClass(int row[] , int indexToChange, int lastIndex){
   if(indexToChange == lastIndex -1){
    display(row); 
   } else {
    

   } 

}

int main(){
    buildRow();

    return 0;
}