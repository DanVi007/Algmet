#include <iostream>          //  cout
#include <queue>             //  queue
#include <vector>            //  vector
using namespace std;

struct Node{
    char ID;
    Node *left, *right; 
}; 

Node* gRoot = nullptr;
bool gKomplettTre = true,
    gNivaaOpp = false ; 
int gDybde = 0 , // gDybde blir nivaa til den første noden som blir funnet 
    gNivaa = -1;

// ser etter blad noder på en preorder måte 
/**
 * koden ser etter en blad node, går dermed å leter etter flere bladnoder og sammenligner 
 * verdien til nyfunnet bladnodene med verdien til den første bladnoden.
 */

/*
void erKomplettTre(Node* node) {
    if(node && gKomplettTre){ //Er det en reell node og er treet fortsatt komplett 
      gNivaa++;
        if(!node->left && !node->right){ // er det en blad node 
            if( !gNivaaOpp){ // er blad noden den første som ble funnet 
                gDybde = gNivaa;
                gNivaaOpp = true;
            } else if(abs(gNivaa - gDybde) > 1){// er forskjellen på denne bladnoden sitt nivå 
                                                // og første mer enn 1 
                gKomplettTre = false; // hvis ja da er treet ikke et komplett tre
               return; // returnerer dermed void, nedre linjer kjøres ikke  
            }
        }
        if((!node->left || !node->right) && abs(gNivaa - gDybde) > 1 ){
          gKomplettTre = false;
          return; 

        }
        erKomplettTre(node->left);// gjør det samme for ventre og høyre  
        erKomplettTre(node->right); 
        gNivaa--;

    }
}
*/

// ser etter enebarn på en preorder måte 
/**
    
 * koden ser etter et enebarn node, går dermed å leter etter flere enebarn  og sammenligner 
 * verdien til nyfunnet enebarn med verdien til den første enebarn .
 * enebarn er noder med ingen søsken dvs. forelderen til enebarnet har kun et barn. 
 */
/*
void erKomplettTre(Node* node) {
    gNivaa++;
    if(node && gKomplettTre){ //Er det en reell node og er treet fortsatt komplett 
      if(!node-> left || !node->right ){ // det er et enebarn  
        if(!gNivaaOpp){ //  er det det første enebarnet funnet 
          gDybde = gNivaa;
          gNivaaOpp = true; 
        } else if(abs(gNivaa - gDybde) > 1){ // det er ikke det første enebarnet funnet og nivaaet funnet her er mer eller mindre enn 1 enn det første 
          gKomplettTre = false; 
          return; 
        }
      }
        erKomplettTre(node->left);// gjør det samme for ventre og høyre  
        erKomplettTre(node->right); 
    }
    gNivaa--;
}
*/

// ser etter enebarn på en preorder måte 
/**
    
 * koden ser etter et enebarn node, går dermed å leter etter flere enebarn  og sammenligner 
 * verdien til nyfunnet enebarn med verdien til den første enebarn .
 * enebarn er noder med ingen søsken dvs. forelderen til enebarnet har kun et barn. 
 */
/*
void erKomplettTre(Node* node) {
    gNivaa++;
    if(node && gKomplettTre){ //Er det en reell node og er treet fortsatt komplett 
       if(gNivaaOpp && abs(gNivaa - gDybde) > 1 ) {
        gKomplettTre = false;
        return; 
       }

      if((!node->right || !node->left) && gNivaaOpp && gDybde != gNivaa){
          gKomplettTre = false;
          return; 
      }
       
      if(!node->left ){
        if(!gNivaaOpp){
          gNivaaOpp = true;
          gDybde = gNivaa; 
          return;
        } else if(gDybde != gNivaa){
          gKomplettTre = false;
          return; 
        }  
      }
      
      erKomplettTre(node->left);
      erKomplettTre(node->right);

    }
    gNivaa--;
}

*/

/*
void erKomplettTre(Node * node ){
  gNivaa++; 
  if(node && gKomplettTre){
    if(!gNivaaOpp){
      if(!node->left){
        gNivaaOpp = true;
        gDybde = gNivaa;
      }
    } else {
      if((gNivaa != gDybde && !node->right) || abs(gNivaa - gDybde) > 1 ){
        gKomplettTre = false;
        return;
      } else {
        gNivaaOpp = false;
      }
      

    }
    erKomplettTre(node->left);
    erKomplettTre(node->right);

  }
  gNivaa--;
}
*/

