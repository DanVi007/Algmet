#include <vector>
#include <iostream>

using namespace std;


int main(){
    vector<int> numbers = {1,2,3};

    numbers = {};

    cout<< numbers[2];
}