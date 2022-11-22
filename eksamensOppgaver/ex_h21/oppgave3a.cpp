#include <iostream> 


using namespace std;
struct Node {
 int ID; // Nodens ID/key/nøkkel/navn (et tall).
 Node *left, *right; // Referanse til begge subtrærne (evt. nullptr/NULL).
 Node(int id) { ID = id; left = right = nullptr; }
};

Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota).
const int MAX = 999; // Max.nodehøyde (høyere enn reelt. Brukes kun i 3a).

int minimumHoyde(const Node * t ){
  if(t){
    int nivaa = 1;
    if(!t->left && !t->right){
      return 1;
    } else {
      int nivaaVenstre = minimumHoyde(t->left);
      int nivaaHoyre = minimumHoyde(t->right);
      // setter den minste av subtreene
      nivaa += (nivaaVenstre < nivaaHoyre) ? nivaaVenstre : nivaaHoyre;
    }

    return nivaa;

  }else{
    if(t == gRoot){
      return 0;
    } 
    return MAX;
  }
}