void erKomplettTre(Node * node){
  if(node && gKomplettTre){// rell 
    if((node->right && !node->left)
        || (gNivaa))
    
    ){

      gKomplettTre = false;
      return;
    }
    if(!gNivaaOpp){ // den har ikke gått opp et nivå 
      if(!node->left){ // den lengste til venstre er funnet 
        gNivaaOpp = true; // maks venstre er funnet
        gDybde = gNivaa; 
      }
    } else  {
      if(gNivaa > gDybde) {
        gKomplettTre = false;
        return;
      }

      if(gDybde -gNivaa > 2 && !(node->left && node->right)){
       gKomplettTre = false;
       return; 
      } 
    }
    erKomplettTre(node->left);
    erKomplettTre(node->right);

  }

  
}

void erKomplettTre2(Node * node) {
  gNivaa++;
  if(node && gKomplettTre) {
    if((node -> right && !node->left)
    || (gNivaaOpp && gNivaa > gDybde )
    || (gNivaaOpp && gDybde - gNivaa > 1 && (!node->left || !node->right))
    ){
      gKomplettTre = false;
      return;
    }
    if(!gNivaaOpp){
      if(!node -> left){
        gNivaaOpp = true;
        gDybde = gNivaa;
      }
    } else {

    }
  }
  gNivaa--;
}

void erKomplettTre3(Node * node){
  gNivaa++;
  if(node && gKomplettTre) {
  if((node -> right && !node->left)
  || (gNivaaOpp && gNivaa > gDybde )
  || (gNivaaOpp && gDybde - gNivaa > 1 && (!node->left || !node->right))
  ){
  gKomplettTre = false;
  return;
  }
  if(!gNivaaOpp){
  erKomplettTre3(node->left);
  if(!node -> left){
    gNivaaOpp = true;
    gDybde = gNivaa;
    return;
  }
  } else {
  if(gDybde - gNivaa == 1){
    if(node->right);
    erKomplettTre3(node->left);
    erKomplettTre3(node->right);

      }

    }
  }
  gNivaa--;
}

void erKomplettTre4(Node * node){
  gNivaa++;
  if(node && gKomplettTre){
    if((node -> right && !node->left)
    || (gNivaaOpp && gNivaa > gDybde )
    || (gNivaaOpp && gDybde - gNivaa > 1 && (!node->left || !node->right)) // maks dybde er funnet og nivået over har ikke maks barn
    ){
      gKomplettTre = false;
      return;
    }
    if(!gNivaaOpp){ // maks dybde ikke funnet 
      if(node->left){
        if(!node->left->left && !node->left->right){
          gNivaaOpp = true; 
          gDybde = gNivaa +1 ;
        }
      }
      if(!node->left && !node->right){// første blad node funnet fra høyre side 
        gNivaaOpp = true;
        gDybde =gNivaa;
      }

    }
   }
   erKomplettTre4(node->right);
   erKomplettTre4(node->left); 
  gNivaa--;
}

void erKomplettTre5(Node * node){
  gNivaa++;
  if(node && gKomplettTre){
    if((node -> right && !node->left)
        ||(gNivaaOpp && gNivaa > gDybde) 
    ){
      gKomplettTre = false;
      return;
    }
    if(!gNivaaOpp){
      if(!node->left && !node->right){
        gNivaaOpp = true;
        gDybde = gNivaa;
      } else if(!node->right){
        gNivaaOpp = true;
        gDybde = gNivaa+1;
      }
    } else {
      

    }

  }
  gNivaa--;

}
/*
void erKomplettTre6(Node * node){
  gNivaa++; 
  if(node && gKomplettTre){
    int depeestLevel = 0; 
    bool deepsestFound = false;
    Node * nodePointer = node; 
    int level = gNivaa;
    while( !deepsestFound ){
      if(!node->left && !node->right && level > depeestLevel) {
        depeestLevel = level;
      }

    }
    

    
  }
}
*/
// gKogg

//Node* gRoot = nullptr;
//bool gKomplettTre = true,
//    gNivaaOpp = false ; 
//int gDybde = 0 ,
//    gNivaa = -1;
void erKomplettTre7(Node * node){
  gNivaa++;
  if(node && gKomplettTre) {
    if(!gNivaaOpp){
      if(node->left && node->right){
        Node * nodePtr = node;
        
        if(node->left->left){
          if(!node->left && !node->right){

          }

        }
      }

    }


  }
  gNivaa--;



}

