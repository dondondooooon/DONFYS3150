#include "alg.hpp"

// Sets up and returns a tridiagonal matrix A of size N
void matrix(double &N, mat &A)
{
    double h = 1/N;
    double a = -1/(h*h);
    double d = 2/(h*h);
    for (int i=0; i < N ; i++){  
        A(i,i) = 2;
        if (i+1<N){
            A(i,i+1) = -1;
        }
        if (i-1>=0){
            A(i,i-1) = -1;
        }
    }
}
/*
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
*/