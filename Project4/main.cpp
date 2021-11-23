#include <iostream>
#include "isingmodel.hpp"

int main(){
    // Size of Lattice
    int L = 60; // L = 2, 20, 40, 60, 80, 100
    // Monte Carlo cycles
    int cycles = 500000; // 1000, 10000, 100000 100000 10000000
    // Temperature
    // vec Tvec = linspace(0.5,4.5,100); // oppg 4 
    vec Tvec = linspace(2.2,2.35,10); // oppg 8
    // Inverse Temperature
    vec betavec = vec(Tvec.size());
    for (int i=0; i<Tvec.size(); i++){
        betavec(i) = 1./Tvec(i);
    }
    // Initiazlize Ising Model class
    Ising ising(L,Tvec,cycles,betavec);
    // ising.monte_carlo(); // run monte carlo simulation for given mc cycles
    // ising.printT1(); // print out values for T = 1 for given mc cycles
    // ising.mc_temp(); // run monte carlo simulation for a range of T
    // ising.cycle_plot(1.0,"1"); // (1.0,"1") for T=1 ; (2.4,"2.4") for T=2.4 // print out values as it evolves in mc cycle
    // ising.monte_histogram(); // run for histogram data

    // Run Monte Carlo Simulation over a range of T 
    auto t1 = chrono::high_resolution_clock::now(); // Measure time
    ising.mc_temp();
    auto t2 = chrono::high_resolution_clock::now();
    double duration_seconds = chrono::duration<double>(t2-t1).count(); // oppg7
    cout << "Time taken: " << duration_seconds << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}