void erKomplettTre8(Node * node){
  gNivaa++;
  if(node&& gKomplettTre){
    if(!node->left && node->right ) // ikke default cases for et komplett tre 
    {
      gKomplettTre = false;
      return;
    }
    if(gNivaaOpp){
      if(gNivaa > gDybde 
      || (gNivaa == gDybde && !node->left && !node->right)
      || (gNivaa < gDybde && !(node->left && node->right))
      ){
        gKomplettTre = false;
        return;
      }
    }
    erKomplettTre8(node->right); 
    if(!gNivaaOpp && node->left && !node->right && (gDybde == 0 || gNivaa == gDybde )){
      gDybde = gNivaa +1 ;
      gNivaaOpp = false;
    }
    if(!gNivaaOpp && !node->left && !node->right){// er det en blad node 
     gDybde = gNivaa; 
    }

    erKomplettTre8(node->left);

}
gNivaa--;

}

// copy of komplee9 
/*
void erKomplett9{
  gNivaa++;
  if(node && gKomplettTre){
    if(!node->left && node->right // ikke default cases for et komplett tre  
      || (gDybde != 0  && gNivaa - gDybde > 1 ) 
      || (gNivaaOpp && gNivaa > gDybde)
      || (gDybde != 0 && gDybde - gNivaa >= 1 && !(node->left && node->right))
    ) 
    {
      gKomplettTre = false;
      return;
    }
    erKomplett9(node->right);
    if(gDybde == 0 && !node->left && !node->right) { // maks dybde er ikke satt 
      gDybde = gNivaa;
    }

    if(gDybde != 0 && gNivaa -gDybde == 1 && !node->left && !node->right) {
      gDybde = gNivaa;
      gNivaaOpp = true; 
    } else if(gDybde == 0 && !node->left && !node->right){
      gDybde = gNivaa; 
      gNivaaOpp = true;
    }

    erKomplett9(node->left);
  }
  gNivaa--;
}
*/
void erKomplett9(Node * node){
  gNivaa++;
  if(node && gKomplettTre){
    if(!node->left && node->right // ikke default cases for et komplett tre  
      || (!gNivaaOpp &&gDybde != 0  && gNivaa - gDybde > 1 ) 
      || (gNivaaOpp && gNivaa > gDybde)
      || (!gNivaaOpp &&gDybde != 0 && gDybde - gNivaa >= 1 && !(node->left && node->right))
    ) 
    {
      gKomplettTre = false;
      return;
    }
    erKomplett9(node->right);
    if(gDybde == 0 && !node->left && !node->right) { // maks dybde er ikke satt 
      gDybde = gNivaa;
    }

    if(gDybde != 0 && gNivaa -gDybde == 1 && !node->left && !node->right) {
      gDybde = gNivaa;
      gNivaaOpp = true; 
    } else if(gDybde == 0 && !node->left && !node->right){
      gDybde = gNivaa; 
      gNivaaOpp = true;
    }

    erKomplett9(node->left);
  }
  gNivaa--;
}

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
void erKomplettTre10(Node * node){
  gNivaa++;
  if(node && gKomplettTre) {
    // caser for om det ikke er et komplett tre 
    if(
      (node->right && !node->left) // default case(1)
      || (gDybde != 0 && gNivaa == gDybde -1 && node->left && node->right)// se punkt 2 i komentaren over 
      || (gNivaaOpp && gNivaa < gDybde && !(node->left && node->right))// se punkt 5 i komentaren over 
      || (gNivaaOpp && gNivaa > gDybde) // se punkt 6 i komentaren over 
    ){
      gKomplettTre = false;
      return;
    }
    erKomplettTre10(node->right);
    if(
      (!node->right && gDybde == 0 && gNivaa == 0)// se punkt 3 
      (!gNivaaOpp && (node->left || node->right)) // se punkt 4
      ){
      gDybde = 1; 
      gNivaaOpp = true;
    } else if(!gNivaaOpp && !node->right) { // se punkt 2 (kan kortes? gNivaaOpp trengs ikke? (samle dem?))
      gDybde = gNivaa; 
    }
    erKomplettTre10(node->left);
  }
  gNivaa--;
}