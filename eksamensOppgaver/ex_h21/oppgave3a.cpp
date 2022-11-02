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
  if(node){
    int nivaa = 1;
    if(!node->left && !node->right){
      return 1;
    } else {
      nivaaVenstre = minimumHoyde(node->left);
      nivaaHoyre = minimumHode(node->right);
      nivaa += (nivaaVenstre < nivaaHoyre) ? nivaaVenstre : nivaaHoyre;
    }

    return nivaa;

  }else{
    return 0;
  }

}
