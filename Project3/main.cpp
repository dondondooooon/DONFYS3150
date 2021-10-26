#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    // Simulation Setup
    double N = 100; // End Time in microseconds
    double dt = 0.01; // Stepsize
    double n = N/dt; // Points
    vec t = vec(n).fill(0.); // Time vector
    mat r = mat(3,n).fill(0.); // Position vector
    mat v = mat(3,n).fill(0.); // Velocity vector
    // Trap & Particle Initialization
    double T = 9.64852558*10;
    double V = 9.64852558*pow(10,7);
    double e = 1.602176634*pow(10,-19);
    double Ca_p_mass = 40.078;
    // Set Penning Trap
    PenningTrap Trap(1*T,10*V,10000,false);
    // Add Particle/s
    Trap.add_n_particle(1,1,Ca_p_mass,{1,0,1},{0,1,0});
    Trap.add_n_particle(1,1,Ca_p_mass,{-1,1,-1},{0,1,0});
    // Number of particles in our trap test
    int p_size = Trap.m_all_p.size(); 
    // Run simulation
    Trap.full_evolution(dt,n,p_size);
    // Export our cube matrixes
    for (int j=0;j<p_size;j++){
        r = Trap.R_.col(j);
        v = Trap.V_.col(j);
        r.save("Rpos" + to_string(j) + ".bin");
        v.save("Vvel" + to_string(j) + ".bin");
        cout << j << endl;
    } 
    cout << "Hello World!" << endl;
    // Done
    return 0;
}