//
// A collection of "clever" algorithms 
//

#ifndef __alg_hpp__
#define __alg_hpp__

#include<math.h>
#include<armadillo>
using namespace arma;

// Here we use "call by reference" (the & in the argument). This
// means that this function can change the value of the original input
// variable, instead of returning a new variable. (Hence "void" as return type.)

// Sets up and returns a tridiagonal matrix A of size N
void matrix(double &N, mat &A);

// Sets up the analytical eigenvalues and vectors
void eigen(double& N, vec& lam, mat& B);

#endif