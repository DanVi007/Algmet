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


bool skrivNivaa(const Node * t , const int n , const int nivaa ){
    if(t){
        if(nivaa == n ) {
            cout << t->ID << " , "; 
            return true;
        }
        bool venstreFunnet = skrivNivaa(t->left , n, nivaa+1) ;
        bool hoyreFunnet = skrivNivaa(t->right , n, nivaa+1 ) ;
        return venstreFunnet || hoyreFunnet; 
    }{
        return false;
    }
}