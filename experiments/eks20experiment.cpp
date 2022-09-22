#include <iostream> //  cout
#include <utility>
using namespace std;

// const int N = 4;
const int N = 2;
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

Board generateStartingPosition()
{
    Board startingPosition;
    int counter = N * N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            startingPosition.array[x][y] = counter;
            counter--;
        }
    }
    return startingPosition;
}

Board startingPosition = generateStartingPosition();

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

// https://www.geeksforgeeks.org/pair-in-cpp-stl/
/*
pair<int, int> translateIndexToCord(int index)

{
    return pair<int,int> PAIR(index %N, (int)index /N );


}
*/
int counter = 0;
void printAllPermutations(Board board, int startingIndex, int endIndex)
{
    if (startingIndex == endIndex)
    {
        display(board);
        cout << "-----------" << endl;
        counter++;
    }
    else
    {
        for (int i = startingIndex; i <= endIndex; i++)
        {
            swap(i % N, (int)i / N,
                 startingIndex % N , (int)startingIndex / N, board);
            printAllPermutations(board, startingIndex + 1, endIndex);
            swap(startingIndex % N , (int)startingIndex / N,
                 i % N, (int)i / N, board);
        }
    }
}

int main()
{
    int startingIndex = 0;
    int endIndex = N * N - 1;
    for (int i = startingIndex; i <= endIndex; i++)
    {

        //       cout << "index " << i << endl;
        //       cout << (int)i / N << " , " ;
        //      cout << i % N << endl;
        //        cout << startingPosition.array[(int)i / N][i % N];
        //        cout << endl;
        //     cout << startingPosition.array[(int)startingIndex / N][startingIndex % N];
        //     cout << endl;
    }
    int i = 1; 

//    swap(i % N, (int)i / N,
//         startingIndex % N , (int)startingIndex / N, startingPosition);
    printAllPermutations(startingPosition, 0, N*N- 1);
    cout << counter << endl;

    return 0;
}