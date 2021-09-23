//Include guard: ensures that this header file can only
//end up being included *once* for the compilation of any given .cpp file
#ifndef __utils_hpp__  
#define __utils_hpp__

// Headers
#include <armadillo>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
using namespace arma;

// Utility Function Declarations

// Return a string with a double in scientific notation
std::string scientific_format(double d, const int width=20, const int prec=10);

// Return a string with an armadillo vector in scientific notation
std::string scientific_format(const arma::vec& v, const int width=20, const int prec=10);

#endif  // end of include guard __utils_hpp__