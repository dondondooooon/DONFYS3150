#include "alg.hpp"

// Sets up and returns a tridiagonal matrix A of size N
mat create_trimatsym(double N)
{
    double n = N+1;
    double h = 1/n;
    double a = -1/(h*h);
    double d = 2/(h*h);
    mat A = mat(N,N,fill::eye) * d;
    for (int i=0; i < N ; i++){  
        if (i+1<N){
            A(i,i+1) = a;
        }
        if (i-1>=0){
            A(i,i-1) = a;
        }
    }
    return A;
}

// Sets up the analytical eigen values and vectors
void analytisk_eigen(double& N, vec& lam, mat& v)
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

// Max. Off-Diagonal Alg.
double max_offdiag_symmetric(const mat& A, int& k, int& l){
    double max = 0.0;
    for (int i = 0; i < A.n_rows; i++){
        for (int j = 0; j < A.n_rows; j++){
            //Loops through only lower tri, which is ok coz symmetric:D
            if (i!=j && i<j){
                if (fabs(A(i,j))>max){
                    max = fabs(A(i,j));
                    k = i;
                    l = j;
                }
            }
                
            }
        }
    return (max);
}

// Jacobi Rotation Algorithm
void rotation(mat& A, mat& R, int k, int l, double N){
    double c,s; 
    // Calculate cos and sin
    if (A(k,l) != 0.0){
        double t,tau;
        tau = (A(l,l)-A(k,k))/(2*A(k,l));
        if (tau > 0){
            t = 1.0/(tau + sqrt(1.0 + tau * tau));
        }
        else {
            t = -1.0/(-tau + sqrt(1.0 + tau * tau));
        }

        c = 1/(sqrt(1 + t * t));
        s = c*t;
    }
    else {
        c = 1.0;
        s = 0.0;
    }
    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
    a_kk = A(k,k);
    a_ll = A(l,l);
    // Change the Matrix Elements with indices k and l
    A(k,k) = a_kk*c*c - 2*A(l,k)*c*s + a_ll*s*s;
    A(l,l) = a_kk*s*s + 2*A(l,k)*c*s + a_ll*c*c;
    A(k,l) = 0.0;
    A(l,k) = 0.0;
    // Change remaining elements
    for (int i = 0; i < N; i++){
        if (i != k && i != l){
            a_ik = A(i,k);
            a_il = A(i,l);
            A(i,k) = a_ik*c - a_il*s;
            A(k,i) = A(i,k);
            A(i,l) = a_il*c + a_ik*s;
            A(l,i) = A(i,l);
        }
        // Compute New Eigenvectors
        r_ik = R(i,k);
        r_il = R(i,l);
        R(i,k) = r_ik*c - r_il*s;
        R(i,l) = r_il*c + r_ik*s;
    }
}

// Solve Eigen values and vectors via Jacobi Rotation Method
void jacobi_eigen(mat& A, mat& R, double N, int& k, int& l, double& max, double eps,
vec& eigval, mat& eigvec, const int maxiter, int& iter, bool& converged){

    while ( (max > eps) && (double(iter) < maxiter)){
        rotation(A,R,k,l,N);
        max = max_offdiag_symmetric(A,k,l);
        iter++;
    }
    for (int i = 0; i < A.n_rows; i++){
        eigval(i) = A(i,i);
    }
    eigval = sort(eigval);
    eigvec = R;
    converged = !converged;
 }