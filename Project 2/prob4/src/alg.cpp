#include "alg.hpp"

// Sets up and returns a tridiagonal matrix A of size N
void matrix(double &N, mat &A)
{
    double n = N+1;
    double h = 1/n;
    double a = -1/(h*h);
    double d = 2/(h*h);
    for (int i=0; i < N ; i++){  
        A(i,i) = d;
        if (i+1<N){
            A(i,i+1) = a;
        }
        if (i-1>=0){
            A(i,i-1) = a;
        }
    }
}
