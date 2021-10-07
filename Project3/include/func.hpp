#ifndef __func_hpp__   
#define __func_hpp__

#include<armadillo>
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

};

class PenningTrap
{
public:
  double m_B0;  // Magnetic Field Strength
  double m_V0;  // Applied Potential
  double m_d;   // Characteristic Dimension

  // Constructor
  PenningTrap(double B0_in, double V0_in, double d_in);
  
//   // Add a particle to the trap
//   void add_particle(Particle p_in);

// External electric field at point r=(x,y,z)
vec external_E_field(vec r);  

// Er det mulig å kalle på member vairable på member functions?

//   // External magnetic field at point r=(x,y,z)
//   vec external_B_field(vec r);
/*
  // Force on particle_i from particle_j
  force_particle(int i, int j);

  // The total force on particle_i from the external fields
  total_force_external(int i);

  // The total force on particle_i from the other particles
  total_force_particles(int i);

  // The total force on particle_i from both external fields and other particles
  total_force(int i);

  // Evolve the system one time step (dt) using Runge-Kutta 4th order
  void evolve_RK4(double dt);

  // Evolve the system one time step (dt) using Forward Euler
  void evolve_Euler_Cromer(double dt);
*/
};

#endif