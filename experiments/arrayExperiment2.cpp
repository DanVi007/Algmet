#include <iostream>
using namespace std; 
int numbers[] = {1,2,3};
int something = 4; 

void changeNumbers(int numbers[]){
    numbers[0] = 5;
}
void display(){
    for(int i : numbers){
        cout <<i << " , ";
    }
    cout <<endl; 
}
void changeNumber(int number){
    number =6;
}

int main(){
    display();
    changeNumbers(numbers);
    display();
    changeNumber(something);
    cout<< something << endl;

    return 0;
}