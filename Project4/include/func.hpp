#ifndef __func_hpp__   
#define __func_hpp__

#include<armadillo>
using namespace arma;
using namespace std;

class Lattice
{
public:
 int samples_; // Samples For MCMC
 int mcycles_; // Number of MCMC cycles
 mat S_; // Spin Configuration
 mat Snew_; // Proposed New Spin Configuration
 int L_;  // Length of Spin Configuration
 int J_ = 1; // Association Energy Constant
 int kb = 1; // Boltzmann Constant
 int i_flip; //
 int j_flip; //
 double T_; // Temperature
 double beta_; // Inverse Temperature

 double E_sum;
 double M_sum;
 double Eavg_; // Mean Energy
 double Mavg_; // Mean Magnetization
 double E_sqr; 
 double M_sqr;
 double E2_; // Mean Energy^2
 double M2_; // Mean Magnetization^2
 double cv_;
 double chi_;

//  vec e ;
//  vec m ;
//  vec e2;
//  vec m2;
//  vec c ;
//  vec x ;

 vec boltz_;  // Probability Vector 
 vec mcvec_; // Vector For MCMC Cycles

 // Constructor 
 Lattice(double N_in, double T_in, int samples_in, int cycles_in);

 // Generate a Random Spin Configuration
 mat S_gen();
 
 // RNG spin flip
 void S_rng();

 // Periodic Boundary Condition
 int Periodic(int i, int L);

 // Energy Around A Spin
 int E_spin(mat S, int i, int j);

 // Energy Difference
 int dE(int i, int j);

 // Probability Ratio for Energy Shift of 1 Spin Change
 double p(int dE);

 // Calculate Total Energy For A Given Spin Configuration
 int E(mat S);

 // Calculate Total Magnetization For A Given Spin Configuration
 int M(mat S);

 // MCMC Algorithm For 1 Cycle
 void MC_cycle();

 // Thats MONTE CARLO babyyyyy
 void MCMC(int cycles);

 // Specific Heat Capacity
 double Cv();

 // Magnetic Susceptibility
 double Chi();


};

#endif