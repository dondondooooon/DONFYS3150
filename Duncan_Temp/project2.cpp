
//including the file to run for the matric
#define _USE_MATH_DEFINES
#include "com.hpp"
using namespace std;

double max_offdiag_symmetric(const mat& A, int& k, int& l);
void rotation(mat& A, mat& R, int k, int l, double &N);

int main(){
    //open matrix filled with zeros, which then is filled with a, d, in com.cpp
    double N = 6;
    double eps = 10e-8;
    mat A = mat(N,N).fill(0.);
    mat R = mat(N,N).fill(0.);
    jacobi(A,R,N);
    cout << "This is the matrix: " << endl;
    cout << A << endl;

    //making a symmetric matrice
    mat sym_matrice = A.t()*A;

    //calculating the eigenvectors and eigenvalues


    vec eigenvalues = zeros<vec>(N);
    mat eigenvectors = mat(N,N).fill(0.);

    //analytisk løsning
    double n = N+1;
    double h = 1/n;
    double a = -1/(h*h);
    double d = 2/(h*h);
    for (int i = 0; i < N; i++){
        eigenvalues(i) = d + 2 * a * cos(((i + 1) * acos(-1)) / (N + 1.0));

    }
    cout << "analytical eigenvalues: " << endl;
    cout << eigenvalues << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            eigenvectors(j,i) = sin(((i+1)*(j+1)*M_PI)/(N + 1.0));
        }

    }

    eigenvectors = normalise(eigenvectors);
    cout << "analytical eigenvector: " << endl;
    cout << eigenvectors << endl;

     int k = 1;
     int l = 1;
     double max = max_offdiag_symmetric(A,k,l);

    while (max <= eps){

    // cout << " Matrix A: " << endl;
    // cout << A << endl;
    // cout << k << l << endl;

    rotation(A,R,k,l,N);
    max_offdiag_symmetric(A,k,l);
    }
    // cout << " Matrix A: " << endl;
    // cout << A << endl;
    cout << " Rotation matrix: " << endl;
    cout << R << endl;
    cout << A << endl;

    vec eigval;
    mat eigvec;

    eig_sym(eigval,eigvec,A);
    cout << "the eigen values: " << endl;
    cout << eigval << endl;
    cout << "the eigen vector: " << endl;
    cout << eigvec << endl;





    return 0;
}



double max_offdiag_symmetric(const mat& A, int& k, int& l){
    double N = 6;
    double max = 0.0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i!=j){
                if (fabs(A(i,j))>max){
                    max = fabs(A(i,j));
                    l = i+1;
                    k = j+1;
                }

            }
        }
    }
    // cout << "max value: " << endl;
    // cout << max << endl;
    return max;
}


void rotation(mat& A, mat& R, int k, int l, double &N){
    double c;
    double s;
    if (A(k,l) != 0.0){
        double t;
        double tau;
        tau = (A(l,l)-A(k,k))/2*A(k,l);
        if (tau > 0){
            t = 1.0/(tau + sqrt(1 + tau * tau));
        }
        else {
            t = -1.0/(-tau + sqrt(1 + tau * tau));
        }
        c = 1/(sqrt(1 + t * t));
        s = c*t;
    }
    else {
        c = 11.0;
        s = 34;
    }
    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
    a_kk = A(k,k);
    a_ll = A(l,l);
    A(k,k) = a_kk*c*c - 2*A(l,k)*c*s + a_ll*s*s;
    A(l,l) = a_kk*s*s + 2*A(l,k)*c*s + a_ll*c*c;
    //A(k,k) = A(k,k)*c*c - 2*A(l,k)*c*s + A(l,l)*s*s;
    //A(l,l) = A(k,k)*s*s + 2*A(l,k)*c*s + A(l,l)*c*c;
    A(k,l) = 0.0;
    A(l,k) = 0.0;
    //for (int i = 0; i < N; i++){
        //if (i != k && i != l){
           // A(i,k) = A(i,k)*c - A(i,l)*s;
           // A(k,i) = A(i,k);
           // A(i,l) = A(i,l)*c + A(i,k)*s;
           // A(l,i) = A(i,l);
        //}
        // R(i,k) = R(i,k)*c - R(i,l)*s;
        // R(i,l) = R(i,l)*c + R(i,k)*s;
    //}
    for (int i = 0; i < N; i++){
        if (i != k && i != l){
            A(i,k) = a_ik*c - a_il*s;
            A(k,i) = A(i,k);
            A(i,l) = a_il*c + a_ik*s;
            A(l,i) = A(i,l);
        }
        r_ik = R(i,k);
        r_il = R(i,l);
        R(i,k) = r_ik*c - r_il*s;
        R(i,l) = r_il*c + r_ik*s;
    }
}
