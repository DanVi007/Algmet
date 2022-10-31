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