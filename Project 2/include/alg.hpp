//
// A collection of "clever" algorithms 
//

#ifndef __alg_hpp__
#define __alg_hpp__

#include<math.h>
#include<tgmath.h>
#include<armadillo>
using namespace arma;

// Here we use "call by reference" (the & in the argument). This
// means that this function can change the value of the original input
// variable, instead of returning a new variable. (Hence "void" as return type.)

// Sets up and returns a tridiagonal matrix A of size N
mat create_trimatsym(double N);

// Analytical Eigensolver
void analytisk_eigen(double& N, vec& lam, mat& B);

// Max. Off-Diagonal Element and returns the value
double max_offdiag_symmetric(const mat& A, int& k, int &l);

// Jacobi Rotation Algorithm
void rotation(mat& A, mat& R, int k, int l, double N);

// Jacobi Eigensolver
void jacobi_eigen(mat& A, mat& R, double N, int& k, int& l, double& max, double eps,
vec& eigval, mat& eigvec, const int maxiter, int& iter, bool& converged);


#endif