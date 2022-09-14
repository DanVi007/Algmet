
#include <iostream>
using namespace std;
struct Node
{
    char ID;            // Nodens ID/key/nøkkel/navn (en bokstav).
    Node *left, *right; // Peker til venstre/høyre subtre (evt. nullptr).
    Node(const char id)
    {
        ID = id;
        left = right = nullptr;
    }
};

Node *gRoot = nullptr; // Rot-peker til treet.

int currentLevel = 0;
int highestOddLevel = -1;
Node* highestOddNode;
void findHighestOddLevel(Node *node)
{
    if (node)
    {
        if(!node->left && !node->right && (currentLevel / 2 ) > highestOddLevel
        && (currentLevel % 2 != 0)){
            highestOddLevel = currentLevel;
            highestOddNode = node;
        }
        currentLevel++;
        findHighestOddLevel(node->left);
        findHighestOddLevel(node->right);
    }
    currentLevel--;
} 



int main(){

    
    return 0;
}