/**
 *   draw this
 *         *
 *         * *
 *           *
 *         * * * *
 *             *
 *             * *
 *               *
 *         * * * * * * * *
 *                 *
 *                 * *
 *                   *
 *                 * * * *
 *                     *
 *                     * *
 *                       *
 * used hint for number of spaces
 */
#include <iostream>
using namespace std;

void visit(int stars, int blanks){
    for(int i = 0 ; i < blanks ; i++ ){
        cout << " ";
    }
    for(int i = 0; i < stars; i++){
        cout << "*";
    }
    
    cout << endl;
}

void traverseInOrder(int stars,int blanks){
   if(stars >= 1){
    traverseInOrder(stars/2,blanks);
    visit(stars,blanks);

    traverseInOrder(stars/2, blanks +stars/2);
   } 
}

int main()
{
    traverseInOrder(8,0);

    return 0;
}
