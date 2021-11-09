#include "PenningTrap.hpp"
#include "Particle.hpp"

// Constructor Definition
PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in, bool colm_in){
  m_B0 = B0_in; // Magnetic Field Strength
  m_V0 = V0_in; // Applied Potential
  m_d = d_in; // Characteristic Dimension
  m_ke = 1.38935333*pow(10,5); // Columbs Constant
  m_colm = colm_in; // Particle Interaction; on or off: true or false
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
    r(0) = r(0)*-2;
    r(1) = r(1)*-2;
    r(2) = r(2)*4;
    return (-(m_V0/(2*m_d*m_d))*r);
  }

  // External magnetic field at point r=(x,y,z)
  vec PenningTrap::external_B_field(vec v){
  vec B = vec({0,0,m_B0});
  return(cross(v,B));
  }

  // The total force on particle_i from the external fields
  vec PenningTrap::total_force_external(int i){
    return m_all_p[i].m_q*external_E_field(m_all_p[i].m_r)+
    external_B_field(m_all_p[i].m_q*m_all_p[i].m_v);
  }

  // Force on particle_i from particle_j
  vec PenningTrap::force_particle(int i, int j){
    double q = m_all_p[j].m_q;
    vec rj = m_all_p[j].m_r;
    vec r = m_all_p[i].m_r;
    vec diff = r-rj;
    double abso = norm(diff);
    double denominator = abso*abso*abso;
    return q*(diff/denominator);
  }

  // The total force on particle_i from the other particles
  vec PenningTrap::total_force_particles(int i){
    vec sum = vec({0,0,0});
    for (int j=0; j<m_psize; j++){
      if (j != i){
        sum += force_particle(i,j);
      }
    }
    return m_ke*sum;
  }

  // The total force on particle_i from both external fields and other particles
  vec PenningTrap::total_force(int i){
    if (m_colm == false){  // Without particle interaction
      return(total_force_external(i));
    }
    else { // With particle interaction
      return(total_force_external(i)+total_force_particles(i));
    }
  }

  // Evolve the system one time step (dt) using Runge-Kutta 4th order
  void PenningTrap::evolve_RK4(double dt, int i, int j){
    double m = m_all_p[j].m_m; // mass
    vec v_old = V_.slice(i-1).col(j); // Save orig v
    vec r_old = R_.slice(i-1).col(j); // Save orig r
    // Integration:
    //k1
    vec acc = total_force(j)/m; // acc = Acceleration (N2L)
    vec v_k1 = dt * acc;
    vec r_k1 = dt * v_old;
    //k2
    m_all_p[j].m_v = v_old + v_k1/2;
    m_all_p[j].m_r = r_old + r_k1/2;
    acc = total_force(j)/m; // Calc. acc for new v & r
    vec v_k2 = dt * acc;
    vec r_k2 = dt * m_all_p[j].m_v;
    //k3
    m_all_p[j].m_v = v_old + v_k2/2;
    m_all_p[j].m_r = r_old + r_k2/2;
    acc = total_force(j)/m; // Calc. acc for new v & r
    vec v_k3 = dt * acc;
    vec r_k3 = dt * m_all_p[j].m_v;
    //k4
    m_all_p[j].m_v = v_old + v_k3;
    m_all_p[j].m_r = r_old + r_k3;
    acc = total_force(j)/m; // Calc. acc for new v & r
    vec v_k4 = dt * acc;
    vec r_k4 = dt * m_all_p[j].m_v;
    // Combine
    V_.slice(i).col(j) = v_old+(v_k1+2*v_k2+2*v_k3+v_k4)/6;  // Endelig hastighet
    R_.slice(i).col(j) = r_old+(r_k1+2*r_k2+2*r_k3+r_k4)/6;  // Endelig posisjon
    // Reset for next particle
    m_all_p[j].m_v = v_old;
    m_all_p[j].m_r = r_old;
  }

  // Evolve the system one time step (dt) using Forward Euler
  void PenningTrap::evolve_Euler_Cromer(double dt, int i, int j){
    double m = m_all_p[j].m_m; // mass
    vec v_old = V_.slice(i-1).col(j); // Save orig v
    vec r_old = R_.slice(i-1).col(j); // Save orig r
    // Integration
    vec acc = total_force(j)/m;
    V_.slice(i).col(j) = v_old + dt*acc;
    R_.slice(i).col(j) = r_old + dt*V_.slice(i).col(j);
    // Reset for next particle
    m_all_p[j].m_v = v_old;
    m_all_p[j].m_r = r_old;
  }

  // Full Evolution of our simulation
  void PenningTrap::full_evolution(double dt, double n, int psiz){
    m_psize = psiz; // number of particles
    V_ = cube(3,m_psize,n).fill(0.);
    R_ = cube(3,m_psize,n).fill(0.);
    // Initialize first values of cube matrixes
    for (int j=0;j<m_psize;j++){
      V_.slice(0).col(j) = m_all_p[j].m_v;
      R_.slice(0).col(j) = m_all_p[j].m_r;
    }
    for (int i=1;i<n;i++){
      for (int j=0;j<m_psize;j++){
          evolve_RK4(dt,i,j); // RK4 method
          // evolve_Euler_Cromer(dt,i,j); // EC method
      }
    }
  }