#include <iostream> //  cout
#include <utility>
using namespace std;

const int N = 4;
const int maxNumber = 34;

// this is necessary because of:
// https://stackoverflow.com/questions/1164266/why-are-arrays-of-references-illegal
struct Board
{
    int array[N][N] = {};
    /*
    void insert(int x,int y, int number){
        array[x][y] = number;
    }
    */
};

int startingPosition[N][N];

void generateStartingPosition()
{
    int counter = N * N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            startingPosition[x][y] = counter;
            counter--;
        }
    }
}
void display(Board board)
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << board.array[x][y] << " , ";
        }
        cout << endl;
    }
}

bool checkLine(int array[N])
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        counter += array[i];
        if (counter >= maxNumber)
        {
            return false;
        }
    }
    return true;
}

void swap(int x1, int y1, int x2, int y2, Board &board)
{
    int temp = board.array[x1][y1];
    board.array[x1][y1] = board.array[x2][y2];
    board.array[x2][y2] = temp;
}
//https://www.geeksforgeeks.org/pair-in-cpp-stl/
pair<int, int> translateIndexToCord(int index)
{
    return pair<int,int> PAIR(index %N, (int)index /N );


}

void printAllPermutations(Board board, int startingIndex, int endIndex)
{
    if (startingIndex == endIndex)
    {
        display(board);
    }
    else
    {
        for (int i = startingIndex; i <= endIndex; i++)
        {
        }
    }
}

int main()
{
    Board testBoard;
    testBoard.array[0][1] = 5;
    testBoard.array[3][1] = 5;
    display(testBoard);

    return 0;
}