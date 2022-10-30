#include <iostream> 
using namespace std;

struct Node{
    int ID; 
    Node * left, *right; 
    Node(int id) {
        ID = id;
        left = right = nullptr;
    }
};
/**
 * 1. Deler arrayen i to, venstre side blir venstre barn og høyre
 *   side blir høyre barn. 
 * 2. gjør dette for de delte treene rekursivt. 
 * 
 */
/*
Node * byggBalansertBST(const int arr[] , const int start, const int slutt ){
    if(start != slutt){ // dersom start == det nådd enden.
        int midtersteIndeks = start + (slutt -start) /2 ; //indeksen det skal deles fra.
        Node * rot = new Node(arr[midtersteIndeks]); // midterste indeks er rot 
        rot->left = byggBalansertBST(arr,start ,midtersteIndeks); //gjør det samme for venstre side av rota.
        rot-> right = byggBalansertBST(arr, midtersteIndeks+1 , slutt ); // gjøre det samme for høyre side av rota 
        return rot;
    } else {
        return nullptr; //ikke noe mer noder å finne , nullptr returnert.
    }
}
*/
/*
Node * byggBalansertBST(const int arr[] , const int start, const int slutt ){
    int midtersteIndeks = start + (slutt -start) /2;
    Node * rot = new Node(arr[midtersteIndeks]); 
    if(midtersteIndeks != start && midtersteIndeks != slutt){
        rot->left = byggBalansertBST(arr,start ,midtersteIndeks);
        rot-> right = byggBalansertBST(arr, midtersteIndeks+1 , slutt );
    }
    return rot;
}
*/

Node * byggBalansertBST(const int arr[] , const int start, const int slutt ){
    int midtersteIndeks = start + (slutt -start) /2;
    Node * rot = new Node(arr[midtersteIndeks]); 
    if(!(start == slutt && slutt == midtersteIndeks))
    rot->left = byggBalansertBST(arr,start ,midtersteIndeks-1);
    rot-> right = byggBalansertBST(arr, midtersteIndeks+1 , slutt );
    return rot;
}