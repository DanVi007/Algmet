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

Node* gRoot = nullptr; ///< Rotpeker til hele treet
bool gKomplettTre = true,   ///< Er treet komplett eller ei.
    gNivaaOpp = false ; ///< Gått opp ett nivå en gang eller ei.
int gDybde = 0 , ///< Aktuell max.dybde å sjekke noder opp mot.
    gNivaa = -1; ///< Aktuelt nivå node/nullptr er på.

/**
 * ide:
 * deprecated feiler på case 11  
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
void erKomplettTreGammel(Node * node){
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
    erKomplettTreGammel(node->right);
    if(
      (!node->right && gDybde == 0 && gNivaa == 0)// rot noden er høyreste høyre node 
      || (!gNivaaOpp &&gNivaa == gDybde && ((node->left && !node->right)  || (node->left && node->right))) // se punkt 4 (clean up here )
      ){
      gDybde++; 
      gNivaaOpp = true;
    } else if(!gNivaaOpp && !node->right) { // se punkt 2 (kan kortes? gNivaaOpp trengs ikke? (samle dem?))
      gDybde = gNivaa; 
    }
    erKomplettTreGammel(node->left);
  }
  gNivaa--;
}

/**
 * 1. traverserer treet fra høyre barn til venstre. dvs høyre barn først dermed 
 *    seg selv også venstre barn.(reverse inorder) 
 * 
 * 2. Finner aller først den høyrenoden lengst til høyre. dvs første node uten
 *    høyre barn helt til høyre. Når denne blir funnet setter den gDybde til å 
 *    være gNivaa. (gNivaaOpp må være false for at sjekken skal foretas) 
 * 
 * 3. Dersom den finner en node på samme nivaa som gDybde og har minst ett barn.
 *    Vil den nye gDybden være gNivaa +1 og gNivaaOpp vil være true. 
 *    (gNivaaOpp må være false for at sjekken skal foretas). Den har nå funnet
 *    maksdybden et komplett tre kan være. 
 * 
 * Krav for ett fullt tre 
 * 4. Noder med gNivaa < gDybde må ha ett fult sett med barn. 
 *
 * 5. Dersom gNivaaOpp er true dvs. et komplett tres maks dybde er funnet.
 *    Da må alle noder ha nivå lik eller under gDybde. 
 * 
 * 6. Dersom en node har ett høyre barn men ingen venstre barn er det ikke et 
 *    komplett tre(uansett).
 */
void erKomplettTre(Node * node){
  if(node && gKomplettTre){
    gNivaa++;
    //sjekker om krav for ett komplett tre er brutt 
    if((gNivaa < gDybde && !(node->left && node->right))//Er nivået til noden
                                                        //lavere enn gDybde og
                                                        //har den ikke fullt 
                                                        //barn?  
        || (gNivaaOpp && gNivaa > gDybde) //Har globale dybden gått opp et nivå 
                                          //og er nivået til noden større enn 
                                          //denne dybden?
        || (node->right && !node->left)){ //Har noden ett høyre barn uten ett 
                                          //venstre barn? 
          gKomplettTre = false; //Hvis ja, da er det ikke et komplett tre.
          return; //De neste linjene vil ikke kjøres. 
    }
    erKomplettTre(node->right);//kaller seg selv rekursivt med høyre barn. 
                               //Høyre barn lengst til høyre vil da bli funnet 
                               //først. 
    // leter etter maks dybde 
    if(!gNivaaOpp && !node->right){//Har gDybden ikke gått opp et nivå en gang
                                   //før og er det ingen høyre barn? 
      gDybde = gNivaa;//Ja, da har høyrebarn lengst til høyre blitt funnet. 
    }
    //Er gNivaaOpp false og noden sitt nivå det samme som dybden? 
    //Har noden minst ett nodebarn? (tilfellet der noden kun har
    //høyre barn er ikke reelt siden det blir fanget opp i punkt 6) 
    if(!gNivaaOpp && gNivaa == gDybde && (node->left || node->right)){
      gDybde = gNivaa +1;//setter ny gDybde til å være en mer enn nivå til node 
      gNivaaOpp = true;//Denne inkrementering vil skje kun en gang. 
    }
    erKomplettTre(node->left);
    gNivaa--;
  }
}

// teste funksjoner
/**
 * Printing a binary tree 
 */
//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
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

Node * byggCase10Tre(){
  Node * n1 = new Node(1,nullptr,nullptr),
        *n3 = new Node(3,nullptr,nullptr),
        *n2 = new Node(2,n1,nullptr),
        *n4 = new Node(4,n3,n2);
        return n4;
}

