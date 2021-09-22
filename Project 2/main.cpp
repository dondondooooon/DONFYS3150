#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    double N = 3;
    mat A = mat(N,N).fill(0.);
    matrix(N,A);
    cout << "This is the matrix: " << endl;
    cout << A;
    
    // Done
    return 0;
}