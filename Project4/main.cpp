#include <iostream>
#include "func.hpp"

int main(){
    int N = 2;
    Lattice gitter(N);

    // int ss;
    // int epsilon = 0;

    gitter.S2_all();
    int nsize = gitter.all_S.size();

    for (int i=0; i<nsize; i++){
        cout << "This" + to_string(i) + ":" << endl << gitter.all_S[i] << endl;
    }

    cout << "THIS!: " << endl << gitter.all_S[nsize-1] << endl;

    int tall = gitter.E_all();


    cout << "THIS IS THE NUMBER: " << tall << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}