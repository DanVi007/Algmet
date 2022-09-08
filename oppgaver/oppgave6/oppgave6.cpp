/**
 *   Programeksempel nr 12 - Traverserer et binært tre REKURSIVT.
 *
 *   Eksempel som viser traversering av et binært tre vha rekursjon.
 *   Det viser hvor enkelt treet kan traverseres både på en preorder,
 *   inorder og postorder måte.
 *
 *   @file     EKS_12_RekursivTreTraversering.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream> //  cout
#include <iomanip>  //  setw
using namespace std;

/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node
{
    char ID;
    Node *left, *right; //  Initierende constructor:
    Node(char id)
    {
        ID = id;
        left = right = nullptr;
    }
};

void besok(const Node *node);
Node *byggTre();


void countNodes(Node *node);

void countNullptr(Node *node);

void countFullNodes(Node *node);

void getHeight(Node *node);

int gNivaa = -1; ///<  Hvilket nivå vi for øyeblikket er på i treet.
int gNr;         ///<  Fortløpende nummerering av besøkte noder.
                 //    NB:  Begge disse er kun i bruk her for å vise
                 //         i hvilken rekkefølge nodene besøkes og
                 //         hvilket nivå de befinner seg på.
                 //         Normalt brukes IKKE disse!
int gHeight;

/**
 *  Hovedprogrammet:
 */
int main()
{
    Node *root;

    root = byggTre();

    gNr = 0;

    cout << "\n\nAntall noder:\n";
    countNodes(root);

    cout << gNr;

    cout << "\n\n";

    gNr = 0;

    cout << "\n\nAntall nullptr:\n";
    countNullptr(root);

    cout << gNr;

    cout << "\n\n";

    gNr = 0;
    cout << "\n\nFulle noder: ";
    countFullNodes(root);

    cout << "\n\nAntall fulle noder :\n";
    cout << gNr;

    cout << "\n\n";

    gNivaa = 0; 
    cout << "\n\nFulle noder: ";
    countFullNodes(root);

    cout << "\n\nAntall fulle noder :\n";
    cout << gNr;

    cout << "\n\n";


    gNivaa = 0;
    gHeight = 0;
    cout << "\n\nHøyde på tre: ";
    getHeight(root);

    
    cout << gHeight;

    cout << "\n\n";

    return 0;
}

/**
 *  Besøker (visit) en node - ved å skrive dens besøksnummer ('gNr'),
 *  dens ID/key/data og hvilket nivå ('gNivaa') den er på.
 *
 *  @param   node  -  Aktuell node som skal besøkes
 */
void besok(const Node *node)
{
    cout << setw(6) << ++gNr << ": " << node->ID
         << "  på nivå: " << gNivaa << '\n';
}

/**
 *  Bygger et binært eksempel-tre (likt med det i EKS_08).
 *
 *  @return   Peker til det bygde treets rot
 */
Node *byggTre()
{
    /*   Bygger treet:                                     A
                                                  /                 \
                                             B                          C
                                        /         \                  /
                                      D             E              F
                                  /       \           \          /
                                G           H           I      J
                                  \        / \         /        \
                                   K      L   M       N          O
    */
    Node *noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast<char>('A' + i));

    noder[0]->left = noder[1];
    noder[0]->right = noder[2];
    noder[1]->left = noder[3];
    noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];
    noder[3]->right = noder[7];
    noder[4]->right = noder[8];
    noder[5]->left = noder[9];
    noder[6]->right = noder[10];
    noder[7]->left = noder[11];
    noder[7]->right = noder[12];
    noder[8]->left = noder[13];
    noder[9]->right = noder[14];
    return noder[0];
}



void countNodes(Node *node)
{
    if (node)
    {

        gNr++; //  Besøker FØR de rekursive kallene!
        countNodes(node->left);
        countNodes(node->right);
    }
}

void countNullptr(Node *node)
{
    if (node)
    {

        countNullptr(node->left);
        countNullptr(node->right);
    }
    else
    {
        gNr++;
    }
}

void countFullNodes(Node *node)
{
    if (node)
    {
        countFullNodes(node->left);
        countFullNodes(node->right);
        if (node->right && node->left)
        {
            cout << node->ID;
            gNr++;
        }
    }
}

void getHeight(Node *node){
    if (node)
    {
        gNivaa++;
        if(gHeight <= gNivaa){
            gHeight = gNivaa;
        }
        getHeight(node->left);
        getHeight(node->right);
        
        gNivaa--;
    }
}