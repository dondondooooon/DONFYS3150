#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    // Trap & Particle Initialization
    double T = 9.64852558*10;
    double V = 9.64852558*pow(10,7);
    double e = 1.602176634*pow(10,-19);
    double Ca_p_mass = 40.078;
    // Set Penning Trap
    PenningTrap Trap(1*T,10*V,10000);
    // Add Particle/s
    Trap.add_n_particle(1,1,Ca_p_mass,{1,0,1},{0,1,0});
    Trap.add_n_particle(1,1,Ca_p_mass,{-1,0,-1},{0,1,0});
    int p_size = Trap.m_all_p.size(); // Number of particles in our trap
//test
    // Simulation Setup
    int l = 0; // Particle interaction; 0 = off
    double N = 100; // End Time in microseconds
    double dt = 0.01; // Stepsize
    double n = N/dt; // Points
    vec t = vec(n).fill(0.); // Time vector
    mat r = mat(3,n).fill(0.); // Position vector
    // mat v = mat(n,3).fill(0.); // Velocity vector

    Trap.full_evolution(dt,n,p_size,l);
    //cout << Trap.R_ << endl;
    for (int j=0;j<p_size;j++){
        r = Trap.R_.col(j);
        r.save("Rpos" + to_string(j) + ".bin");
    }
    
    // for (int i=0; i<p_size; i++){
    //     // Start Condition
    //     // if (i = 0){
    //     //     r0 = Trap.m_all_p[i].m_r;
    //     //     v0 = Trap.m_all_p[i].m_v;
    //     // }
    //     // else{
    //     //     Trap.m_all_p[i].m_r = r0;
    //     //     Trap.m_all_p[i].m_v = v0;
    //     // }
    //     // r.row(0) = r0.st(); 
    //     r.col(i) = Trap.m_all_p[i].m_r;
    //     // v.row(i) = Trap.m_all_p[i].m_v.st();

    //     Trap.full_evolution(r,dt,n,l,i);
    //     r.save("Rpos" + to_string(i) + ".bin"); // Save position vectors
    //     // v.save("Vhas" + to_string{i} + ".bin"); // Save velocity vectors
    // }

    // // EulerCromer Check?
    // for (int i=0; i<n-1; i++){
    //     Trap.evolve_Euler_Cromer(dt,l);
    //     v.row(i+1) = Trap.m_all_p[0].m_v.st();
    //     r.row(i+1) = Trap.m_all_p[0].m_r.st();
    //     t(i+1) = t(i) + dt;
    // }
   
    // Save Matrix to binary files
    // r.save("Rpos.bin"); // EC
    // v.save("Vhas.bin"); // EC
    // t.save("tid.bin");  // EC

    cout << "Hello World!" << endl;
    // Done
    return 0;
}