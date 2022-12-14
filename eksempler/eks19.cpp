/**
 *   Programeksempel nr 19 - Permutering (plassombytting/annen rekkefølge).
 *
 *   Eksemplet viser ombytting på ALLE tenkelige måter av ALLE elementer
 *   i en (int-)array.
 *   Mer forklaring av algoritmen/funksjonaliteten på:  Permutering.pdf
 *
 *   @file     EKS_19_Permutering.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>             //  cout
using namespace std;


const int N = 3;                       ///<  Arrayens lengde.


void bytt(int & tall1, int & tall2);
void display(const int arr[], const int n);
void permuter(int arr[], const int i, const int n);
void roterVenstre(int arr[], const int i, const int n);


/**
 *  Hovedprogrammet:
 */
int main() {
    int array[N];                    //  Array som skal permuteres.

    for (int i = 0; i < N; i++)      //  Fyller array med: 1, 2, 3, ..., N
        array[i] = i+1;
        display(array,N);

    permuter(array, 0, N);           //  Lager (og skriver) permutasjoner av
                                     //    ALLE arrayelementene.
    cout << '\n';
    display(array, N);       //  Skriver array etter at ferdig
                              //    (for å vise at original er gjenopprettet).

    cout << "\n\n";

    return 0;
}


/**
 *  Bytter om to referanseoverførte variables innhold.
 *
 *  @param   tall1  -  Verdien som skal byttes med 'tall2' (referanseoverført)
 *  @param   tall2  -  Verdien som skal byttes med 'tall1' (referanseoverført)
 */
void bytt(int & tall1, int & tall2) {
    int temp = tall1;           //  Midlertidig (temporary) unnalagring.
    tall1 = tall2;
    tall2 = temp;
}


/**
 *  Skriver ut HELE arrayen 'arr' sitt innhold.
 *
 *  @param   arr  -  Arrayen som får hele sitt innhold skrevet ut
 *  @param   n    -  Antall elementer i arrayen (siste indeks brukt er n-1)
 */
void display(const int arr[], const int n) {
    for (int i = 0;  i < n;  i++)
        cout << ' ' << arr[i];
    cout << '\n';
}


/**
 *  Genererer rekursivt ALLE mulige permutasjoner av innholdet i 'arr'.
 *
 *  @param   arr  -  Arrayen som skal permuteres
 *  @param   i    -  Indeksen som ALLE ETTERFØLGENDE verdier skal flyttes til
 *  @param   n    -  Antall elementer i arrayen (siste indeks brukt er n-1)
 *  @see     bytt(...)
 *  @see     display()
 *  @see     roterVenstre(...)
 */
void permuter(int arr[], const int i, const int n) {
    if (i == n-1){                      //  Nådd en ny permutasjon:
        display(arr, n);                //  Skriver ut arrayens innhold.
       // cout << " ";
}   else {                              //  Skal permutere:
        permuter(arr, i+1, n);          //  Beholder nåværende nr.'i'.
        for (int t = i+1;  t < n;  t++) {
            bytt(arr[i], arr[t]);       //  Bytter nr.'i' etter tur med
            permuter(arr, i+1, n);      //  For hver av ombyttene: permuterer
        }                               //     resten av de etterfølgende.
       // cout << "For rotering ";
       // display(arr,n);
        roterVenstre(arr, i, n);        //  Gjenoppretter opprinnelig array!!!
      //  cout << "Etter rotering ";
      //  display(arr,n);
       // cout << endl;
    }
}


/**
 *  Venstreroterer en array innhold.
 *
 *  @param   arr  -  Arrayen som får (deler av) sitt innhold venstrerotert
 *  @param   i    -  Laveste indeks som skal venstreroteres
 *  @param   n    -  'n-1' er høyeste indeks som venstreroteres
 */
void roterVenstre(int arr[], const int i, const int n) {
    int venstreVerdi = arr[i];            //  Tar vare på første.
    for (int k = i+1;  k < n;  k++)       //  Roterer (flytter alle ned
        arr[k-1] = arr[k];                //     ETT hakk/indeks).
    arr[n-1] = venstreVerdi;              //  Legger første inn bakerst.
}