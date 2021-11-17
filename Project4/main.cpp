#include <iostream>
#include "isingmodel.hpp"

int main(){
    int L = 2;
    int cycles = 10000;
    vec Tvec = linspace(0.5,4.5,100);
    Ising ising(L,Tvec,cycles);
    //ising.monte_carlo();
    ising.printT1();
    //ising.mc_temp();

    cout << "Hello World!" << endl;
    // Done
    return 0;
}

