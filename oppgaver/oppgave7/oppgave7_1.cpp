#include <iostream> //  cout
#include <vector>
#include <utility>
using namespace std;
const int N = 10;

int board[N][N] = {};
vector<pair<int, int>> tempGroup;
vector<vector<pair<int, int>>> groups;
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
            cout << board[x][y] << " , ";
        }
        cout << "\n";
    }
}
void visit(int i, int j)
{
    board[i][j] = 2;
    tempGroup.push_back(pair<int, int>(i, j));
}

void groupNodes(int nextI, int nextJ)
{
    int i = nextI;
    int j = nextJ;

    if (board[i][j] != 0)
    {
        visit(i, j);

        if (board[i][j + 1] == 1)
        {
            groupNodes(i, j + 1);
        }
        if (board[i + 1][j] == 1)
        {
            groupNodes(i + 1, j);
        }
        if (board[i][j - 1] == 1)
        {
            groupNodes(i, j - 1);
        }
        if (board[i - 1][j] == 1)
        {
            groupNodes(i - 1, j);
        }
    }
}
void gatherGroups()
{

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (board[x][y] == 1)
            {
                groupNodes(x, y);
                groups.push_back(tempGroup);
                tempGroup.clear();
            }
        }
    }
}

int main()
{
    buildBoard();
    printBoard();
    cout << "\n-------------------------------------\n";
    gatherGroups();

    cout << "\n-------------------------------------\n";
    cout << "\nTotal amount of groups: " << groups.size();

    cout << "\n-------------------------------------\n";

    for (int i = 1; i <= groups.size(); i++)
    {
        cout << "Group : " << i << "\n";
        for (pair<int, int> cord : groups[i - 1])
        {
            cout << cord.first << " , " << cord.second << "\n";
        }
    }
    cout << "\n-------------------------------------\n";
    printBoard();
    return 0;
}
