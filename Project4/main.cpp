#include <iostream>
#include "isingmodel.hpp"

int main(){
    int L = 2;
    int samples = 1000;
    int cycles = 1000;
    double T = 1.0;
    vec Tvec = linspace(0.5,2.0,100);
    Ising ising(L,T,samples,cycles,Tvec);
    ising.mc_temp();
    ising.print();

    // cout << "This is E_average: " << gitter.Eavg_ << endl;
    // cout << "This is M_avgerage: " << gitter.Mavg_ << endl;
    // cout << "This is E^2 avg: " << gitter.E2_ << endl;
    // cout << "This is M^2 avg: " << gitter.M2_ << endl;

    // cout << "This is the heat capacity: " << gitter.cv_ << endl;
    // cout << "This is the mag. suscp.: " << gitter.chi_ << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}