#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    // Sets up tridiagonal matrix A for N = 6
    double N = 6;
    mat A = mat(N,N).fill(0.);
    matrix(N,A);
    //Print check
    cout << "This is the matrix: " << endl;
    cout << A;
    
    // Solve eigen things:^))
    vec eigval;
    mat eigvec; 
    eig_sym(eigval,eigvec,A);
    // Normalize
    //mat envec = normalise(eigvec,1,0);
    //Print check
    cout << "This is the eigenvalues; " << endl << eigval << endl;
    cout << endl << "This is the eigenvectors in a matrix: " << endl << eigvec << endl;
    //cout << endl << "Normalized egenvektor: " << endl << envec << endl;

    cout << endl << "Normal?: " << endl << eigval.row(0)/normalise(eigval.row(0),1) << endl;
    // Done
    return 0;
}