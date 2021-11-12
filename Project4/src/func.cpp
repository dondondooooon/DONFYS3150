#include "func.hpp"

// Constructor Definition
Lattice::Lattice(double N_in, double T_in, int samples_in, int cycles_in){
    samples_ = samples_in;
    mcycles_ = cycles_in;
    // S_ = mat(N_in,N_in);
    // Snew_ = mat(N_in,N_in);
    L_ = N_in;
    T_ = T_in;
    beta_ = 1./(kb*T_);
    boltz_ = vec(17);
    for (int i=0; i<17; i+=4){
        boltz_(i) = exp(-beta_*(i-8)*J_);
    }
    // mcvec = vec()
    // vec e = vec(cycles_in);
    // vec m = vec(cycles_in);
    // vec e2 = vec(cycles_in);
    // vec m2 = vec(cycles_in);
    // vec c = vec(cycles_in);
    // vec x = vec(cycles_in);
}

// Generate a Random Spin Configuration For Initial Spin Configuration
mat Lattice::S_gen(){
    int randNum;
    mat A = mat(L_,L_).fill(0.);
    srand(time(NULL)); // Seed Generate
    for (int i = 0;i< L_; i++){
        for(int j = 0;j< L_; j++){
            randNum = rand() % 2;
            if(randNum == 0){
                randNum = -1;
            }
            A(i,j) = randNum;
        }
    }
    return A;
}

// RNG Spin Flip
void Lattice::S_rng(){
    Snew_ = S_;
    srand(time(NULL)); // Seed Generate
    i_flip = rand() % L_;
    j_flip = rand() % L_;
    Snew_(i_flip,j_flip) = Snew_(i_flip,j_flip) * -1; // Flip that spin
}

// Periodic Boundary Condition
int Lattice::Periodic(int i, int L){
    int correct_index = (i+L) % L;
    return correct_index;
}

// Energy Around A Spin
int Lattice::E_spin(mat S, int i, int j){
    int s = S(i,j);
    int up = s * S(Periodic(i-1,L_),Periodic(j,L_));
    int down = s * S(Periodic(i+1,L_),Periodic(j,L_));
    int left = s * S(Periodic(i,L_),Periodic(j-1,L_));
    int right = s * S(Periodic(i,L_),Periodic(j+1,L_));
    return up+down+left+right;
}

// Energy Difference
int Lattice::dE(int i, int j){
    int E_before = E_spin(S_, i_flip, j_flip);
    int E_after = E_spin(Snew_, i_flip, j_flip);
    return E_after-E_before;
}

// Probability Ratio for Energy Shift of 1 Spin Change
double Lattice::p(int dE){
    return boltz_[dE+8];
}

// Calculate Total Energy For A Given Spin Configuration
int Lattice::E(mat S){
    int E = 0;
    for (int i=0; i<L_; i++){
        for(int j=0; j<L_; j++){
            int s_elem = S(i,j);
            int up = s_elem * S(Periodic(i-1,L_),Periodic(j,L_));
            int right = s_elem * S(Periodic(i,L_),Periodic(j+1,L_));
            E += up + right;
        }
    }
    return -J_*E;
}

// Calculate Total Magnetization For A Given Spin Configuration
int Lattice::M(mat S){
    int M = 0;
    for (int i=0; i<L_; i++){
        for(int j=0; j<L_; j++){
            M += abs(S(i,j));
        }
    }
    return M;
}

 // Metropolis Rule && 1 Cycle of Monte Carlo
 void Lattice::MC_cycle(){
    for (int i=1; i<samples_; i++){
        //int E_old = E(S_);
        S_rng();
        //int E_new = E(Snew_);

        double accept = p(dE(i_flip,j_flip));
        
        double r = randu();
        if (r <= accept){
            S_ = Snew_;
        }

        E_sum += E(S_);
        M_sum += M(S_);
        E_sqr += E_sum*E_sum;
        M_sqr += M_sum*M_sum;

        // Eavg_ += E_sum / i;
        // Mavg_ += M_sum / i;
        // E2_ += E_sqr/ i;
        // M2_ += M_sqr/ i;
    }

    // Eavg_ = E_sum / samples_;
    // Mavg_ = M_sum / samples_;
    // E2_ = E_sqr / samples_;
    // M2_ = M_sqr / samples_;
 }

 // Multiple Monte Carlo Cycles
 void Lattice::MCMC(int cycles){
    // mat S_old = S_;
    for (int i=0; i<cycles; i++){
        // S_ = S_gen();
        // S_ = S_old;

        E_sum = 0;
        M_sum = 0;
        E_sqr = 0;
        M_sqr = 0;

        MC_cycle();

        Eavg_ += E_sum / samples_ / cycles;
        Mavg_ += M_sum / samples_ / cycles;
        E2_ += E_sqr / samples_ / cycles;
        M2_ += M_sqr / samples_ / cycles;
        cv_ += Cv() / samples_ / cycles;
        chi_ += Chi() / samples_ / cycles;

        // save(i);
    }
    // export();
 }

 // Specific Heat Capacity
 double Lattice::Cv(){
    // E2_ = mcE2_;
    // Eavg_ = mcEavg_;
    return (1./(kb*T_*T_))*(E2_-Eavg_*Eavg_);
 }

 // Magnetic Susceptibility
 double Lattice::Chi(){
    // M2_ = mcM2_;
    // Mavg_ = mcMavg_;
    return beta_*(M2_-Mavg_*Mavg_);
 }

//  void save(int i){
//     vec e(i) = Eavg_;
//     vec m(i) = Mavg;
//     vec e2(i) = E2_;
//     vec m2(i) = M2_;
//     vec c(i) = cv_;
//     vec x(i) = chi_;
//  }

//  void export(){
//     e.save("Average_E_Temp_" + to_string(T_in) + ".bin");
//     m.save("Average_M_Temp_" + to_string(T_in) + ".bin");
//     e2.save("E_squared_Temp_" + to_string(T_in) + ".bin");
//     m2.save("M_squared_Temp_" + to_string(T_in) + ".bin");
//     c.save("Cv_Temp_" + to_string(T_in) + ".bin");
//     x.save("Chi_Temp_" + to_string(T_in) + ".bin");
//  }