#ifndef __isingmodel_hpp__   
#define __isingmodel_hpp__

#include<armadillo>
#include<random>
#include<iomanip>
#include<chrono>
using namespace arma;
using namespace std;

class Ising
{
private:
 double E_; // Energy of Microstate
 double M_; // Magnetization of Microstate
 double Esum; // Sum of Energy of Microstate
 double Msum; // Sum of Magnetization of Microstate
 double Eavg; // Mean Energy
 double Mavg; // Mean Magnetization
 double E2_; // Energy^2 of Microstate
 double M2_; // Magnetization^2 of Microstate
 double Esqrd; // Mean Energy^2
 double Msqrd; // Mean Magnetization^2

 int L_;  // Length of Spin Configuration
 int N_; // Number of Spins
 int tsize_; // Size of Temperature Vector
 int mc_cycles_; // Number of MCMC cycles
 int i_flip; // Row Flip Index
 int j_flip; // Column Flip Index
 double beta_; // Inverse Temperature
 double cnorm_; // Normalizing MC cycles Factor
 vec bvec_; // Inverse Temperature Vector
 vec boltz_ = vec(17).fill(0.);  // Delta Energy Values
 vec Tvec_; // Temperature Vector
 mat S_; // Spin Configuration

public:
 double kb = 1.; // Boltzmann Constant
 int J_ = 1; // Association Energy Constant

 // RNG Declaration
 random_device rando;
 mt19937_64 generate;

 uniform_real_distribution<double> distribution_double;
 uniform_int_distribution<int> distribution_int;

 // Constructor 
 Ising(int L_in, vec Tvec_in, int cycles_in);

 // Initial Spin Configuration
 void start_config(bool order);

 // Periodic Boundary Condition
 int Periodic(int i, int L);

 // Calculate Total Energy For A Given Spin Configuration
 int E(mat S);

 // Calculate Total Magnetization For A Given Spin Configuration
 int M(mat S);

 // Energy Around The Chosen Spin
 int E_spin(int i, int j);

 // Energy Difference
 int dE(int i, int j);

 // Delta Energy Values
 void dE_values();

 // Probability Ratio for Energy Shift of 1 Spin Change
 double p(int dE);


 // Metropolis Rule
 void metropolis();

 // Monte Carlo
 void monte_carlo();

 // Parallellized Temperature Monte Carlo plots
 void paratemp();

 // Temperature Monte Carlo plots
 void mc_temp();

 // Cycles Monte Carlo plots
 void cycle_plot(double temperature, string t);

 // Printout for T = 1
 void printT1();

};

#endif