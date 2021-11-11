#ifndef __func_hpp__   
#define __func_hpp__

#include<armadillo>
using namespace arma;
using namespace std;

class Lattice
{
public:
 mat S_; // Spin Configuration
 mat Snew_; // Proposed New Spin Configuration
 int L_;  // Length of Spin Configuration
 int J_ = 1; // Association Energy
 int kb = 1; // Boltzmann Constant
 double beta_; // Inverse Temperature
 int i_flip;
 int j_flip;
 vec Ediff = vec({8.*J_, 4.*J_, 0., -4.*J_, -8.*J_});
 vector<mat> all_S; // All Spin Configuration

 // Constructor 
 Lattice(double N_in, double T_in);

 // Generate a Random Spin Configuration
 mat S_gen();
 
 // RNG spin flip
 void S_rng();

 // Periodic Boundary Condition
 int Periodic(int i, int L);

 // Energy Around A Spin
 int E_spin(mat S, int i, int j);

 // Energy Difference
 int delta_E(int i, int j);

 // Probability Ratio for Energy Shift of 1 Spin Change
 double p(int dE);

 // Calculate Total Energy For A Given Spin Configuration
 int E(mat S);

//  // Partition Function Calculation
//  void Z();

//  // Probability Function for a given state S
//  double p(mat S);



//  // Generate 1 of 16 possible states of 2x2 System
//  mat S2(int a, int b, int c, int d);

//  // Generate all 16 possible states of 2x2 System
//  void S2_all();

 // // Calculate Total Energy of all possible states
 // int E_all();




};

#endif