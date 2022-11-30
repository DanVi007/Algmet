/*
* oppgave 7_2 after looking at frode's solution
*/
#include <iostream>

using namespace std;

const int N = 10; 

int board[N][N] = {}; 

void buildBoard()
{
    board[1][1] = 1;
    board[1][2] = 1;
    board[2][1] = 1;
    board[2][2] = 1;
    board[3][5] = 1;
    board[3][8] = 1;
    board[4][8] = 1;
    board[4][6] = 1;
    board[4][3] = 1;
    board[5][3] = 1;
    board[7][0] = 1;
    board[7][4] = 1;
    board[7][5] = 1;
    board[7][6] = 1;
    board[8][0] = 1;
    board[8][1] = 1;
    board[8][4] = 1;
    board[9][8] = 1;
    board[9][9] = 1;
}


void printBoard(){
  cout << endl 
    << "  -------------------------------------" 
    << endl;
  for(int y = N-1; y >= 0;y--) {
    for(int x = 0; x < N; x++) {
      if(!board[x][y]){
        cout<< " ";
      } else {
        cout << board[x][y];
      }
      cout << " | ";
    }
    cout << endl 
      << "  -------------------------------------" 
      << endl;
  }
  
}


void gatherGroup(int x,int y, int & groupAmount){
  if(board[x][y] == 1
    && x >= 0 && x < N && y >= 0 && y < N) {
    groupAmount++;
    board[x][y] = 2;
    cout << "   cord: " << x << " , " << y << endl;
    gatherGroup(x-1,y,groupAmount);
    gatherGroup(x+1,y,groupAmount);
    gatherGroup(x,y+1,groupAmount);
    gatherGroup(x,y-1,groupAmount);
  }
}

void loopThroughBoard() {
  int groupNumber = 0;
  int groupAmount = 0;
  for(int y = 0; y < N;y++) {
    for(int x = 0; x < N;x++) {
      if(board[x][y] == 1 ) {
        groupNumber++;
        cout << "Group number " << groupNumber << endl;
        gatherGroup(x,y,groupAmount);
        cout << "   Group amount: " << groupAmount << endl;
        groupAmount = 0;
      }
    }
  }
}


int main(){
  buildBoard();
  printBoard();
  loopThroughBoard();
  printBoard();
  return 0;
}
