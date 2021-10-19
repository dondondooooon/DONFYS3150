#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    PenningTrap Trap(40,40,2);

    Trap.add_n_particle(1,6,6,{1,0,1},{0,1,0});
    //Trap.add_n_particle(1,3,6,{1,2,0},{0,0,0});

    cout << Trap.m_all_p[0].info() << endl;
    vec r = Trap.m_all_p[0].m_r;
    vec v = Trap.m_all_p[0].m_v;
    cout << "Efield:\n" << Trap.external_E_field(r) << endl;
    cout << "Bfield:\n" << Trap.external_B_field(r) << endl;
    cout << "Net_External:\n" << Trap.total_force_external(0) << endl;
    cout << "Net_Particle_Force:\n" << Trap.total_force_particles(0) << endl;
    cout << "Netto Force:\n" << Trap.total_force(0) << endl;
    cout << ": " << "Hello World!" << endl;

    // Done
    return 0;
}