#include "com.hpp"

//defining the matrix
//void matrix(double &N, mat &A){


void jacobi(mat &A, mat &R, double &N){
    //int k, l; 
    double n = N+1;
    double h = 1/n;
    double a = -1/(h*h);
    double d = 2/(h*h);
    for (int i = 0; i < N; i++){
        A(i,i) = d;
        if (i+1<N){
            A(i, i+1) = a;
        }
        if (i-1>=0) {
            A(i,i-1) = a;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                R(i,j) = 1.0;
            }
            else {
                R(i,j) = 0.0;
            }
        }
    }
}

