#include <iostream>
#include "Particle.hpp"
#include "PenningTrap.hpp"

int main()
{
    double ke = 1;
    PenningTrap Trap(40,40,2);

    Trap.add_n_particle(1,6,6,{1,1,1},{0,0,0});
    Trap.add_n_particle(1,3,6,{1,2,0},{0,0,0});
    // cout << Trap.m_all_p[0].info() << endl;
    // vec r = Trap.m_all_p[0].m_r;
    // vec v = Trap.m_all_p[0].m_v;
    // cout << Trap.external_E_field(r) << endl;
    // cout << Trap.external_B_field(r) << endl;
    // cout << Trap.total_force_external(0,r,v) << endl;
    cout << "This: " << Trap.total_force_particles(0,ke) << endl;
    // cout << "The size: " << sqrt(Trap.m_all_p.size()) << endl;
    cout << "Hello World!" << endl;

    // Done
    return 0;
}