/**
 *   Hovedrisset til oblig nr 2.
 *
 *   For programmets funksjonalitet se:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */

#include <iostream>
using namespace std;

/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node
{
    int ID;             //  Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; //  Peker til begge subtrærne (evt. 'nullptr').
    Node(int id)
    {
        ID = id;
        left = right = nullptr;
    }
};

void byggTre();
void skrivAnnenhverBladnode(Node *node); //  Oppgave A
int tellStorre(Node *node, int verdi);   //  Oppgave B
bool storreEnnBarna(Node *node);         //  Oppgave C

Node *root = nullptr; ///<  Peker til treet rot.
bool skrev = true;    ///<  Om forrige bladnode ble skrevet eller ei.

/**
 *  Hovedprogrammet:
 */
int main()
{
    int verdi; //  Innlest og ønsket verdi fra brukeren.

    byggTre();

    cout << "\n\nTester Oppgave A:\n"
         << "\tAnnenhver bladnode i treet:   ";
    skrivAnnenhverBladnode(root);

    cout << "\n\n\n\nTester Oppgave B:\n"
         << "\tNoder større enn verdien: ";
    cin >> verdi;
    cout << "\tAntall noder større enn " << verdi << ": "
         << tellStorre(root, verdi);

    cout << "\n\n\n\nTester Oppgave C:\n"
         << "\tEnhver foreldre er " << ((storreEnnBarna(root)) ? "" : "IKKE ")
         << "større enn barna sine!\n";

    root->left->right->ID = 20; //  Endrer verdien 15 til 20.
    cout << "\tEnhver foreldre er " << ((storreEnnBarna(root)) ? "" : "IKKE ")
         << "større enn barna sine!\n\n";

    return 0;
}

/**
 *  Bygger et tre for å kunne teste de ulike funksjonene.
 */
void byggTre()
{
    Node *p[19];
    for (int i = 0; i < 19; i++)
        p[i] = new Node(19 - i);
    root = p[0]; //  Bygger treet:          //
    p[0]->left = p[1];
    p[0]->right = p[2]; //          19             //
    p[1]->left = p[3];
    p[1]->right = p[4]; //       /       \         //
    p[2]->left = p[5];
    p[2]->right = p[6]; //     18        17        //
    p[3]->left = p[7];
    p[3]->right = p[8];  //    /   \     /   \      //
    p[4]->left = p[9];   //  16     15  14    13    //
    p[5]->right = p[10]; //  / \    /     \   / \   //
    p[6]->left = p[11];
    p[6]->right = p[12]; // 12 11  10      9 8   7  //
    p[9]->left = p[13];
    p[9]->right = p[14];  //       / \     /   \     //
    p[10]->left = p[15];  //      6   5   4     3    //
    p[11]->right = p[16]; //         /     \         //
    p[14]->left = p[17];  //        2       1        //
    p[15]->right = p[18];
}

/**
 *  OPPGAVE A:
 *     Skriver annenhver bladnode startende fra høyre, og med den andre noden.
 *     Traverserer: "seg selv", "høyre node", "venstre node".
 *   @param   node  -  Noden som skal besøkes.
 */
void skrivAnnenhverBladnode(Node *node)
{
    if (node) // sjekker om noden peker til en reel node. 
    {
        if (!node->left && !node->right && !skrev) // sjekker om noden ikke har noen barn dvs "er en blad node".
                                                    // og om den tidligere noden har allerede skrevet ut. skrev variabel starter som true.  
        {
            cout << node->ID << " ";  
            skrev = true; // setter skrev til å være true etter å hatt skrevet. 
        }
        else if (!node->left && !node->right) // hvis noden er en blad node, men tidligere bladnode har skrevet. skrev blir da satt til false.
        {
            skrev = false;
        }
        else
        { // hvis noden ikke er en blad node fortsetter koden med høyrebarn først. 
            skrivAnnenhverBladnode(node->right);
            skrivAnnenhverBladnode(node->left);
        }
    }
}

/**
 *  OPPGAVE B: Finner antall noder under 'node' STØRRE ENN enn 'verdi'.
 *  Traverseres på en preorder måte ikke alle nodene blir besøkt. 
 *  @param   node   -  Noden som skal besøkes/undersøkes
 *  @param   verdi  -  verdien det skal sjekkes om nodens ID er større enn
 *  @return  Antall noder under 'node' med 'ID' STØRRE ENN 'verdi'
 */
int tellStorre(Node *node, int verdi)
{
    int antall = 0; // antall noder større enn verdi.
    if (node && node->ID > verdi) // sjekk hvis node eksiterer og om den er større en vedien. 
    {
        antall++; // inkrementerer antall med 1 hvis noden er større enn verdi.
        antall += tellStorre(node->left, verdi); // inkrementerer antall som blir funnet fra venstre og høyre node. 
        antall += tellStorre(node->right, verdi);
    }

    return antall; // returnerer totalt antall noder større enn verdi. 
}

/**
 *  OPPGAVE C: Finner ut om alt under 'node' er mindre dens 'ID'.
 *  Går gjennom på en postorder måte om en av barna er større returnere funksjonen.
 *  @param   Node  -  Noden som skal besøkes/undersøkes
 *  @return  Returnerer om 'node's ID er større enn barnas eller ei
 */
bool storreEnnBarna(Node *node)
{
    bool left = true;
    bool right = true;
    if (node) // sjekker om det er en node
    {
        if (node->left) // sjekker om venstre barn eksisterer
        {
            if (node->left->ID >= node->ID) // hvis venstre barn har høyere eller lik verdi til nåverende node returneres false.
            {
                return false;
            }

            else // ellers fortsetter koden og sjekke storreEnnBarna for venstre barnet.
            {
                left = storreEnnBarna(node->left);
            }
        }

        if (node->right) // sjekker om venstre barn eksisterer
        {
            if (node->right->ID >= node->ID) // hvis høyre barn har høyere eller lik verdi til nåverende node returneres false.
            {
                return false;
            }
            else
            {
                right = storreEnnBarna(node->right); // ellers fortsetter koden og sjekke storreEnnBarna for høyre barnet.
            }
        }
    }
    return left && right; // returnere om venstre side og høyre side er har barn større enn foreldre.
}