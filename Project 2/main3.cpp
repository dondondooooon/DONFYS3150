#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    // Sets up tridiagonal matrix A for N = 6
    double N = 6;
    mat A = mat(N,N).fill(0.);
    mat v = mat(N,N).fill(0.);
    vec lam = vec(N).fill(0.);
    matrix(N,A);
    //Print check
    cout << "This is the matrix: " << endl;
    cout << A;
    
    // Eig_sym
    vec eigval;
    mat eigvec; 
    eig_sym(eigval,eigvec,A);
    cout << "eig_sym eigenvalues: " << endl << eigval << endl;
    cout << endl << "eig_sym eigenvectors: " << endl << eigvec << endl;
    
    // Analytisk Eig
    eigen(N,lam,v);
    // Normalize
    mat vnorm = normalise(v);
    cout << "Analytical eigenvalues: " << endl << lam << endl;
    //cout << "Analytical eigenvectors: " << endl << v << endl;
    cout << "Normalized analytical eigenvectors: " << endl << vnorm << endl;

    // Done
    return 0;
}