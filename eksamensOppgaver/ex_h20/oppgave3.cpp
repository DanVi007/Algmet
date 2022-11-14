#include <iostream>

using namespace std;

struct Node {
 int ID; // Nodens ID/key/nøkkel/navn (et tall).
 int avstand; // Nodens "vertikale avstand" ift. rota (brukes kun i 3A).
 Node *left, *right; // Referanse til begge subtrærne (evt. 'nullptr/NULL').
 Node(int id) { ID = id; left = right = nullptr; avstand = 0; }
};

Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota).


//a

void settVertikalAvstand(const Node * t ) {
  if(t){
    if(t->left) {
      t->left->avstand = t->avstand - 1;
      settVertikalAvstand(t->left);
    }
    if(t->right) {
      t->right->avstand = t->avstand + 1;
      settVertikalAvstand(t->right);
    }
  }
}

// b
void skrivNoderUtenSosken(const Node * t ) {
  if(t) {
    if(t == gRoot){
      cout << gRoot->ID << " ";
    }
    if(!t->left && t->right){
      cout << t->right->ID << " "; 
    } else if(!t->right && t->left){
      cout << t->left->ID << " "; 
    } 
    skrivNoderUtenSosken(t->left);
    skrivNoderUtenSosken(t->right);
  }


}
int main(){


  return 0;
}

