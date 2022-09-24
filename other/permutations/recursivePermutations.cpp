/*
following pseudo code from this video
https://www.youtube.com/watch?v=GuTPwotSdYw&t=2s&ab_channel=TECHDOSE
*/

#include <iostream> //  cout
#include <vector>
using namespace std;

vector<int> gNumbers = {1, 2, 3,4,5,6};

void swap(int i, int j, vector<int> &numbers)
{
    int oldNumber = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = oldNumber;
}
void displayVector(vector<int> vector){
        for(int i: vector){
            cout << i << " , ";
        }
        cout << endl;

}
int counter = 0;
void findPermutations(vector<int> numbers, int startingIndex, int endIndex)
{
    if (startingIndex == endIndex)
    {
        displayVector(numbers);
        counter++;
    }
    else
    {
        for (int i = startingIndex; i <= endIndex; i++)
        {
            swap(startingIndex, i, numbers);
            findPermutations(numbers, startingIndex + 1, endIndex);
            swap(i, startingIndex, numbers);
        }
    
    }
}

int main()
{

    findPermutations(gNumbers,0,gNumbers.size()-1);
    cout << counter << endl; 

    return 0;
}