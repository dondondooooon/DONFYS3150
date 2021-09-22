#include "alg.hpp"

// Sets up and returns a tridiagonal matrix A of size N
void matrix(double &N, mat &A)
{
    for (int i=0; i < N ; i++){  
        A(i,i) = 2;
        /*for (int j=0; i < N ; j++){
            if (i==j)
            {
                A(i,j) = 2;
            }
            if (j+1 < N-1)
            {
                A(i,j+1) = 1;
            }
            if (j-1 < N-1)
            {
                A(i,j-1) = 1;
            }
        }*/
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