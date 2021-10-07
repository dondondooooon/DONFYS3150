#include <iostream>
#include "func.hpp"

int main()
{
    vec a = linspace(1,10,10);
    Particle my_particle(1023,2301,{9, 1, 2},a);
    PenningTrap trap(69,96,5);
    cout << my_particle.m_r << endl;
    cout << trap.m_V0 << endl;
    vec e;
    e = trap.external_E_field(a);
    cout << e << endl;

    // Done
    return 0;
}