#include "particle.hpp"

// Definitions of constructors
Particle::Particle(double q_in, double m_in,vec r_in, vec v_in){
  q = q_in;     // Charge
  m = m_in;     // Mass
  r = r_in;     // Position
  v = v_in; // Velocity
}

// Definitions of copy constructor, ...
