#include <iostream>
using namespace std;
int number = 5;

void printAnumber(int number){
    cout<< number << endl;
}

//https://stackoverflow.com/questions/6905598/c-equivalent-to-java-this
/*
the solution above only works in classes etc i assume. I get the error below when used
without a class
*/
//https://stackoverflow.com/questions/7600346/what-is-a-nonstatic-member-function
int main(){
    printAnumber(7);

    int numbers [][];
    return 0;
}