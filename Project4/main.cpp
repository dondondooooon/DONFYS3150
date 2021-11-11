#include <iostream>
#include "func.hpp"

int main(){
    int N = 2;
    int T = 1;
    Lattice gitter(N,T);
    gitter.S_ = gitter.S_gen();
    int n_samples = 100;

    // gitter.S2_all();
    // int nsize = gitter.all_S.size();

    // for (int i=0; i<nsize; i++){
    //     cout << "This" + to_string(i) + ":" << endl << gitter.all_S[i] << endl;
    // }

    // // int tall = gitter.E_all();
    // // cout << "THIS IS THE NUMBER: " << tall << endl;
    
    int E_sum = 0;
    int E_avg = 0;

    for (int i=1; i<n_samples+1; i++){
        propose new s 
        
    }

    cout << "Hello World!" << endl;
    // Done
    return 0;
}