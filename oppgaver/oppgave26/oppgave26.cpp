#include <iostream>          //  cout
using namespace std;

const int N = 10;

int solutionCounter = 0 ;

int gNeighbour[N][N] = { 
 // Node nr: 0  1  2  3  4  5  6  7  8  9 Node nr:
           { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 }, // 0
           { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0 }, // 1
           { 1, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, // 2
           { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, // 3
           { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 }, // 4
           { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0 }, // 5
           { 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 }, // 6
           { 1, 0, 0, 0, 1, 1, 1, 0, 0, 1 }, // 7
           { 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 }, // 8
           { 0, 0, 0, 0, 1, 0, 1, 1, 1, 0 } }; // 9


int requirement[N]= {21,33,14,27,1,14,20,12,28,20} ; // index is id
// nodeArray is the mapping of reference number and id 
int nodeArray[N] = {0,1,2,3,4,5,6,7,8,9}; // index is reference , value is id  

/**
 * checks if the requirement is met. 
 * Only call this when its on the final permutation  
 */
bool requirementMet(){
    //  
    for(int i = 0; i < N; i++){
        int sumOfNeighbours = 0; 
        for(int j = 0; j < N; j++) {
            if(gNeighbour[i][j] != 0){
                sumOfNeighbours += nodeArray[j];
            }
        }
        if(sumOfNeighbours != requirement[nodeArray[i]]){
            return false;
        } 
    }
    return true;
}

void swap(int & firstNum, int & secondNum){
    int temp = firstNum; 
    firstNum = secondNum;
    secondNum = temp;
}

void rotateLeft(int arr[], const int i , const int n){
    int leftValue = arr[i]; 
    for(int k = i +1; k< n; k++){
        arr[k-1] = arr[k];
    }
    arr[n-1]= leftValue;
}

void display(){
    solutionCounter++;
    cout << "solution " << solutionCounter<< endl;
    int index = 0;
    for(int i : nodeArray){
        cout << "ref: " << index << " , id: " << i << endl;
        index++;
    }
    cout << "\n"; 
}


void permutateSolutions(int arr[],const int i, const int n) {
    //if(i == n-1 && requirementMet()){
    if(i == n-1 ){
        if(requirementMet()){
            display();
        }
    } else {
        permutateSolutions(arr, i +1, n); 
        for(int t = i +1;t < n;t++ ){
            swap(arr[i] ,arr[t]);
            permutateSolutions(arr, i+1 , n);
        }
        rotateLeft(arr,i,n);
    }

}

int main(int argc, char const *argv[])
{
    cout << "All solutions: " << endl; 
    permutateSolutions(nodeArray, 0,N);
    return 0;
}
