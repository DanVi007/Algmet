#include <iostream>

using namespace std;
const int N = 5;
int numbers[N];

void buildArray()
{
    numbers[0] = 0;
    numbers[1] = 1;
    numbers[2] = 2;
    numbers[3] = 3;
    numbers[4] = -4;
}

int main()
{
    buildArray();
    int i = 0;
    while (numbers[++i] >= 0);
    cout << i << endl;

    return 0;
}