#include <iostream>
#include "utils.hpp"
#include "particle.hpp"

int main()
{
    vec a = linspace(1,10,100);
    Particle my_particle(1023,2301,a,a);
    cout << my_particle.q << endl;
    trap.add_particle(my_particle)
    // Done
    return 0;
}