#include<iostream>

using namespace std;

// bool check3prefix(int array[],)
//
// bool prefix(int array[]){
//   int sizeOfArray = sizeof(array)/sizeof(int);
//   for(int i = 0; i < sizeOfArray; i++) {
//     
//     
//   }
// }
const string some3Prefix = "113";
const string some3Prefix2 = "112";
const string some4Prefix = "4222";
const string some5Prefix = "31233";

bool checkPrefix(string potentialPrefix){
 if(potentialPrefix== some3Prefix ||
     potentialPrefix == some3Prefix2 ||
     potentialPrefix == some4Prefix ||
     potentialPrefix == some5Prefix){
   return true;
 }
 return false ;
}
// arrayen trenger ikke å være sortert. 
bool prefix(char array[],const int sizeOfArray){
  string tempString;
  for(int i = 0;i < sizeOfArray;i++){

   tempString += array[i]; 

    if (checkPrefix(tempString) && i != sizeOfArray-1){
      cout << tempString << endl;
      for(int j = i +1 ; j < sizeOfArray;j++){
        cout << array[j];
      }
      cout << endl;

      return true;
    }
    // resets tempstring if a full number is found
    if(tempString.length() == 8){
      tempString = "";
    }
  }
  return false;
}
int main(){
  string number = "113123"; 
  const int lengthString = 6;
  char charArray[lengthString];
  int index = 0;
  for(char a : number) {
    charArray[index] = a;
    index++;
  }
  
  cout << prefix(charArray,lengthString) << endl;

  number = "123456781127834"; 
  const int lengthString2 = number.length();
  const int sizeOfArray2 = 15;
  char charArray2[sizeOfArray2];
  index = 0;
  for(char a : number) {
    charArray2[index] = a;
    index++;
  }
  
  cout << prefix(charArray2,sizeOfArray2) << endl;
  return 0;


}
