#include "alg.hpp"

// Sets up and returns a tridiagonal matrix A of size N
arma::mat matrix(double N)
{
    mat A = mat(N,N).fill(0.)
    for (int i=0; i < N ; i++){  
        double A(i,i) = 2;
    }
    // Controlled to test with size N = 3 first
    double A(1,0) =  1;
    double A(1,2) = 1;
    double A(2,0) = 1;
    double A(2,2) = 1;

    return(A);
}

tuple<arma::vec, arma::mat> solveig(arma::mat A)
{
    arma::vec eigval;
    arma::mat eigvec;
    // Solve Eigen values and vector
    arma::eig_sym(eigval,eigvec,A);
    // Normalize
    arma::vec eigval = arma::normalise(eigval);
    arma::vec eigvec = arma::normalise(eigvec);

    return{eigval,eigvec};
}