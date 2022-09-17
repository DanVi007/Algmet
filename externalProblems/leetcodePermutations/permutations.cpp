#include <iostream>
#include <vector>
using namespace std;
/*

the problem is from this video:
https://www.youtube.com/watch?v=s7AvT7cGdSo&ab_channel=NeetCode
*/
// TODO: utiilise pointers
vector<int> numbers = {1, 2, 3};

void printAllPermutations(vector<int> currentNumbers, vector<int> remainingNumbers)
{
    if (remainingNumbers.size() == 0)
    {
        for (int i = 0; i < currentNumbers.size(); i++)
        {
            cout << currentNumbers[i] << " , ";
        }
        cout << endl;
    }
    for (int i = remainingNumbers.size() - 1; i >= 0; i--)
    {
        vector<int> remainingNumbersCp = remainingNumbers;
        vector<int> currentNumbersCp = currentNumbers;
        currentNumbersCp.push_back(remainingNumbers[i]);
        remainingNumbersCp.erase(remainingNumbersCp.begin() + i);
        printAllPermutations(currentNumbersCp, remainingNumbersCp);
    }
}

int main()
{
    vector<int> emptyVector;
    printAllPermutations(emptyVector, numbers);
    return 0;
}