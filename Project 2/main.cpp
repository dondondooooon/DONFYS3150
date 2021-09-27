#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    // Initiazlization
    // vec eigval;
    // mat eigvec; 
    int k,l = 0.0;
    double N = 3;
    // vec lam = vec(N).fill(0.);
    // mat v = mat(N,N).fill(0.);
    mat A = mat(N,N).fill(0.);
    mat R = mat(N,N,fill::eye);


    // // Oppgave 3
    // // Sets up tridiagonal matrix A for size N
    // matrix(N,A);
    // // Armadillo Eigen-solver
    // eig_sym(eigval,eigvec,A);
    // // Analytisk Eigen-solver
    // eigen(N,lam,v);
    // // Normalize
    // v = normalise(v);

    
    // cout << "This is the matrix: " << endl << A << endl;
    // cout << "eig_sym eigenvalues: " << endl << eigval << endl;
    // cout << "eig_sym eigenvectors: " << endl << eigvec << endl;
    // cout << "Analytical eigenvalues: " << endl << lam << endl;
    // cout << "Normalized analytical eigenvectors: " << endl << v << endl;
    

    //Oppgave 4
    // mat A = mat(4,4,fill::eye);
    // A(1,2) = -0.7;
    // A(2,1) = -0.7;
    // A(0,3) = 0.5;
    // A(3,0) = 0.5;
    // double max = max_offdiag_symmetric(A,k,l);

    // cout << "Matrix: " << endl << A << endl;
    // cout << "The maximum value of all off-diagaonal element is: "
    //     << max << endl;
    // cout << "The index for this maximum off-diagonal element is: "
    //     << k << ".row and " << l << ".column" << endl;

    //Oppgave 5
    matrix(N,A);
    cout << "Matrix før endring: " << endl << A << endl;

    int iter = 0;
    double eps = 1.0e-8;
    double maxiter = N*N*N;
    double max = max_offdiag_symmetric(A,k,l);
    cout << "This is the max: " << max << endl;

    for (int i = 0; i < 2; i++){
        max = max_offdiag_symmetric(A,k,l);
        rotation(A,R,k,l,N);
        cout << "Rotation Matrix: " << endl << R << endl;
        cout << "Endret Matrix: " << endl << A << endl;
    }

    // while ( (max > eps) && (double(iter) < maxiter)){
    //     rotation(A,R,k,l,N);
    //     max = max_offdiag_symmetric(A,k,l);
    //     cout << "Rotation Matrix: " << endl << R << endl;
    //     cout << "Endret Matrix: " << endl << A << endl;
    //     cout << "max: " << max << endl;
    //     iter++;
    //     cout << "Interation: " << iter << endl;
    // }

    // vec jaro_eigval;
    // mat jaro_eigvec;

    // eig_sym(jaro_eigval,jaro_eigvec,A);
    // cout << "The Eigen Values: " << endl;
    // cout << eigval << endl;
    // cout << "the eigen vector: " << endl;
    // cout << eigvec << endl;
    
    // Done
    return 0;
}