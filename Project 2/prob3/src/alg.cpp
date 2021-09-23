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

// Sets up the analytical eigen values and vectors
void eigen(double& N, vec& lam, mat& v)
{
    double n = N+1;
    double h = 1/n;
    double a = -1/(h*h);
    double d = 2/(h*h);
    for (int i=0; i< N; i++){
        lam(i) = d + 2*a*cos(((i+1)*M_PI)/(N+1));
        for (int j=0; j < N; j++){
            v(j,i) = sin(((j+1)*(i+1)*M_PI)/(N+1));
        }
    }
}
