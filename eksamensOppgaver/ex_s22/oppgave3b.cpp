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
    if(start <= slutt) {
        int midtersteIndeks = start + (slutt -start) /2;
        Node * rot = new Node(arr[midtersteIndeks]); 
        rot->left = byggBalansertBST(arr,start ,midtersteIndeks-1);
        rot-> right = byggBalansertBST(arr, midtersteIndeks+1 , slutt );
        return rot;
    } else {
        return nullptr;
    }
}

// probably worse would remove 
Node * byggBalansertBSTv2(const int arr[] , const int start, const int slutt ){
    int midtersteIndeks;
    Node * rot; 
    if(start <  slutt){
        midtersteIndeks = start + (slutt -start) /2;
        rot = new Node(arr[midtersteIndeks]); 
        rot->left = byggBalansertBST(arr,start ,midtersteIndeks-1);
        rot-> right = byggBalansertBST(arr, midtersteIndeks+1 , slutt );
    } else if (start == slutt) {
        midtersteIndeks = start; 
    } else {
        return nullptr; 
    } 
    return rot;
}

//test 
/**
 * Printing a binary tree 
 */
//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void printBT(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << (int)node->ID << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node *node)
{
    printBT("", node, false);
}

int IDer[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

int main(){
    Node * root = byggBalansertBST(IDer, 0,15);
    printBT(root);

    root = byggBalansertBSTv2(IDer, 0,15);
    printBT(root);
    return 0;
}


