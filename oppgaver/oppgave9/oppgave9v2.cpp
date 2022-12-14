#include <iostream>

using namespace std;

const int N = 9;

int row[N];
int counter = 0;

void buildRow()
{
    for (int i = 0; i < N; i++)
    {
        row[i] = i + 1;
    }
}

void display(const int row[])
{
    for (int i = 0; i < N; i++)
    {
        cout << row[i] << " ";
    }
    cout << endl;
}
/*
void swap(int row[], int i, int j)
{
    int temp = row[i];
    row[i] = row[j];
    row[j] = temp;
}
*/
void change(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}
/*
bool checkNumber(int row[] , int indexToCheck){
    if(row[indexToCheck] +1 == row[indexToCheck +1 ] ||
    row[indexToCheck] -1 == row[indexToCheck +1] ||
      row[indexToCheck] +1 == row[indexToCheck -1] ||
        row[indexToCheck] -1 == row[indexToCheck -1] ){
            return false;
        }
   return true;
}
*/
/*
bool checkNumber(int row[], int start, int indexToCheck)
{
    if (
        row[indexToCheck] + 1 == row[start - 1] ||
        row[indexToCheck] - 1 == row[start - 1]
        )
    {
        return false;
    }
    if(start == N-2 &&
        abs((int)row[indexToCheck] -(int) row[start]) <= 1 ){
            return false;

    }
    return true;
}
*/
bool checkNumber(int row[], int indexToCheck)
{
    if (indexToCheck <= 0)
    {
        return true;
    }
    else if (abs((int)row[indexToCheck] - (int)row[indexToCheck - 1]) <= 1)
    {
        return false;
    }
    return true;
}

void permutateClass(int row[], int start, int last)
{

    if (start == last && checkNumber(row, start -1) && checkNumber(row, start))
    {
        display(row);
        counter++;
    }
    else if (start == 0 || checkNumber(row, start-1))
    {
        for (int i = start; i <= last; i++)
        {
            change(row[start], row[i]);
            permutateClass(row, start + 1, last);
            change(row[i], row[start]);
        }
    }
}

int main()
{
    buildRow();
    // display(row);
    // change(row[0], row[1]);
    display(row);
    cout << endl;
    counter = 0;
    permutateClass(row, 0, N - 1);
    //    cout << N-1<< endl ;
    //    cout << checkNumber(row, 3) << endl;

        cout << counter << endl;
    return 0;
}
