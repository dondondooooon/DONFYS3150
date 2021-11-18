#include <iostream>
#include "isingmodel.hpp"

int main(){
    int L = 20;
    int cycles = 1000000;
    vec Tvec = linspace(0.5,4.5,100);
    Ising ising(L,Tvec,cycles);
    //ising.monte_carlo();
    //ising.printT1();
    //ising.mc_temp();
    ising.cycle_plot(1.0,"1");

    cout << "Hello World!" << endl;
    // Done
    return 0;
}

