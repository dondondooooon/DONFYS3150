#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    // Simulation Setup
    double N = 100; // End Time in microseconds
    double dt = 0.01; // Stepsize
    double n = N/dt; // Points
    mat r = mat(3,n).fill(0.); // Position vector
    mat v = mat(3,n).fill(0.); // Velocity vector
    // Trap & Particle Initialization
    double T = 9.64852558*10; // Tesla unit
    double V = 9.64852558*pow(10,7); // electric potential unit
    double Ca_p_mass = 40.078; // mass for Ca+ ion
    double d = 10000.0*0.05; // characteristic dimenion
    double f = 0.01; // 0.4 // 0.7
    double wz = 0.2; // (0.2,2.5)
    // Set Penning Trap
    PenningTrap Trap(1*T,10*V,10000,false, f, wz, n);
    // Add Particle/s
    Trap.add_n_particle(1,1,Ca_p_mass,{1,0,1},{0,1,0});
    // Trap.add_n_particle(1,1,Ca_p_mass,{-1,1,-1},{0,1,0});
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