#include<iostream>
#include<armadillo>
#include <cmath>
using namespace arma;
using namespace std;

int main()
{
    double x = 1/6;
    cout << x << endl;

 return 0;
}







































/*
class Particle 
{
public:
  double m_q; // Charge
  double m_m; // Mass
  vec m_r; // Position
  vec m_v; // Velocity
  cube m_cr; // Cube_Position
  cube m_cv; // Cube_Velocity

  // Constructor 1
  Particle(double q_in, double m_in,vec r_in, vec v_in);

  // Constructor 2
  Particle(int p_size_in, int n_in);
};

class PenningTrap
{
public: // Public 
  double m_B0;  // Magnetic Field Strength
  double m_V0;  // Applied Potential
  double m_d;   // Characteristic Dimension
  double m_ke;  // Columbs Constant
  vector<Particle> m_all_p;  // All particles

  // Constructor
  PenningTrap(double B0_in, double V0_in, double d_in);

  void blank();

int main()
{
    Particle poop(1,1,{1,1,1},{0,2,0});
    cout << poop.m_r << endl;
    cout << poop.m_cv << endl;

 return 0;
}

// Constructor 1
Particle::Particle(double q_in, double m_in, vec r_in, vec v_in){
  m_q = q_in; // Charge
  m_m = m_in; // Mass
  m_r = r_in; // Position
  m_v = v_in; // Velocity
}

// Constructor 2
Particle::Particle(int p_size_in, int n_in){
    m_cv = cube(3,p_size_in,n_in);  // Cube for velocity
    m_cr = cube(3,p_size_in,n_in); // Cube for position
}

// Constructor Definition
PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in){
  m_B0 = B0_in; // Magnetic Field Strength
  m_V0 = V0_in; // Applied Potential
  m_d = d_in; // Characteristic Dimension
  m_ke = 1.38935333*pow(10,5); // Columbs Constant
}

void PenningTrap::blank(){
    Particle coob(2,10);
}
*/