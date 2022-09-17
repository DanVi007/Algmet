#include <iostream>
#include <vector>
using namespace std;
vector<int> someVector = {1, 2, 3};
template <class T>
void printVector(vector<T> vector)
{

    for (T i : someVector)
    {
        cout << i << " , ";
    }
    cout << endl;
}


void popVector(vector<int> vector){
    vector.pop_back();
}

int main()
{
    vector<int> *vectorPointer = &someVector;
    printVector(someVector);
    cout << endl;
    vectorPointer->pop_back();
    printVector(someVector);
    popVector(someVector);
    printVector(someVector);
    
    return 0;
}