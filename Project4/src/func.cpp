#include "func.hpp"

// Constructor Definition
Lattice::Lattice(double N_in, double T_in){
    S_ = mat(N_in,N_in);
    Snew_ = = mat(N_in,N_in);
    L_ = N_in;
    beta_ = 1./(kb*T_in);
}

// Generate a Random Spin Configuration
mat Lattice::S_gen(){
    int randNum;
    int A(L_,L_);
    srand(time(NULL)); // Seed Generate
    for (int i = 0;i< L_; i++){
        for(int j = 0;j< L_; j++){
            int randNum = rand() % 2;
            if(randNum == 0){
                randNum = -1;
            }
            A(i,j) = randNum;
        }
    }
    return A;
}

// Periodic Boundary Condition
int Lattice::Periodic(int i, int L){
    int correct_index = (i+L) % L;
    return correct_index;
}

// Calculate Total Energy in a given Spin Configuration
int Lattice::E(mat S){
    int E = 0;
    int L = sqrt(S.size());
    for (int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            int s_elem = S(i,j);
            int up = s_elem * S(Periodic(i-1,L),Periodic(j,L));
            int right = s_elem * S(Periodic(i,L),Periodic(j+1,L));
            E += up + right;
        }
    }
    return E;
}

// // Calculate Total Energy of all possible states
// int Lattice::E_all(){
//     int size = all_S.size();
//     int all = 0;
//     for (int i=0; i<size-1; i++){
//         all += E(all_S[i]);
//     }
//     return all;
// }

// // Partition Function Calculation
// void Lattice::Z(){
//     int size = all_S.size();
//     Z_all = 0;
//     for (int i=0; i<size; i++){
//         Z_all += exp(beta_*E(all_S[i]));
//     }
//     Z_ = Z_all;
// }

// Probability Function for a given state S
double Lattice::p(mat S){
    return ( (1/Z_)*exp(beta_*E(S)) );
}



////////##################IDK#####################////////

// // Generate 1 of 16 possible states of 2x2 System
// mat Lattice::S2(int a, int b, int c, int d){
//     if(a == 0){ 
//         a = -1;
//     }
//     if(b == 0){
//         b = -1;
//     }
//     if(c == 0){
//         c = -1;
//     }
//     if(d == 0){
//         d = -1;
//     }
//     arma::mat A = arma::mat(2,2);
//     A(0,0) = a;
//     A(0,1) = b;
//     A(1,0) = c;
//     A(1,1) = d;
//     return A;
// }

// // Generate all 16 possible states of 2x2 System
// void Lattice::S2_all(){
//     for (int a = 0; a<2; a++){
//         for (int b = 0; b<2; b++){
//             for (int c = 0; c<2; c++){
//                 for (int d = 0; d<2; d++){
//                     mat S_ = S2(a,b,c,d);
//                     all_S.push_back(S_);
//                 }
//             }
//         }
//     }
    
// }