#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    /*  //Oppgave 3
    // initiazlization
    vec eigval;
    mat eigvec; 
    double N = 6;
    mat A = mat(N,N).fill(0.);
    mat v = mat(N,N).fill(0.);
    vec lam = vec(N).fill(0.);

    // sets up tridiagonal matrix A for size N
    matrix(N,A);
    // eig_sym
    eig_sym(eigval,eigvec,A);
    // analytisk eig
    eigen(N,lam,v);
    // normalize
    v = normalise(v);

    
    cout << "This is the matrix: " << endl << A << endl;
    cout << "eig_sym eigenvalues: " << endl << eigval << endl;
    cout << "eig_sym eigenvectors: " << endl << eigvec << endl;
    cout << "Analytical eigenvalues: " << endl << lam << endl;
    cout << "Normalized analytical eigenvectors: " << endl << v << endl;
    */

    //Oppgave 4
    int k,l = 0;
    mat Z(4,4, fill::eye);
    for (int i = 0; i < 4; i++){
        Z(i,4-1-i) = 0.5; 
    }
    Z(3,2) = 32;

    cout << "Matrix: " << endl << Z << endl;
    cout << "The maximum value of all off-diagaonal element is: "
        <<max_offdiag_symmetric(Z,k,l) << endl;
    cout << "The index for this maximum off-diagonal element is: "
        << k << ".row and " << l << ".column" << endl;

    // Done
    return 0;
}