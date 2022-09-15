
#include <iostream>
using namespace std;
struct Node
{
    char ID;            // Nodens ID/key/nøkkel/navn (en bokstav).
    Node *left, *right; // Peker til venstre/høyre subtre (evt. nullptr).
    Node(const char id, Node *l, Node *r)
    {
        ID = id;
        left = l;
        right = r;
    }
};

Node *gRoot = nullptr; // Rot-peker til treet.

Node *newRootNode = nullptr;
int currentLevel = 0;
int highestOddLevel = -1;
Node *highestOddNode;

void findHighestOddLevel(Node *node)
{
    if (node)
    {
        if (!node->left && !node->right && currentLevel > highestOddLevel && (currentLevel % 2 != 0))
        {
            highestOddLevel = currentLevel;
            highestOddNode = node;
        }
        currentLevel++;
        findHighestOddLevel(node->left);
        currentLevel++;

        findHighestOddLevel(node->right);
    }
    currentLevel--;
}

Node *nodes[100];
int lastIndex;

void listNodes(Node *node)
{
    if (node)
    {
        listNodes(node->left);
        nodes[lastIndex] = node;
        lastIndex++;
        listNodes(node->right);
    }
}

void sortNodes()
{

    for (int i = 0; i < lastIndex -1 ; i++)
    {
        for (int u = 0; u < lastIndex-1; u++)
        {
            {

                if (nodes[u]->ID > nodes[u + 1]->ID)
                {
                    Node *oldNode = nodes[u];
                    nodes[u] = nodes[u + 1];
                    nodes[u + 1] = oldNode;
                }
            }
        }
    }
   
}
int counter =0 ;


void setNodesBack(Node *node)
{
    if (node)
    {
    cout << "\n#" << counter << endl;  
    counter++;
        setNodesBack(node->left);
        node->ID = nodes[lastIndex]->ID;
        lastIndex++;
       cout << lastIndex<< " , ";
        setNodesBack(node->right);
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

//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << (int)node->ID<< std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}
int main()
{
    
    Node *rootNode = byggTre();
    findHighestOddLevel(rootNode);

    cout << highestOddLevel << " , " << (int)highestOddNode->ID << "\n";

    highestOddLevel = 0;
    highestOddNode = nullptr;
    currentLevel = 0;
    findHighestOddLevel(byggBFStre());

    cout << highestOddLevel << " , " << (int)highestOddNode->ID << "\n";
    // oppgave c

    nodes[0] = new Node(0, nullptr, nullptr);
    lastIndex = 1;

    newRootNode = byggTre();
    cout << endl;
    printBT(newRootNode);
    listNodes(newRootNode);
    for (int i = 1; i < lastIndex; i++)
    {
        cout << (int)nodes[i]->ID << " ";
    }
    cout << "\n\n";
    sortNodes();
    for (int i = 1; i < lastIndex; i++)
    {
        cout << (int)nodes[i]->ID << " ";
    }
    cout << endl;
    lastIndex = 1;
    setNodesBack(newRootNode);
    
    cout << (int)newRootNode->ID << endl;
    cout << (int)newRootNode->right->ID << endl;
    cout << (int)newRootNode->right->right->ID << endl;
    
    cout << endl << endl;
    printBT(newRootNode);
    return 0;
}