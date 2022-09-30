#include <iostream>

using namespace std;

const int N = 3;
int row[N];

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

void swap(int row[], int i, int j)
{
    int temp = row[i];
    row[i] = row[j];
    row[j] = temp;
}

void permutateClass(int row[], int start, int last)
{
    if (start == last )
    {
        display(row);
    }
    else
    {
        for (int i = start; start <= last; i++)
        {
            swap(row, start, i);
            permutateClass(row, start + 1, last);
            swap(row ,i, start);
        }
    }
}

int main()
{
    buildRow();
    display(row);
    swap(row, 1,2);
    swap(row, 2,1);
    display(row);
    cout << endl;
    //permutateClass(row, 0, N -1);
    return 0;
}