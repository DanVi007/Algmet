#include <iostream>

using namespace std;

const int N = 4;
const int maxNumber = 34;

int board[N][N] = {{}};
//int availableNumbers [N*N];
bool availableNumbers[N*N] = {true, true, true, true, true, true,
                              true, true, true, true, true, true,
                              true , true,true , true };
int solutionCounter = 0;

void printBoard()
{
  for (int y = 0; y < N; y++)
    {
      for (int x = 0; x < N; x++)
        {
          cout << board[x][y] << " , ";
        }
      cout << endl;
    }
  cout << "------------" << endl;
}

int sumHorizontal[N] = {}; // sum of the Horizontal rows, index is yIndex
int sumVerticals[N] = {}; // sum of the vertical rows , index is xIndex

int sumDiagonals[2] = {}; //index 0 represents top left to right.
                          // index 1 represents top right to left

/**
* checks whether the numberToPut will be correct to xIndex and yIndex.
*/
bool checkValidNumber(int numberToPut, int xIndex,int yIndex,
                      int diagonalDirection) {
  if((yIndex == N -1 && sumVerticals[xIndex] != maxNumber ) || //vertical and
    (xIndex == N-1 && sumHorizontal[yIndex] != maxNumber))    //Horizontal. 
    return false;
  
  if((sumVerticals[xIndex] > maxNumber || sumHorizontal[yIndex] > maxNumber ))
    return false;
   
  if(diagonalDirection != 3){ // checks diagonals
    if(((xIndex == 0 && yIndex == N-1) || 
      (xIndex == N-1 && yIndex == N-1)) && 
      sumDiagonals[diagonalDirection] != maxNumber){
      return false;
    }
    if(sumDiagonals[diagonalDirection] > maxNumber)
      return false;
  }

  return true;
}

void printAllPermutations(int startIndex){
  int xIndex = startIndex % N;
  int yIndex = startIndex / N;
  if (startIndex == N * N) // solution found
  {
    solutionCounter++;
    //printBoard();
    return;
  }

  // checking for availableNumbers
  for (int j = 0; j < N * N; j++)
    {
      if (availableNumbers[j]) // availableNumber found
      {
        int numberToPut = j+1; // sets the number to their sums  
        sumHorizontal[yIndex] += numberToPut;
        sumVerticals[xIndex] += numberToPut;
        int diagonalDirection = 3;  
        if( xIndex== yIndex) //left right diagonal has the same x,y index
          diagonalDirection = 0;
        else if(xIndex +yIndex == N-1) //right left has their sum = N-1
          diagonalDirection = 1;
        
        if(diagonalDirection != 3 )
          sumDiagonals[diagonalDirection] += numberToPut;
        

        if (checkValidNumber(numberToPut,xIndex,yIndex,diagonalDirection))
        {
          availableNumbers[j] = false;
          board[xIndex][yIndex] = numberToPut;
          printAllPermutations(startIndex + 1);

          // backtrack
          board[xIndex][yIndex] = 0;
          availableNumbers[j] = true;
        }

        //backtrack
        sumHorizontal[yIndex] -= numberToPut;
        sumVerticals[xIndex] -= numberToPut;
        if(diagonalDirection != 3 )
          sumDiagonals[diagonalDirection] -= numberToPut;

      }
    }
}




int main(){
  printAllPermutations(0);
  cout << solutionCounter << endl;
  return 0;
}
