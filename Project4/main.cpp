#include <iostream>
#include "isingmodel.hpp"

int main(){
    int L = 80; // L = 2, 20, 40, 60, 80, 100
    int cycles = 500000; // 1000, 10000, 100000
    // vec Tvec = linspace(0.5,4.5,100); // oppg 4 
    vec Tvec = linspace(2.1,2.4,10); // oppg 8
    vec betavec = vec(Tvec.size());
    for (int i=0; i<Tvec.size(); i++){
        betavec(i) = 1./Tvec(i);
    }
    Ising ising(L,Tvec,cycles,betavec);
    // ising.monte_carlo();
    // ising.printT1();
    // ising.mctemp();
    // ising.cycle_plot(1.0,"1"); // (1.0,"1") for T=1 ; (2.4,"2.4") for T=2.4
    auto t1 = chrono::high_resolution_clock::now();
    ising.mc_temp();
    auto t2 = chrono::high_resolution_clock::now();
    double duration_seconds = chrono::duration<double>(t2-t1).count(); // oppg7
    cout << "Time taken: " << duration_seconds << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}

