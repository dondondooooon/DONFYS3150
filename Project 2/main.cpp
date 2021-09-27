#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    //Initiazlization
    vec arma_eigval;
    mat arma_eigvec; 
    vec jaro_eigval;
    mat jaro_eigvec;
    int k,l = 0.0;
    int iter = 0;
    double N = 3;
    double eps = 1.0e-8;
    double maxiter = N*N*N;
    bool converged {false};
    vec anl_eigval = vec(N).fill(0.);
    mat anl_eigvec = mat(N,N).fill(0.);
    // Sets up R_1 = I matrix
    mat R = mat(N,N,fill::eye);
    // Sets up tridiagonal matrix A for size N
    mat A = create_trimatsym(N);
    // Finds the max off-diagonal element for A
    double max = max_offdiag_symmetric(A,k,l);


    // // Oppgave 3
    // // Armadillo Eigen-solver
    //eig_sym(arma_eigval,arma_eigvec,A);
    // // Analytisk Eigen-solver
    // analytisk_eigen(N,anl_eigval,anl_eigvec);
    // // Normalize
    // anl_eigvec = normalise(anl_eigvec);
    // // cout << "This is the matrix: " << endl << A << endl;
    // // cout << "Arma::Eigenvalues: " << endl << arma_eigval << endl;
    // // cout << "Arma::Eigenvectors: " << endl << arma_eigvec << endl;
    // // cout << "Analytical Eigenvalues: " << endl << anl_eigval << endl;
    // // cout << "Normalized Analytical Eigenvectors: " << endl << anl_eigvec << endl;
    

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

    jacobi_eigen(A,R,N,k,l,max,eps,jaro_eigval,jaro_eigvec,
    maxiter,iter,converged);

    cout << "This is the max: " << max << endl;
    cout << "Iterations: " << iter << endl;
    cout << "Egenvalues in diagonal " << endl << A << endl;
    cout << "Rotation Matrix/Egenvectors: " << endl << R << endl;

    //jaro_eigval =
    //jaro_eigvec = 

    // Done
    return 0;
}