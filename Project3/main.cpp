#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    double T = 9.64852558*10;
    double V = 9.64852558*pow(10,7);
    double e = 1.602176634*pow(10,-19);
    double cap_mass = 40.078;

    PenningTrap Trap(1*T,10*V,10000);

    Trap.add_n_particle(1,1,cap_mass,{1,0,1},{0,1,0});
    //Trap.add_n_particle(1,3,6,{1,2,0},{0,0,0});

    // cout << Trap.m_all_p[0].info() << endl;
    // vec r = Trap.m_all_p[0].m_r;
    // vec v = Trap.m_all_p[0].m_v;
    // cout << "Efield:\n" << Trap.external_E_field(r) << endl;
    // cout << "Bfield:\n" << Trap.external_B_field(r) << endl;
    // cout << "Net_External:\n" << Trap.total_force_external(0) << endl;
    // cout << "Net_Particle_Force:\n" << Trap.total_force_particles(0) << endl;
    // cout << "Netto Force:\n" << Trap.total_force(0) << endl;
    
    double N = 100;
    vec t = linspace(0,N,100);
    double dt = t(1)-t(0);  // Since evenly spaced, timestep is constant
    mat r = mat(N,3).fill(0.);
    mat v = mat(N,3).fill(0.);

    for (int i=0;i<N;i++){
        r.row(i) = Trap.m_all_p[0].m_r.st();
        v.row(i) = Trap.m_all_p[0].m_v.st();
        Trap.evolve_RK4(dt);
    }

    // EulerCromer Check?
    /*
    for (int i=0; i<N; i++){
        r.row(i) = Trap.m_all_p[0].m_r.st();
        v.row(i) = Trap.m_all_p[0].m_v.st();
        Trap.evolve_Euler_Cromer(dt);
    }
    */
   
    r.save("Rpos_RK4.bin");
    v.save("Vhas_RK4.bin");

    cout << "Hello World!" << endl;
    // Done
    return 0;
}