#ifndef __quantum_hpp__   
#define __quantum_hpp__

#include<armadillo>
#include<random>
#include<iomanip>
#include<chrono>
#include<complex>
using namespace arma;
using namespace std;

class quantum
{
public:
 int M; // Number of points along gird axis
 int L; // Length of Inner Points
 int N; // Number of Inner Points
 double h; // Spacestep
 double dt; // Timestep
 double T; // End Time
 int tn; // Number of Time Points
 int t_iteration = 1; // Time Iteration 
 double xc; // Center Coordinate of Initial Wave Packet
 double xsig; // Initial Widths of Wave Packet
 double px; // Wave Packet Momenta
 double yc; // Center Coordinate of Initial Wave Packet
 double ysig; // Initial Widths of Wave Packet
 double py; // Wave Packet Momenta
 double v0; // 10*10*10*10*10*10*10*10*10*10 // High Potential
 cx_double r;
 cx_double dt_half;
 bool slit1; // Single Slit
 bool slit2; // Double Slit
 bool slit3; // Triple Slit
 string sim; 
 vec xvec; // Space Vector x-axis
 vec yvec; // Space Vector y-axis

 cx_mat V; // Potential Matrix
 cx_vec v; // Vectorized Potential
 cx_mat U; // Inner Points Matrix
 cx_vec u; // Initial Vectorized IP Matrix
 cx_cube grid_tid; // Cube Matrix of IP Matrices with Time
 cx_vec a; // a vector for CN method
 cx_vec b; // b vector for CN method
 sp_cx_mat A; // A matrix for CN method
 sp_cx_mat B; // B matrix for CN method
//  cx_vec new_u;
//  cx_mat U_new; 

 // Constructor 
 quantum(int M_, double h_, double dt_, double T_, double xc_,
 double xsig_, double px_, double yc_, double ysig_, double py_,
 double v0_, bool slit1in, bool slit2in, bool slit3in, string sim_);


 // Initialize Potential w/ 2 slit
 void slit_2();

 // Initialize Potential w/ 1 slit
 void slit_1();

 // Initialize Potential w/ 3 slit
 void slit_3();

 // Gaussian Wave Packet
 cx_double func(double xi, double yj);

 // Initialize & Normalize a grid point
 void wavepoints();

 // Initialize U
 void grid_init();

 // A diagonal value
 cx_double af(int k);

 // B diagonal value
 cx_double bf(int k);

 // Set up Matrix A and B
 void set_matsAB();

 // Solve A*u_new = B*u_old via Armadillo Solver for Sparse Matrices
 void solver();

 // Run Crank-Nicolson for time steps
 void Cranky();

 //printout
 void print();


};

#endif