#include <iostream> //  cout
#include <string>   //  string
#include <vector>
#include <set>
using namespace std;
class DiagonalLine
{
public:
    int start;
    int slope;

    DiagonalLine(int pStart, int pSlope)
    {
        start = pStart;
        slope = pSlope;
    }
};

int amountOfSolutions = 0;

/**
 * a is depth 0, b is depth 1 ...
 */
void miniMax(vector<int> takenHorizontals, vector<DiagonalLine> takenDiagonals, int depth)
{
    // TODO: modify to take in range like thingy, so that you dont have to change the numbers for other n*n chess boards
    // set<int> availablePositions = {1, 2, 3, 4, 5, 6, 7, 8,9,10,11,12,13};
    set<int> availablePositions = {1, 2, 3, 4, 5, 6, 7, 8};
     //set<int> availablePositions = {1, 2, 3, 4,5,6};

    int endDepth = 8;
    // int endDepth = 4;

    for (int i : takenHorizontals)
    {
        availablePositions.erase(i);
    }

    for (DiagonalLine d : takenDiagonals)
    {
        availablePositions.erase(d.start + d.slope * depth);
    }

    if (availablePositions.empty() && depth == endDepth)
    {
        for (int i : takenHorizontals)
        {
            cout << i << " , ";
        }
        cout << "\n--------------------\n";
        amountOfSolutions++;
    }
    else if (!availablePositions.empty())
    {
        for (int i : availablePositions)
        {
            vector<int> mTakenHorizontals = takenHorizontals;
            vector<DiagonalLine> mTakenDiagonals = takenDiagonals;
            mTakenHorizontals.push_back(i);
            mTakenDiagonals.push_back(DiagonalLine(i + depth, -1));
            mTakenDiagonals.push_back(DiagonalLine(i - depth, 1));
            miniMax(mTakenHorizontals, mTakenDiagonals, depth + 1);
        }
    }
}

int main()
{
    vector<int> startHorizontal = {};
    vector<DiagonalLine> startDiagonal = {};
    miniMax(startHorizontal, startDiagonal, 0);

    cout << amountOfSolutions << endl;
    return 0;
};