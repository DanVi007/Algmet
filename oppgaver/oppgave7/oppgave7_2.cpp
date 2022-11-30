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

int groupNumber;
int groupAmount;

void gatherGroup(int x,int y){
  if(board[x][y] && board[x][y] != 2 
    && x >= 0 && x < N && y >= 0 && y < N) {
    groupAmount++;
    board[x][y] = 2;
    cout << "   cord: " << x << " , " << y << endl;
    gatherGroup(x-1,y);
    gatherGroup(x+1,y);
    gatherGroup(x,y+1);
    gatherGroup(x,y-1);
  }

}

void loopThroughBoard() {
  for(int y = 0; y < N;y++) {
    for(int x = 0; x < N;x++) {
      if(board[x][y] && board[x][y] != 2 ) {
        groupNumber++;
        cout << "Group number " << groupNumber << endl;
        gatherGroup(x,y);
        cout << "   Group amount: " << groupAmount << endl;
        groupAmount = 0;
      }
    }
  }
}

void init(){
  groupAmount = 0;
  groupNumber = 0;
}

int main(){
  buildBoard();
  printBoard();
  loopThroughBoard();
  printBoard();
  return 0;
}
