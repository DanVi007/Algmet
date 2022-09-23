#include <iostream> 

using namespace std; 
//https://www.w3schools.com/cpp/cpp_arrays_size.asp
void display(int* numbers ){
    cout << sizeof(numbers)/sizeof(int);
    for(int i = 0; i < sizeof(numbers)/sizeof(int);i++){
        cout << numbers[i] << endl; 
    }
}

int main(){
    int numbers[100] = {} ;
    numbers[1] = 5;
    display(numbers);
    cout << sizeof(numbers);

    return 0;

}
// result of experiment just use vector.