Node* byggCase11Tre(){
  Node * n1 = new Node(1,nullptr,nullptr),
      * n2 = new Node(2,nullptr,nullptr),
      * n3 = new Node(3,nullptr,nullptr) ,
      * n4 = new Node(4,n1,nullptr),
      * n5 = new Node(5,n4,n2),
      * n6 = new Node(6,n3,nullptr),
      * n7 = new Node(7,n5,n6);
  return n7;
}

Node * byggCase12Tre(){
  Node* n1 = new Node(1,nullptr,nullptr),
      * n2 = new Node(2,nullptr,nullptr),
      * n3 = new Node(3,nullptr,nullptr),
      * n4 = new Node(4,nullptr,nullptr),
      * n5 = new Node(5,nullptr,nullptr),
      * n6 = new Node(6,n2,n3),
      * n7 = new Node(7,n4,n5),
      * n8 = new Node(8,n6,n7),
      * n9 = new Node(9,n1,n8);
    return n9;

}

Node * byggCase13Tre(){
  Node* n6, * n8, * n11a, * n11b, * n12, * n13a, * n13b,
        * n17, * n28, * n31, * n33, * n34, * n35a, * n35b, * n39, * n72;

    n8 = new Node(8, nullptr, nullptr);
    n11b = new Node(11, nullptr, nullptr);
    n13b = new Node(13, nullptr, nullptr);
    n31 = new Node(31, nullptr, nullptr);
    n35b = new Node(35, nullptr, nullptr);
    n34 = new Node(34,n35b, nullptr);
    n12 = new Node(12, n11b, nullptr);
    n39 = new Node(39,nullptr, nullptr);
    n72 = new Node(72, nullptr, nullptr);
    n6 = new Node(6, n72, nullptr);
    n13a = new Node(13, n12, nullptr);
    n28 = new Node(28, nullptr, nullptr);
    n35a = new Node(35, n34, n39);
    n11a = new Node(11, n6, n13a);
    n33 = new Node(33, n28, n35a);
    n17 = new Node(17, n11a, n33);
    gRoot = n17;
  return gRoot;
}

Node * byggCase14Tre(){
  Node * n1 = new Node(1, nullptr,nullptr),
       * n2= new Node(2,nullptr,nullptr),
       * n3= new Node(3,nullptr,nullptr),
       * n4= new Node(4,nullptr,nullptr),
       * n5= new Node(5,nullptr,nullptr),
       * n6= new Node(6,nullptr,nullptr),
       * n7= new Node(7,nullptr,nullptr),
       * n8= new Node(8,nullptr,nullptr),
       * n9= new Node(9,n1,n2),
       * n10= new Node(10,n3,n4),
       * n11= new Node(11,n5,n6),
       * n12= new Node(12,n7,n8),
       * n13= new Node(13,n9,n10),
       * n14= new Node(14,n11,n12),
       * n15= new Node(15,n13,n14);
    return n15;
}

// https://cplusplus.com/forum/beginner/4639/
typedef Node* (*AlleByggeFunksjoner)();

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
    byggCase9Tre,
    byggCase10Tre,
    byggCase11Tre,
    byggCase12Tre,
    byggCase13Tre,
    byggCase14Tre
  };

  const int antallCase = sizeof(byggeFunksjoner)
                          /sizeof(AlleByggeFunksjoner);
  int sukksessArray[antallCase] = { 1,0,1,1,1, 1,0,0, 0,0,0 ,0,0,1}; 
  int antallSukkses = 0; 

  for(int i = 0; i < antallCase; i ++){
    cout << "case " << (i+1) << " tre" << endl;
    string komplettEllerIkke = sukksessArray[i] ? "Et " : "Ikke et " ;
    cout << komplettEllerIkke<< "komplett tre " << endl; 
    gRoot = byggeFunksjoner[i](); 
    printBT(gRoot); 
    erKomplettTre(gRoot);
    if(gKomplettTre == sukksessArray[i]){
      cout << "sukkses" <<endl;
      antallSukkses++;
    }  else {
      cout << "feil" << endl;
    }
    cout << " - - - - - - - - - - \n" << endl;
    nullStill();
  }

  cout << "Testet " << antallCase << " tilfeller." << endl;
  if(antallCase == antallSukkses){
    cout << "Alle testene var en sukkses. " << endl;
  } else {
    cout << antallSukkses << "/" << antallCase
          << " tester var sukksesfulle." << endl;
  }

  return 0;
}