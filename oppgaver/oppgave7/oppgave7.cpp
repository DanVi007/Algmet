#include <iostream> //  cout
#include <vector>
using namespace std;
const int N = 10;

int board[N][N] = {};

struct Position
{
    int xCord;
    int yCord;

    Position(int x, int y)
    {
        xCord = x;
        yCord = y;
    }
};

struct Group
{
    vector<Position *> positions;
};

vector<Group*> groups;

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

void printBoard()
{
    for (int y = N - 1; y >= 0; y--)
    {
        for (int x = 0; x < N; x++)
        {
            // cout << board[x][y] << " | ";
            cout << board[x][y] << " , ";
        }
        cout << "\n";
        // cout << "---------------------------------------";
        // cout << "\n";
    }
}


bool nextToInPosition(int i, int j, Position* position){
   Position positionToCheck = *position; 
    if (
        (i + 1 == positionToCheck.xCord && j == positionToCheck.yCord) ||
        (i - 1 == positionToCheck.xCord && j == positionToCheck.yCord) ||
        (i == positionToCheck.xCord && j + 1 == positionToCheck.yCord) ||
        (i == positionToCheck.xCord && j - 1 == positionToCheck.yCord))
    {
        return true;
    }
    return false;
 
}
/*
bool nextToInPosition(int i, int j)
{

    if (
        board[i + 1][j] ||
        board[i - 1][j] ||
        board[i ][j+1 ] ||
        board[i ][j-1] 

    ){
        return true;
    }
    return false;
    
    if (
        (i + 1 == positionToCheck.xCord && j == positionToCheck.yCord) ||
        (i - 1 == positionToCheck.xCord && j == positionToCheck.yCord) ||
        (i == positionToCheck.xCord && j + 1 == positionToCheck.yCord) ||
        (i == positionToCheck.xCord && j - 1 == positionToCheck.yCord))
    {
        return true;
    }
    return false;
    
}
*/
bool putInGroupIfBelongs(int i,int j, Group* group){
   for(Position* position : group->positions) {
       if(nextToInPosition(i,j,position)){
            Position* newPosition = new Position(i,j);
          group->positions.push_back(newPosition);
          return true; 
       } 
   }
   return false;
}

bool checkInGroup(int i, int j)
{
    bool inGroup = false;
    for (Group* group : groups)
    {
      if(putInGroupIfBelongs(i,j,group)){
        inGroup = true;
      }
    }
    return inGroup;
}

void findGroup()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if(board[x][y]== 1) {
                if(!checkInGroup(x,y)){
                    Group* group = new Group;
                    Position* newPosition = new Position(x,y);
                    group->positions.push_back(newPosition); 
                    groups.push_back(group);
                }
            board[x][y] = 2;
            }

/*
            if (board[x][y] == 1)
            {
                if (!checkInGroup(x, y))
                {
                    vector<Position> newGroup;
                    newGroup.push_back(Position(x, y));

                    groups.push_back(newGroup);
                }
            }
            */
        }
    }
}
int main()
{
    buildBoard();
    // printBoard();

    // groupToAdd.insert(new Position(1,1));
    findGroup();
    for (Group* group : groups)
    {
        cout << "Group : \n";
        for (Position* position : group->positions)
        {
            cout << position->xCord << " , " << position->yCord << "\n";
        }
    }

    return 0;
}