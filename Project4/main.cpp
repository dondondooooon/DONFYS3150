#include <iostream>
#include "func.hpp"

int main(){
    int N = 2;
    int T = 1;
    Lattice gitter(N,T);
    gitter.S_ = gitter.S_gen();
    int n_samples = 100;

    // CHECK IF I FLIP 1 SPIN
    // cout << "This: " << endl << gitter.S_ << endl;
    // cout << "This: " << endl << gitter.Snew_ << endl;
    // gitter.S_rng();
    // cout << "This: " << endl << gitter.Snew_ << endl;

    // gitter.S2_all();
    // int nsize = gitter.all_S.size();
    // for (int i=0; i<nsize; i++){
    //     cout << "This" + to_string(i) + ":" << endl << gitter.all_S[i] << endl;
    // }
    // // int tall = gitter.E_all();
    // // cout << "THIS IS THE NUMBER: " << tall << endl;
    
    int E_old;
    int E_new;
    int E_sum = 0;
    int E_avg = 0;

    for (int i=1; i<n_samples+1; i++){
        E_old = gitter.E(gitter.S_);
        gitter.S_rng();
        int ii = gitter.i_flip;
        int jj = gitter.j_flip;
        E_new = gitter.E(gitter.Snew_);

        double accept = gitter.p(gitter.delta_E(ii,jj));
        int r = randu();

        if (r < accept){
            gitter.S_ = gitter.Snew_;
        }

        E_sum += gitter.E(gitter.S_);
    }

    E_avg += E_sum / n_samples;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}