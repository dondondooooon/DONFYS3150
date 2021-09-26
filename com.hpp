#ifndef __com_hpp__
#define __com_hpp__

//including all the elements needed to run code
#include <armadillo>
#include <sstream> 
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <math.h>
using namespace arma;

//void matrix(double &N, mat &A);
void jacobi(mat& A, mat& R, double &N);

#endif