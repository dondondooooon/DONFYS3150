#ifndef __PenningTrap_hpp__   
#define __PenningTrap_hpp__

#include <Particle.hpp>

class PenningTrap
{
public: // Public 
  double m_B0;  // Magnetic Field Strength
  double m_V0;  // Applied Potential
  double m_d;   // Characteristic Dimension
  double m_ke;  // Columbs Constant
  std::vector<Particle> m_all_p;  // All particles

  // Constructor
  PenningTrap(double B0_in, double V0_in, double d_in);
  
  // Add a particle to the trap
  void add_particle(Particle p_in);

  // Add n particles to the trap
  void add_n_particle(int n, double q_in, double m_in, vec r_in, vec v_in);

  // External electric field at point r=(x,y,z)
  vec external_E_field(vec r);  

  // External magnetic field at point r=(x,y,z)
  vec external_B_field(vec v);

// The total force on particle_i from the external fields
  vec total_force_external(int i);

  // Force on particle_i from particle_j
  vec force_particle(int i, int j);

  // The total force on particle_i from the other particles
  vec total_force_particles(int i);

  // The total force on particle_i from both external fields and other particles
  vec total_force(int i);

  // Evolve the system one time step (dt) using Runge-Kutta 4th order
  void evolve_RK4(double dt);

  // Evolve the system one time step (dt) using Euler-Cromer
  void evolve_Euler_Cromer(double dt);

};

#endif