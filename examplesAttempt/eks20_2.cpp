#include <iostream> 

const int endXindex = 3;
const int endYindex= 3;
const int N = 4;
int availableNumbers[N*N];
const int maxNumber = 34;

int board[N][N];

// int sumRightDiagonal = 0;
// int sumLeftDiagonal = 0;
int sumHorizontal = 0;
// int sumVertical = 0;

void printAllPermutations(int startIndex){
  int xIndex = startIndex % N; 
  int yIndex = startIndex / N;

  for(int i = startIndex; i < N*N; i++){

    // checking for availableNumbers
    for(int j = 0; j < N*N; j++){
      if(availableNumbers[j] != 0){
        int numberToPut = availableNumbers[j];
        sumHorizontal += numberToPut;

        bool valid = true;
        if(sumHorizontal > maxNumber){
          valid = false;
        }
        if(yIndex == endYindex) {
          if((board[xIndex][0] + board[xIndex][1] + board[xIndex][2] 
                + numberToPut) != maxNumber){
            valid = false;
          } 

          if(xIndex == 0 && 
              (board[3][0] + board[3][0] + 
               board[3][0] + numberToPut) != maxNumber {

          }


        }
        if(valid) {
          availableNumbers[j] = 0;
          board[xIndex][yIndex] = numberToPut;
          printAllPermutations(startIndex+1);

          // backtrack
          board[xIndex][yIndex] = 0;
          availableNumbers[j] = numberToPut;
        }
        sumHorizontal -= numberToPut;
      }

    }

  }


}

void initAvailableNumbers(){
  for(int i = 0;i < N*N;i++) {
    availableNumbers[i] = i+1;
  }

}


int main(){
  initAvailableNumbers();
  availableNumbers[0] = 0;
  board[0][0] = 1;
  printAllPermutations(1);

  return 0;

}
