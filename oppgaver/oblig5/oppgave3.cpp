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

// ser etter blad noder på en preorder måte 
/**
 * koden ser etter en blad node, går dermed å leter etter flere bladnoder og sammenligner 
 * verdien til nyfunnet bladnodene med verdien til den første bladnoden.
 */
void erKomplettTre(Node* node) {
      gNivaa++;
    if(node && gKomplettTre){ //Er det en reell node og er treet fortsatt komplett 
      if(!node-> left || !node->right ){ // det mangler et barn 
        if(!gNivaaOpp){ // er det første ukomplette funnet? 
          gDybde = gNivaa;
          gNivaaOpp = true; 
        } else if(abs(gNivaa - gDybde) > 1){ // det er ikke det første ukomplette funnet og nivaaet funnet her er mer enn 1 mer enn det første 
          gKomplettTre = false; 
          return; 
        }
      }

        erKomplettTre(node->left);// gjør det samme for ventre og høyre  
        erKomplettTre(node->right); 
    
    }
        gNivaa--;
}



