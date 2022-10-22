#include <iostream>          //  cout
using namespace std;
struct Node{
    char ID;
    Node *left, *right; 
    Node(const char id, Node * l , Node *r){
      ID= id; 
      left = l;
      right = r;
    }
}; 

// https://cplusplus.com/forum/beginner/4639/
typedef Node* (*AlleByggeFunksjoner)();

Node* gRoot = nullptr;
bool gKomplettTre = true,
    gNivaaOpp = false ; 
int gDybde = 0 , // gDybde blir nivaa til den første noden som blir funnet 
    gNivaa = -1;


/**
 * ide:
 * 
 * 1. Default case for alle noder uansett nivå
 * ** om det er en node med høyre barn men ingen venstre, vil det ikke være et komplett tre  
 * 
 * 
 * 
 * 2. traverserer treet fra høyre til venstre. dvs høyre barn først dermed seg selv og så venstre barn. 
 * Funksjonen henter først ut høyrenoden helt til høyre. Nivået på denne høyrenoden blir initielt gDybde
 * de neste nodene som har nivå gDybde -1 må ha fullt barn, dvs både venstre og høyre barn.
 * 
 * 3. Dersom høyrenoden helt til høyre har nivå 0 blir gNivaaOpp satt til å være true og gDybde til å være 1  
 * 
 * 4. Noder som har nivå gdybde kan enten ha ingen barn, fullt barn eller bare venstre barn .(kan kortes siden default case allerede sjekkes)
 *  Første gang en node med manglende høyre barn eller fullt barn blir funnet på dette nivået og gNivaaOpp er false
 *  blir gdybde++ og gNivaaOpp blir satt til true, et unntak er om noden ikke følger default casen. 
 * 
 * 5.Dersom gNivaaOpp er true skal alle de neste nodene på nivå under gDybde ha fullt barn for at det skal være komplett tre. Dvs hvis 
 * gNivaopp == true && !(node->left && node->right) && gNivaa < gDybde 
 * 
 * 6. Dersom gNivaOpp er true og det er noen noder som er større enn gDybde vil det ikke være komplett
 * 
*/
void erKomplettTre(Node * node){
  gNivaa++;
  if(node && gKomplettTre) {
    // caser for om det ikke er et komplett tre 
    if(
      (node->right && !node->left) // default case(1) har ingen venstre, men en høyre
      || (gDybde != 0 && gNivaa == gDybde -1 && !(node->left && node->right))//om gDybde er satt (ikke 0) og gNivå er rett over gDybde og om den mangler barn (punkt 2) 
      || (gNivaaOpp && gNivaa < gDybde && !(node->left && node->right))// se punkt 5 i komentaren over 
      || (gNivaaOpp && gNivaa > gDybde) // se punkt 6 i komentaren over 
    ){
      gKomplettTre = false;
      return;
    }
    erKomplettTre(node->right);
    if(
      (!node->right && gDybde == 0 && gNivaa == 0)// rot noden er høyreste høyre node 
      || (!gNivaaOpp &&gNivaa == gDybde && ((node->left && !node->right)  || (node->left && node->right))) // se punkt 4 (clean up here )
      ){
      gDybde++; 
      gNivaaOpp = true;
    } else if(!gNivaaOpp && !node->right) { // se punkt 2 (kan kortes? gNivaaOpp trengs ikke? (samle dem?))
      gDybde = gNivaa; 
    }
    erKomplettTre(node->left);
  }
  gNivaa--;
}

/**
 * Printing a binary tree 
 */
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
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

void nullStill(){
  gKomplettTre = true;
  gNivaaOpp = false;
  gDybde = 0;
  gNivaa = -1;
}

Node* byggCase1Tre(){
  Node *n1 = new Node(1,nullptr,nullptr);
  return n1;
}

Node* byggCase2Tre(){
  Node *n1 = new Node(1,nullptr,nullptr),
       *n2 = new Node(2,nullptr,n1 );

  return n2;
}

Node* byggCase3Tre(){
  Node *n1 = new Node(1,nullptr,nullptr),
       *n2 = new Node(2,n1,nullptr );

  return n2;
}

Node* byggCase4Tre(){
  Node *n1 = new Node(1,nullptr,nullptr),
       *n2 = new Node(2,nullptr,nullptr ),
       *root = new Node(3,n1,n2);
  return root ;
}

Node* byggCase5Tre(){
  Node *n0 = new Node(0,nullptr,nullptr), 
        *n1 = new Node(1,n0,nullptr),
       *n2 = new Node(2,nullptr,nullptr ),
       *root = new Node(3,n1,n2);
  return root ;
}

Node* byggCase6Tre(){
  Node *n0 = new Node(0,nullptr,nullptr), 
        *n3 = new Node(3, nullptr,nullptr),
        *n1 = new Node(1,n0,n3),
       *n2 = new Node(2,nullptr,nullptr ),
       *root = new Node(3,n1,n2);
  return root ;
}

Node* byggCase7Tre(){

  Node    *n5 = new  Node(5, nullptr,nullptr),
    * n2 = new Node(2, n5, nullptr),
  *n3 = new Node(3, nullptr,nullptr), 
        *n1 = new Node(1,n3,nullptr ),
       *root = new Node('r',n1,n2);
  return root ;
}

Node* byggCase8Tre(){
  Node * n1 = new Node(1,nullptr,nullptr),
        *n2 = new Node(2,nullptr,nullptr),
        *n3 = new Node(3,nullptr,nullptr),
        *n4 = new Node(4, n1,n2),
        *n5 = new Node(5, n3,nullptr),
        *n6 = new Node(6, n5,nullptr),
        *n7 = new Node(7,nullptr,n6),
        *n8 = new Node(8,n4,n7);
  return n8;
}

Node* byggCase9Tre(){
  Node *n1 = new Node(1,nullptr,nullptr),
      *n5 = new Node(5, nullptr,nullptr),
      *n2 = new Node(2, n1,nullptr),
      *n3 = new Node(3, n2, nullptr),
      *n4 = new Node(4,n3, n5);
    return n4;
}

int main(int argc, char const *argv[])
{
  AlleByggeFunksjoner byggeFunksjoner[] = {
    byggCase1Tre,
    byggCase2Tre,
    byggCase3Tre,
    byggCase4Tre,
    byggCase5Tre,
    byggCase6Tre,
    byggCase7Tre,
    byggCase8Tre,
    byggCase9Tre
  };

  const int antallCase = sizeof(byggeFunksjoner) /sizeof(AlleByggeFunksjoner);
  int sukksessArray[antallCase] = { 1,0,1,1,1, 1,0,0, 0}; 

  for(int i = 0; i < antallCase; i ++){
    cout << "case " << (i+1) << " tre" << endl;
    string komplettEllerIkke = sukksessArray[i] ? "Et " : "Ikke et " ;
    cout << komplettEllerIkke<< "komplett tre " << endl; 
    gRoot = byggeFunksjoner[i](); 
    printBT(gRoot); 
    erKomplettTre(gRoot);
    if(gKomplettTre == sukksessArray[i]){
      cout << "sukkses" <<endl;
    }  else {
      cout << "feil" << endl;
    }
    cout << " - - - - - - - - - - \n" << endl;
    nullStill();
  }

  return 0;
}