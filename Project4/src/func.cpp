#include "func.hpp"

// Constructor Definition
Lattice::Lattice(double N){
    S_ = mat(N,N);
}

// Generate 1 of 16 possible states of 2x2 System
mat Lattice::S2(int a, int b, int c, int d){
    if(a == 0){ 
        a = -1;
    }
    if(b == 0){
        b = -1;
    }
    if(c == 0){
        c = -1;
    }
    if(d == 0){
        d = -1;
    }
    arma::mat A = arma::mat(2,2);
    A(0,0) = a;
    A(0,1) = b;
    A(1,0) = c;
    A(1,1) = d;
    return A;
}

// Generate all 16 possible states of 2x2 System
void Lattice::S2_all(){
    for (int a = 0; a<2; a++){
        for (int b = 0; b<2; b++){
            for (int c = 0; c<2; c++){
                for (int d = 0; d<2; d++){
                    mat S_ = S2(a,b,c,d);
                    all_S.push_back(S_);
                }
            }
        }
    }
    
}

// // Generate a Random Spin Configuration
// mat rand_S(double N, mat A){
// int randNum;
// srand(time(NULL));
//     for (int i = 0;i< N; i++){
//         for(int j = 0;j< N; j++){
//             int randNum = rand() % 2;
//             if(randNum == 0){
//                 randNum = -1;
//             }
//             A(i,j) = randNum;
//         }
//     }
// }

// Periodic Boundary Condition
int Lattice::Periodic(int i, int L){
    int correct_index = (i+L) % L;
    return correct_index;
}

// Calculate Total Energy in a Spin Configuration
int Lattice::E(mat S){
    int E = 0;
    int N = S.size();
    int L = sqrt(N);
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int s_elem = S(i,j);
            int up = s_elem * S(Periodic(i-1,L),Periodic(j,L));
            int right = s_elem * S(Periodic(i,L),Periodic(j+1,L));
            E += up + right;
        }
    }
    return E;
}

// Calculate Total Energy of all possible states
int Lattice::E_all(){
    int size = all_S.size();
    int all = 0;
    for (int i=0; i<size-1; i++){
        all += E(all_S[i]);
    }
    return all;
}


// // Calculate Magnetization in a Spin Configuration
// int M(mat S){
//     return S;
// }
//////////


// double P_MS(double Energy);
// double P_MS(double Energy){ //Probablity for microstate.
//     int beta = 1;
//     double pms = exp(-beta * Energy) /(12 + 4 * cosh(8 * beta));
//     return pms;
// }