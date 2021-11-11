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
 int kb = 1; // Boltzmann Constant
 double beta_; // Inverse Temperature
 double Z_;    // Partition Value
 vector<mat> all_S; // All Spin Configuration

 // Constructor 
 Lattice(double N);

  // Generate a Random Spin Configuration
  mat S_gen();

 // Periodic Boundary Condition
 int Periodic(int i, int L);

 // Calculate Total Energy in a Spin Configuration
 int E(mat S);

//  // Partition Function Calculation
//  void Z();

 // Probability Function for a given state S
 double Lattice::p(mat S);



//  // Generate 1 of 16 possible states of 2x2 System
//  mat S2(int a, int b, int c, int d);

//  // Generate all 16 possible states of 2x2 System
//  void S2_all();

 // // Calculate Total Energy of all possible states
 // int E_all();




};

#endif