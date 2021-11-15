/*
#ifndef __isingmcmc_hpp__   
#define __isingmcmc_hpp__

#include "func.hpp"




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

 // Specific Heat Capacity
 double Cv();

 // Magnetic Susceptibility
 double Chi();

 // Metropolis Rule && 1 Cycle of Monte Carlo
 void MC_cycle();

 // Multiple Monte Carlo Cycles
 void MCMC();

 // Printout
 void print();

#endif
*/