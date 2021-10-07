#include "func.hpp"

// Definitions of constructors
Particle::Particle(double q_in, double m_in,vec r_in, vec v_in){
  m_q = q_in; // Charge
  m_m = m_in; // Mass
  m_r = r_in; // Position
  m_v = v_in; // Velocity
}

PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in){
  m_B0 = B0_in; // Magnetic Field Strength
  m_V0 = V0_in; // Applied Potential
  m_d = d_in; // Characteristic Dimension
}

// // Add a particle to the trap
// void add_particle(Particle p_in){

// }

// External electric field at point r=(x,y,z)
vec PenningTrap::external_E_field(vec r){
  //r(0) = -2*r(0);
  //r(1) = -2*r(1);
  //r(2) = 4*r(2);
  vec Efield = (m_V0/(2*m_d*m_d))*r;
  return (Efield);
}

// // External magnetic field at point r=(x,y,z)
// vec external_B_field(vec r){
//   vec Bfield = trap.B0*vec({0,0,r(2)});
//   return(Bfield);
// }
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
  void evolve_forward_Euler(double dt);
*/
