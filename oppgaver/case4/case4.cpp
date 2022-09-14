
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

    bool sorted = false;
    while (!sorted)
    {
        sorted = false;
        int index = 0;
        while (index <= lastIndex)
        {
            if ((int)nodes[index]->ID > (int)nodes[index + 1]->ID)
            {
                Node *oldNode = nodes[index];
                nodes[index] = nodes[index + 1];
                nodes[index + 1] = oldNode;
                sorted = true;
            }
            index++;
        }
    }
}

void setNodesBack(Node *node)
{
    if (node)
    {
        setNodesBack(node->left);
        node->ID = nodes[lastIndex]->ID;
        lastIndex++;
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

int main()
{

    if ((int)'a'  (int)'b')
    {
        cout << "asklødfjløasdjfl";
    }
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

    Node *newRootNode = byggTre();

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
    lastIndex = 1;
    setNodesBack(newRootNode);

    return 0;
}