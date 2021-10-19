#include "PenningTrap.hpp"
#include "Particle.hpp"

// Constructor Definition
PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in){
  m_B0 = B0_in; // Magnetic Field Strength
  m_V0 = V0_in; // Applied Potential
  m_d = d_in; // Characteristic Dimension
  m_ke = 1; // Columbs Constant
}

  // Add a particle to the trap
  void PenningTrap::add_particle(Particle p_in){
    m_all_p.push_back(p_in);
  }

  // Add n particles to the trap
  void PenningTrap::add_n_particle(int n, double q_in, double m_in, vec r_in, vec v_in){
    for (int i=0; i < n; i++){
      // Create new Particle
      Particle new_p(q_in, m_in, r_in, v_in);

      // Add to trap
      //m_all_p.push_back(new_p) // Remove the need for the prior method
      add_particle(new_p);
    }
  }

  // External electric field at point r=(x,y,z)
  vec PenningTrap::external_E_field(vec r){
    //vec r = m_all_p[i].m_r;
    r(0) = r(0)*-2;
    r(1) = r(1)*-2;
    r(2) = r(2)*4;
    return (-(m_V0/(2*m_d*m_d))*r);
  }

  // External magnetic field at point r=(x,y,z)
  vec PenningTrap::external_B_field(vec v){
  //vec r = m_all_p[i].m_v;
  vec B = vec({0,0,m_B0});
  return(cross(v,B));
  }

  // The total force on particle_i from the external fields
  vec PenningTrap::total_force_external(int i){
    return(m_all_p[i].m_q*
    (external_E_field(m_all_p[i].m_r)+external_B_field(m_all_p[i].m_v))
    );
  }

  // Force on particle_i from particle_j
  vec PenningTrap::force_particle(int i, int j){
    double q = m_all_p[j].m_q;
    vec rj = m_all_p[j].m_r;
    vec r = m_all_p[i].m_r;
    vec diff = r-rj;
    double abso = sqrt(diff(0)*diff(0)+diff(1)*diff(1)+diff(2)*diff(2));
    double denominator = abso*abso*abso;
    return( q*diff/denominator );
  }

  // The total force on particle_i from the other particles
  vec PenningTrap::total_force_particles(int i){
    vec sum = vec({0,0,0});
    int siz = m_all_p.size();
    for (int j=0; j<siz; j++){
      if (j != i){
        sum += force_particle(i,j);
      }
    }
    return(m_ke*sum);
  }

  // The total force on particle_i from both external fields and other particles
  vec PenningTrap::total_force(int i){
    return(total_force_external(i)+total_force_particles(i));
  }

  // // Evolve the system one time step (dt) using Forward Euler
  // void evolve_Euler_Cromer(double dt){
  //   int i = 0;
  //   Particle::m_v = Particle::m_v + dt*total_force_external(i);
  //   Particle::m_r = Particle::m_r + dt*Particle::m_v;
  // }

//////////






/*


  

  // Evolve the system one time step (dt) using Runge-Kutta 4th order
   void evolve_RK4(double dt);
 */

