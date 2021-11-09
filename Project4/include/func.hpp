#ifndef __func_hpp__   
#define __func_hpp__

#include<armadillo>
using namespace arma;
using namespace std;

class Lattice
{
public:
 mat S_; // Spin Configuration / Matrix / Microstate
 vector<mat> all_S; // All Spin Configuration

 // Constructor 
 Lattice(double N);

 // Generate 1 of 16 possible states of 2x2 System
 mat S2(int a, int b, int c, int d);

 // Generate all 16 possible states of 2x2 System
 void S2_all();

//  // Generate a Random Spin Configuration
//  mat rand_S(double N);

// Periodic Boundary Condition
int Periodic(int i, int L);

// Calculate Total Energy in a Spin Configuration
int E(mat S);

// Calculate Total Energy of all possible states
int E_all();

//  // Calculate Magnetization in a Spin Configuration
//  int M(int y);


};

#endif