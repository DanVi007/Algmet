#include <iostream>
using namespace std;

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
  if(node){
    int venstreSum = slettNoderPaaStiMedmMinSum(t->left,sum+t->ID,min);
    int hoyreSum = slettNoderPaaStiMedmMinSum(t->right,sum+t->ID,min);
    if(venstreSum < min){
      t->left = nullptr;
    }
    if(hoyreSum < min){
      t->right = nullptr;
    }

    int sumNode = t->ID+sum;
    int sumNode += (venstreSum < hoyreSum) ? hoyreSum : venstreSum;
    if(sumNode < min){
      delete (t);
    }
    return sumNode;
  } else {
    return 0;
  }
}
