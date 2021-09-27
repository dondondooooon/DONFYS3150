#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    //Initiazlization
    vec eigval;
    mat eigvec; 
    double N = 3;
    int iter = 0;
    int k,l = 0.0;
    double eps = 1.0e-8;
    double maxiter = N*N*N;
    vec lam = vec(N).fill(0.);
    mat v = mat(N,N).fill(0.);
    // Sets up R_1 = I matrix
    mat R = mat(N,N,fill::eye);
    // Sets up tridiagonal matrix A for size N
    mat A = create_trimatsym(N);
    // Finds the max off-diagonal element for A
    double max = max_offdiag_symmetric(A,k,l);

    // // Oppgave 3
    // // Armadillo Eigen-solver
    //eig_sym(eigval,eigvec,A);
    // // Analytisk Eigen-solver
    // eigen(N,lam,v);
    // // Normalize
    // v = normalise(v);
    // // cout << "This is the matrix: " << endl << A << endl;
    // // cout << "Arma::Eigenvalues: " << endl << eigval << endl;
    // // cout << "Arma::Eigenvectors: " << endl << eigvec << endl;
    // // cout << "Analytical Eigenvalues: " << endl << lam << endl;
    // // cout << "Normalized Analytical Eigenvectors: " << endl << v << endl;
    

    // //Oppgave 4
    // //Test Matrix T
    // mat T = mat(4,4,fill::eye);
    // T(1,2) = -0.7;
    // T(2,1) = -0.7;
    // T(0,3) = 0.5;
    // T(3,0) = 0.5;
    // double max = max_offdiag_symmetric(T,k,l);
    // cout << "Matrix: " << endl << T << endl;
    // cout << "The maximum value of all off-diagaonal element is: "
    //     << max << endl;
    // cout << "The index for this maximum off-diagonal element is: "
    //     << k+1 << ".row and " << l+1 << ".column" << endl;


    //Oppgave 5
    cout << "Matrix før endring: " << endl << A << endl;
    cout << "This is the max: " << max << endl;

    // for (int i = 0; i < 2; i++){
    //     max = max_offdiag_symmetric(A,k,l);
    //     rotation(A,R,k,l,N);
    //     cout << "Rotation Matrix: " << endl << R << endl;
    //     cout << "Endret Matrix: " << endl << A << endl;
    // }

    while ( (max > eps) && (double(iter) < maxiter)){
        rotation(A,R,k,l,N);
        max = max_offdiag_symmetric(A,k,l);
        cout << "Rotation Matrix: " << endl << R << endl;
        cout << "Endret Matrix: " << endl << A << endl;
        cout << "max: " << max << endl;
        iter++;
        cout << "Interation: " << iter << endl;
    }

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