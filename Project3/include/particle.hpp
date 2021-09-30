#ifndef __MyClass_hpp__   
#define __MyClass_hpp__

#include<armadillo>
using namespace arma;

class Particle 
{
public:
  double q; // Charge
  double m; // Mass
  vec r; // Position
  vec v; // Velocity

  // Constructers
  Particle(double q_in, double m_in,vec r_in, vec v_in);

};

#endif