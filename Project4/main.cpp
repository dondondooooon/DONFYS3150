#include <iostream>
#include "func.hpp"

int main(){
    int N = 2;
    int n_samples = 100;
    int cycles = 1000;
    int T = 1;
    Lattice gitter(N,T,n_samples,cycles);
    gitter.S_ = gitter.S_gen();

    gitter.MCMC(cycles);

    cout << "This is E_average: " << gitter.Eavg_ << endl;
    cout << "This is M_avgerage: " << gitter.Mavg_ << endl;
    cout << "This is E^2 avg: " << gitter.E2_ << endl;
    cout << "This is M^2 avg: " << gitter.M2_ << endl;

    cout << "This is the heat capacity: " << gitter.cv_ << endl;
    cout << "This is the mag. suscp.: " << gitter.chi_ << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}