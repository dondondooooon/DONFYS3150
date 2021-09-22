//
// A collection of "clever" algorithms 
//

#ifndef __alg_hpp__
#define __alg_hpp__

#include<armadillo>
using namespace arma;

// Here we use "call by reference" (the & in the argument). This
// means that this function can change the value of the original input
// variable, instead of returning a new variable. (Hence "void" as return type.)

// Sets up and returns a tridiagonal matrix A of size N
void matrix(double &N, mat &A);

// Solves for the eigen values and vectors of a given matrix
//tuple<arma::vec, arma::vec> solveig(arma::mat A);

#endif