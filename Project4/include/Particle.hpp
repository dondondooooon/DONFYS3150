#ifndef __Particle_hpp__   
#define __Particle_hpp__

#include<armadillo>
#include <cmath>
using namespace arma;
using namespace std;

class Particle 
{
public:
  double m_q; // Charge
  double m_m; // Mass
  vec m_r; // Position
  vec m_v; // Velocity

  // Constructor
  Particle(double q_in, double m_in,vec r_in, vec v_in);

  // Info Method
  string info();
};

#endif