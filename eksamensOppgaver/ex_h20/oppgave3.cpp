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
  if(t){ // sjekker om noden som ble satt inn ikker er nullptr
    if(t->left) { // om den har et venstre barn
      t->left->avstand = t->avstand - 1; // avstanden blir 1 mindre. 
      settVertikalAvstand(t->left);// gjør det samme for venstre barnet.
    }
    if(t->right) { // samme som for venstre. 
      t->right->avstand = t->avstand + 1;
      settVertikalAvstand(t->right);
    }
  }
}

// b
void skrivNoderUtenSosken(const Node * t ) {
  if(t) { // reel node
    if(t == gRoot){ // hvis det er første node altså rot
      cout << gRoot->ID << " ";
    }
    if(!t->left && t->right){ // hvis høyre barn ikke har venstre  søsken.
      cout << t->right->ID << " ";  // print ut ide til høyre barn.
    } else if(!t->right && t->left){ //hvis venstre barn ikke har høyre søsken
      cout << t->left->ID << " "; //print ut venstre barn
    } 
    skrivNoderUtenSosken(t->left); // sjekk for venstre
    skrivNoderUtenSosken(t->right); // sjekk for høyre
  }


}

int main(){
  return 0;
}

