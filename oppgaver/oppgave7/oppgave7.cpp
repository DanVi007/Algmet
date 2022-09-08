#include <iostream> //  cout
#include <vector>
using namespace std;
const int N = 10;

int board[N][N] = {};

vector<int[2]> groups;

struct Position{
    int xCord;
    int yCord;

    Position(int x, int y){
        xCord = x;
        yCord = y;
    }
    


};

void buildBoard(){
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
    for(int y = N-1; y>= 0;y--){
        for(int x = 0; x< N;x++){
            //cout << board[x][y] << " | ";
            cout << board[x][y] << " , ";
        }
        cout << "\n";
        //cout << "---------------------------------------";
        //cout << "\n";

    }

}


/*
void findGroup(int i, int j,vector<int[2]> group){
    if(board[i][j] == 1){
        for(int cord[2] : group){
            if((i +1 == cord[0] || i -1 == cord[0] ) 
            && (j+i == cord[1] || j-1 == cord[1])){
                group.insert([i,j]);
            }
        }
    }
}
*/



int main(){
    buildBoard();
    //printBoard();
    vector<Position> groupToAdd;
       
    groupToAdd.push_back(Position(1,2));
    //groupToAdd.insert(new Position(1,1));

    
    //findGroup(1,1,groupToAdd);

    for(Position cord: groupToAdd){
        cout << cord;
    }
    

    return 0;

}