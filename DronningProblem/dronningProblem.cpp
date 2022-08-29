#include <iostream> //  cout
#include <string>   //  string
#include <vector>

#include <set>
using namespace std;

class Position
{
public:
    vector<int> availablePositions = {1, 2, 3, 4, 5, 6, 7, 8};
    int positionTaken;

    Position(int positonToBeTaken)
    {

        positionTaken = positonToBeTaken;
    }

    template <size_t N>
    Position(int (&notAvailablePos)[N]) // https://stackoverflow.com/questions/28653967/range-based-for-loop-throws-a-compiler-error-with-array-parameter
    {

        for (int a : notAvailablePos)
        {
            for (int b : availablePositions)
            {
                if (a == b)
                {
                    availablePositions[b];
                }
            }
        }
    }
};

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

/**
 * a is depth 0, b is depth 1 ...
 *
 *
 */
void miniMax(vector<int> takenHorizontals, vector<DiagonalLine> takenDiagonals, int depth)
{
    set<int> availablePositions = {1, 2, 3, 4, 5, 6, 7, 8};
    //set<int> availablePositions = {1, 2, 3, 4};

    int endDepth = 8;
    //int endDepth = 4;

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

            miniMax(mTakenHorizontals,mTakenDiagonals,depth +1);
        }
    }
}

int main()
{
    vector<int> startHorizontal = {};
    vector<DiagonalLine> startDiagonal = {};

    miniMax(startHorizontal,startDiagonal,0);

    return 0;

/*
    set<int> availablePositions = {1, 2, 3, 4, 5, 6, 7, 8};
    // cout << availablePositions.erase(1);

    vector<int> numbers = {1, 2, 3};

    numbers.push_back(6);
    */

    /*
        Position aPosition = Position(5);

        cout <<  aPosition.positionTaken << endl;
    */

    // cout << a << " , " << b << " , " << c << " , " << endl;

    /*
    set<int> allNumbers;

    allNumbers.insert(1);
    allNumbers.insert(2);
    allNumbers.insert(3);
    allNumbers.insert(4);
    allNumbers.insert(5);
    allNumbers.insert(6);
    allNumbers.insert(7);
    allNumbers.insert(8);

    for (int a = 1; a <= 8; a++)
    {
        set<int> availableNumbersA = allNumbers;
        availableNumbersA.erase(a);

        for (int b : availableNumbersA)
        {
            set<int> availableNumbersB = availableNumbersA;
            availableNumbersB.erase(b);

            for (int c : availableNumbersB)
            {
                set<int> availableNumbersC = availableNumbersB;
                availableNumbersC.erase(c);

                for (int d : availableNumbersC)
                {
                    set<int> availableNumbersD = availableNumbersC;
                    availableNumbersD.erase(d);

                    for (int e : availableNumbersD)
                    {
                        set<int> availableNumbersE = availableNumbersD;
                        availableNumbersE.erase(e);

                        for (int f : availableNumbersE)
                        {
                            set<int> availableNumbersF = availableNumbersE;
                            availableNumbersF.erase(f);

                            cout << a << " , " << b << " , " << c << " , " << d <<" , " << e << " , " << " , " << f << endl;
                        }
                    }
                }
            }
        }
    }
    */
};