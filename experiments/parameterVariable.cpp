
#include <iostream>
using namespace std;

void someFunction(string someString, int depth)
{
    if (depth == 0)
    {
        return;
    }
    if (depth == 2)
    {

        someString = "not hello";
    }
    cout << someString << endl;
    depth--;

    someFunction(someString, depth);
}

int main()
{
    string something = "hello";
    someFunction(something, 2);

    cout << something << endl;

    return 0;
}