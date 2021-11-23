#include <iostream>
#include "isingmodel.hpp"

int main(int argc, const char* argv[]){
    // Check number of command line arguments
    assert(argc==6);

    // Read command line arguments
    const double T_min = atof(argv[1]);
    const double T_max = atof(argv[2]);
    const int n_T = atoi(argv[3]);
    const int n_cycles_per_thread = atoi(argv[4]);
    const string output_file_name = argv[5];

    // Define Temperature Vector
    vec Tvec = vec(n_T).fill(0.);
    double dT = (T_max - T_min)/( (double) n_T);
    double t_iter = T_min;
    for (int i=0; i<n_T; i++){
        Tvec(i) += t_iter;
        t_iter += dT;
    }

    // Define Inverse Temperature Vector
    vec betavec = vec(Tvec.size());
    for (int i=0; i<Tvec.size(); i++){
        betavec(i) = 1./Tvec(i);
    }

    // Set Lattice Size
    int L = 80; // 20, 60, 100
    // Set Monte Carlo cycles
    int cycles = n_cycles_per_thread;

    
    cout << Tvec << endl;
    cout << output_file_name << endl;

    // Initialize Ising Class
    Ising ising(L,Tvec,cycles,betavec,output_file_name);

    auto t1 = chrono::high_resolution_clock::now();
    ising.mc_temp();
    auto t2 = chrono::high_resolution_clock::now();
    double duration_seconds = chrono::duration<double>(t2-t1).count(); // oppg7
    cout << "Time taken: " << duration_seconds << endl;

    cout << "Hello World!" << endl;
    // Done
    return 0;
}