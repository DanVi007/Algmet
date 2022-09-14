#include <iostream>
using namespace std;

struct Node
{
    int ID;     // Nodens ID/key/navn et (tall) 
    int nivaa;   // Nodens nivå i treet ift. rotnoden.
    Node *left;  // Peker til venstre subtre, evt nullptr.
    Node *right; // Peker til høyre subtre, evt nullptr.

    Node(int id, Node *l, Node *r)
    {
        nivaa = 0;
        ID = id;
        left = l, right = r;
    }
};

Node *gRoot = nullptr; // Rot-peker.

void setLevel(Node *node)
{
    if (node)
    {
        if (node->left)
        {

            node->left->nivaa = node->nivaa + 1;
        }
        if (node->right)
        {

            node->right->nivaa = node->nivaa + 1;
        }
        setLevel(node->left);
        setLevel(node->right);
    }
}

void findValues(Node* node, int& sumNivaa, int& antall) {
    if(node){
        sumNivaa += node->nivaa;
        antall += 1;
        findValues(node->left, sumNivaa, antall);
        findValues(node->right, sumNivaa, antall);
    }
} 


void writeParents(Node * node){
   if(node){
    if(!node->left && !node->right){
        Node * nodePointer = gRoot; 
        int searchValue = node->ID;
        while(nodePointer){
            cout << nodePointer->ID << " ";
           if(searchValue < nodePointer->ID){
            nodePointer = nodePointer->left;
           }else {
            nodePointer = nodePointer->right;
           } 
        }
        cout << "\n";

    }
    writeParents(node->left);
    writeParents(node->right);
   } 
}
Node *byggBFStre()
{
    Node *n1 = new Node(1, nullptr, nullptr),
         *n3 = new Node(3, n1, nullptr),
         *n5 = new Node(5, nullptr, nullptr),
         *n4 = new Node(4, n3, n5);
    return n4;
}

/**
 *  Bygger et binært testtre.
 *
 *  @return   Peker til rota i treet som er bygd
 */
Node *byggTre()
{
    //          Bygger treet:                         //
    //                       17                       //
    //                  /          \                  //
    //                 33           11                //
    //               /    \       /    \              //
    //              7      35   82      5             //
    //            /   \           \    /              //
    //           27     13        31  34              //
    //                   \        /                   //
    //                   10      57                   //
    //                          /  \                  //
    //                         3   30                 //
    Node *n3 = new Node(3, nullptr, nullptr),
         *n30 = new Node(30, nullptr, nullptr),
         *n10 = new Node(10, nullptr, nullptr),
         *n57 = new Node(57, n3, n30),
         *n27 = new Node(27, nullptr, nullptr),
         *n13 = new Node(13, nullptr, n10),
         *n31 = new Node(31, n57, nullptr),
         *n34 = new Node(34, nullptr, nullptr),
         *n7 = new Node(7, n27, n13),
         *n35 = new Node(35, nullptr, nullptr),
         *n82 = new Node(82, nullptr, n31),
         *n5 = new Node(5, n34, nullptr),
         *n33 = new Node(33, n7, n35),
         *n11 = new Node(11, n82, n5),
         *n17 = new Node(17, n33, n11);
    return n17;
}


int main()
{
    gRoot = byggBFStre();
    setLevel(gRoot);
    cout << gRoot->nivaa << "\n";
    cout << gRoot->left->nivaa << "\n";
    cout << gRoot->right->nivaa << "\n";
    cout << gRoot->left->left->nivaa << "\n";
    

   int sum = 0;
   int antall = 0;

   findValues(gRoot, sum,antall);

   cout << "\n\n" << double(sum/antall); 


gRoot = byggTre();

setLevel(gRoot);


   sum = 0;
   antall = 0;

   findValues(gRoot, sum,antall);

    
   cout << "\n\n" << double(sum)/ double(antall); 


    gRoot = byggBFStre();
    cout << gRoot->ID;
    cout << "\n\nForeldre\n\n";
    writeParents(gRoot);

    return 0;
}