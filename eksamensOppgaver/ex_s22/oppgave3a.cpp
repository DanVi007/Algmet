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

Node * gRoot = nullptr;


bool skrivNivaa(const Node * t , const int n , const int nivaa ){
    if(t){
        if(n == nivaa) {
            cout << t->ID << " , "; 
            return true;
        }
        bool venstreFunnet = skrivNivaa(t->left , n+1 , nivaa) ;
        bool hoyreFunnet = skrivNivaa(t->right , n+1, nivaa ) ;
        return venstreFunnet || hoyreFunnet; 
    }{
        return false;
    }
}

void  byggEksempelTre(){
    gRoot = new Node(1);
    gRoot -> left = new Node(2);
    gRoot -> right = new Node(3);
}

int main(){
    byggEksempelTre();
    int aktueltNivaa = 1; 
    while(skrivNivaa(gRoot,1 , aktueltNivaa) ) aktueltNivaa++;
    return 0;
}