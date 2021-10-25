#ifndef __trap_hpp__
#define __trap_hpp__
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <armadillo>
#include <vector>
using namespace arma; 

class trap
{
public:

    trap(){}

    trap(double B0_in, double V0_in, double d_in);

    void add_particle(class particle p_in);

    std::vector<class particle> particles;

    vec external_E_field(vec r);

    vec external_B_field(vec r);

    vec force_particle(int i, int j);

    // vec total_force_external(int i);

    // vec total_force_particles(int i);

    // vec total_force(int i);

    void evolve_RK4(double dt);

    void evolve_FE(double dt);


};

#endif
