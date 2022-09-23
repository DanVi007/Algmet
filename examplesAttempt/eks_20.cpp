#include <iostream> //  cout
#include <utility>
#include <vector>
using namespace std;

// const int N = 4;
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

Board generateCorrectBoard(){
    Board correctPos;      

    int numbers[4][4] = {{16,15,2,1}, {4,3,14,13},{5,10,7,12},{9,6,11,8}};
    
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            correctPos.array[x][y] = numbers[x][y];
        }
    }
    return correctPos;
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
//TODO: REFACTOR
bool checkLine(vector<int> line)
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        counter += line[i];
        if(line.size() == N && counter == maxNumber){
            return true;
        }
        if (counter > maxNumber)
        {
            return false;
        }
    }
//TODO: use shorthand
    if(line.size() >= N){
        return false; 
    }
    return true;
}

bool checkBoard(Board board, int currentIndex)
{
    int x = currentIndex % N;
    int y = (int)currentIndex / N;

    bool correctSum = false;
    vector<int> line;
    // horizontal 
    for (int _x = 0; _x <= x; _x++)
    {
        line.push_back(board.array[_x][y]);
    }
    //vertical
    correctSum = checkLine(line);
    if (correctSum)
    {
        line.clear();
        for (int _y = 0; _y <= y; _y++)
        {
            line.push_back(board.array[x][_y]);
        }
        correctSum = checkLine(line);
    }
    // diagonal
   // todo: optimise 
    if (correctSum && (currentIndex ==5 || currentIndex == 10 || currentIndex
     == 15 ))
    {
        line.clear();
        for (int i = 0; i <= (int) currentIndex/N; i++)
        {
            line.push_back(board.array[i][i]);
        }
        correctSum = checkLine(line);
    }
    
    if (correctSum && (currentIndex ==6 || currentIndex == 9 || currentIndex
     == 12 ))
    {
        line.clear();
        for (int i = 0; i <= (int) currentIndex/N; i++)
        {
            line.push_back(board.array[i][i]);
        }
        correctSum = checkLine(line);
    }

    return correctSum;

    
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

void printAllPermutations(Board board, int startingIndex, int endIndex)
{
    if (startingIndex == endIndex)
    {
        display(board);
        cout << "-----------" << endl;
    }
    else
    {
        for (int i = startingIndex; i <= endIndex; i++)
        {
            swap(startingIndex % N, (int)startingIndex / N,
                 i % N, (int)i / N, board);

            printAllPermutations(board, startingIndex +1, endIndex);
            
            swap(i % N, (int)i / N,
                 startingIndex % N, (int)startingIndex / N, board);

        }
    }
}

int main()

{ 
    /*
    display(startingPosition);

    cout << "----------------" << endl;
    cout << "Permutations" << endl;
    printAllPermutations(startingPosition, 0, N * N - 1);

*/
    cout << "\n\n\nTESTS"; 
    /*
    for (int i = 0; i <= N*N -1; i++){
        cout << startingPosition.array[i%N][(int) i / N] << " , ";
    }
    */

    cout << endl;
    vector<int> numbers = {34};
    cout << checkLine(numbers) << endl;
    numbers = {35};

    cout << checkLine(numbers) << endl;

    numbers = {32};

    cout << checkLine(numbers) << endl;
    
    numbers = {1,2};
    cout << checkLine(numbers) << endl;
    
    numbers = {4,30};
    cout << checkLine(numbers) << endl;


    Board correctBoard = generateCorrectBoard();
    
    cout << checkBoard(correctBoard, 11) << endl; 
    
    cout << checkBoard(generateStartingPosition() , 15) << endl;

    return 0;
}