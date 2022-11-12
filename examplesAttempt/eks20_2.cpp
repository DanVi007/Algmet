#include <iostream>

using namespace std;

const int endXindex = 3;
const int endYindex = 3;
const int N = 4;
int availableNumbers[N * N];
const int maxNumber = 34;

int solutionCounter = 0;

//int board[N][N] = {{1,2,15,16},{13,14,3,4},{12,7,10,5},{8,11,6,0}};
int board[N][N];

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

// int sumRightDiagonal = 0;
// int sumLeftDiagonal = 0;
int sumHorizontal = 0;
// int sumVertical = 0;

void printAllPermutations(int startIndex)
{
  int xIndex = startIndex % N;
  int yIndex = startIndex / N;
  // printBoard();
  // cout << "----------" << endl;
  // cout << "sum: " << sumHorizontal << endl;
  // cout << "startIndex:" << startIndex << endl;
  // cout << "x , y " << xIndex << " , " << yIndex << endl;

  if (xIndex == 0)
  {
    sumHorizontal = 0;
    // printBoard();
    // cout << "--------------" << endl;
    // cout << startIndex << endl;
  }
  if (startIndex == N * N)
  {
    //printBoard();
    solutionCounter++;
    return;
  }

  // checking for availableNumbers
  int localSumHorizontal = sumHorizontal;
  for (int j = 0; j < N * N; j++)
  {
    if (availableNumbers[j] != 0)
    {
      int numberToPut = availableNumbers[j];
      sumHorizontal += numberToPut;

      bool valid = true;
      if (sumHorizontal > maxNumber)
      {
        valid = false;
      }
      // TODO: SHORTEN
      if (yIndex == endYindex)
      {
        // checks vertical
        if ((board[xIndex][0] + board[xIndex][1] + board[xIndex][2] + numberToPut) != maxNumber)
        {
          valid = false;
        }
        else if (xIndex == 0 && 
                 (board[3][0] + board[2][1] +
                  board[1][2] + numberToPut) != maxNumber) //checks diagonal right to left 
        {
          valid = false;
        }
        else if (xIndex == endXindex &&
                 (board[0][0] + board[1][1] +
                  board[2][2] + numberToPut) != maxNumber) //checks diagonal left to right 
        {
          valid = false;
        }
      }

      if (xIndex == endXindex && sumHorizontal != maxNumber)
      {
        valid = false;
      }
      if (valid)
      {
        availableNumbers[j] = 0;
        board[xIndex][yIndex] = numberToPut;
        printAllPermutations(startIndex + 1);

        // backtrack
        board[xIndex][yIndex] = 0;
        availableNumbers[j] = numberToPut;
      }
      if(sumHorizontal == 0){
        sumHorizontal = localSumHorizontal;
      } else {
        sumHorizontal -= numberToPut;
      }
    }
  }
}

void initAvailableNumbers()
{
  for (int i = 0; i < N * N; i++)
  {
    availableNumbers[i] = i + 1;
  }
}

void initAvailableNumbersTest(){
  availableNumbers[8] = 9;
}

int main()
{
  initAvailableNumbers();
  //initAvailableNumbersTest();
  /*
  availableNumbers[0] = 0;
  board[0][0] = 1;
  cout << "board before: " << endl;
  printBoard();
  sumHorizontal = 1;
  printAllPermutations(1);
  */
  //sumHorizontal = 25;
  //printAllPermutations(15);
  sumHorizontal = 0;
  printAllPermutations(0);
  cout << solutionCounter << endl;

  return 0;
}
