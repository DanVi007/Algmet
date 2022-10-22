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
