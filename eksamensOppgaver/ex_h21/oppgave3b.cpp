#include <iostream>
using namespace std;

struct Node {
 int ID; // Nodens ID/key/nøkkel/navn (et tall).
 Node *left, *right; // Referanse til begge subtrærne (evt. nullptr/NULL).
 Node(int id) { ID = id; left = right = nullptr; }
};

// /**
//  * 1. traverserer postorder.
//  * 2. Dersom det er en blad node returner sum i  parameter 
//  * 3. Totalsum = max(sum fra venstre og sum fra høyre )
//  * 4. Summen fra venstre eller høyre subtre som er mindre enn min skall settes
//  *    til nullptr.
//  * 5. Dersom totalsum er mindre enn min skal noden slettes
//  *
//  */
//  
// int slettNoderPaaStiMedMinSum(Node * & t, const int sum,const int min){
//   if(t){
//     //venstre og høyre subtre sin minste sum
//     //nåverende sum blir satt inn som parameter
//     int venstreSum = slettNoderPaaStiMedMinSum(t->left,sum+t->ID,min);
//     int hoyreSum = slettNoderPaaStiMedMinSum(t->right,sum+t->ID,min);
//     //sjekker om subtreene er mindre enn min
//     if(venstreSum < min){
//       t->left = nullptr;
//     }
//     if(hoyreSum < min){
//       t->right = nullptr;
//     }
//
//     int sumNode = t->ID+sum;
//     sumNode += (venstreSum < hoyreSum) ? hoyreSum : venstreSum;
//     if(sumNode < min){
//       delete (t);
//     }
//     return sumNode;
//   } else {
//     return 0;
//   }
// }

/**
 * 1. traverserer postorder.
 * 2. Dersom det er en blad node returner sum i  parameter 
 * 3. Totalsum = max(sum fra venstre og sum fra høyre )
 * 4. Summen fra venstre eller høyre subtre som er mindre enn min skall settes
 *    til nullptr.
 * 5. Dersom totalsum er mindre enn min skal noden slettes
 *
 */
 
int slettNoderPaaStiMedMinSum(Node * & t, const int sum,const int min){
  if(t){
    //venstre og høyre subtre sin minste sum
    //nåverende sum blir satt inn som parameter
    int venstreSum = slettNoderPaaStiMedMinSum(t->left,sum+t->ID,min);
    int hoyreSum = slettNoderPaaStiMedMinSum(t->right,sum+t->ID,min);
    //sjekker om subtreene er mindre enn min
    if(venstreSum < min){
      t->left = nullptr;
    }
    if(hoyreSum < min){
      t->right = nullptr;
    }

    // setter summen av det største sum fra subtre.
    int sumNode = (venstreSum < hoyreSum) ? hoyreSum : venstreSum;
    if(sumNode < min){
      delete (t);
    }
    return sumNode;
  } else {
    // returner gammel verdi dersom nullptr er nådd. 
    return sum;
  }
}

