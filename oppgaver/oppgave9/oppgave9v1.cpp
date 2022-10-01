
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

void change(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

bool checkRow(int row[])
{

    for (int i = 1; i < N; i++)
    {
        if (abs((int)row[i] - (int)row[i - 1]) <= 1)
        {
            return false;
        }
    }
    return true;
}

void permutateClass(int row[], int start, int last)
{

    if (start == last && checkRow(row))
    {
        display(row);
        counter++;
    }
    else
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