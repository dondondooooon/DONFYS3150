#include "isingmodel.hpp"

// Constructor Definition
Ising::Ising(int L_in, vec Tvec_in, int cycles_in) : generate(rando()) { // Initialize Ising Model
    L_ = L_in;
    N_ = L_*L_;
    start_config(true);
    E_ = E(S_);
    M_ = M(S_);
    E2_ = E_*E_;
    M2_ = M_*M_;
    mc_cycles_ = cycles_in;
    invN_ = 1./N_;
    cnorm_ = 1.0/mc_cycles_;
    Tvec_ = Tvec_in;
    tsize_ = Tvec_.size();
    bvec_ = vec(tsize_);
    for (int i=0; i<tsize_; i++){
        bvec_(i) = 1./(kb*Tvec_(i));
    }
    uniform_real_distribution<double> dist_double(0.0, 1.0);
    uniform_int_distribution<int> dist_int(0.0, L_-1);
    distribution_int = dist_int;
    distribution_double = dist_double;
}
// Initial Spin Configuration
void Ising::start_config(bool order){
    if (order==true){
        S_ = mat(L_,L_).fill(1);
    }
    else{
    S_ = mat(L_,L_);
    int randNum;
    srand(time(NULL)); // Seed Generate
    for (int i = 0;i< L_; i++){
        for(int j = 0;j< L_; j++){
            randNum =  rand() % 2; 
            if(randNum == 0){
                randNum = -1;
            }
            S_(i,j) = randNum;
        }
    }}
}
// Periodic Boundary Condition
inline int Ising::Periodic(int i, int L){
    int correct_index = (i+L) % L;
    return correct_index;
}
// Calculate Total Energy For A Given Spin Configuration
int Ising::E(mat S){
    int E = 0;
    int s_elem;
    int up;
    int right;
    for (int i=0; i<L_; i++){
        for(int j=0; j<L_; j++){
            s_elem = S(i,j);
            up = s_elem * S(Periodic(i-1,L_),Periodic(j,L_));
            right = s_elem * S(Periodic(i,L_),Periodic(j+1,L_));
            E += up + right;
        }
    }
    return -J_*E;
}

// Calculate Total Magnetization For A Given Spin Configuration
int Ising::M(mat S){
    int M = 0;
    for (int i=0; i<L_; i++){
        for(int j=0; j<L_; j++){
            M += S(i,j);
        }
    }
    return M;
}
// Energy Around The Chosen Spin : dont need stat arg
int Ising::E_spin(int i, int j){
    int s = S_(i,j);
    int up = S_(Periodic(i-1,L_),Periodic(j,L_));
    int down = S_(Periodic(i+1,L_),Periodic(j,L_));
    int left = S_(Periodic(i,L_),Periodic(j-1,L_));
    int right = S_(Periodic(i,L_),Periodic(j+1,L_));
    return s*(up+down+left+right);
}
// Energy Difference
int Ising::dE(int i, int j){
    int de = E_spin(i_flip, j_flip);
    return 2*de;
}
// Delta Energy Values
void Ising::dE_values(){
    for (int i=0; i<17; i+=4){
        boltz_(i) = exp(-beta_*(i-8)*J_);
    }
}
// Probability Ratio for Energy Shift of 1 Spin Change
double Ising::p(int dE){
    return boltz_[dE+8];
}

 //*******// Markov Chain Monte Carlo: Metropolis //*******//

 // Metropolis Rule
 void Ising::metropolis(){
    // Flip 
    i_flip = distribution_int(generate);
	j_flip = distribution_int(generate);
    // Calculate Difference in Energy 
    double diff = dE(i_flip,j_flip); 
    // Get Correct Probability Ratio
    double accept = p(diff);
    // Generate r From A Uniform RNG
    double r = distribution_double(generate);
    // To Accept Proposed Or Not
    if (diff<0){
        S_(i_flip,j_flip) *= -1.0;
        E_ += diff;
        M_ += 2.0*S_(i_flip,j_flip);
    }
    else if(r <= accept){
        S_(i_flip,j_flip) *= -1.0;
        E_ += diff;
        M_ += 2.0*S_(i_flip,j_flip);
    }
 }
 // Monte Carlo
 void Ising::monte_carlo(){
    // MC cycles
    for (int k=0; k<mc_cycles_; k++){
        // 1 MC Cycle Sampling
        for (int i=0; i<N_; i++){ 
            metropolis();
        }
        // Update Values
        Eavg += E_;
        Mavg += fabs(M_);
        Esqrd += E_*E_;
        Msqrd += M_*M_;
    }
    // Normalize w/ The  MC Cycles
    Eavg *= cnorm_;
    Mavg *= cnorm_;
    Esqrd *= cnorm_;
    Msqrd *= cnorm_;
 }
 // Temperature Monte Carlo plots
 void Ising::mc_temp(){
    ofstream ofile;
    ofile.open("TempPlot" + to_string(mc_cycles_) + ".txt");
    int width = 23; 
    int prec  = 9;
    for (int i=0; i<tsize_; i++){
        beta_ = bvec_(i);
        dE_values();
        monte_carlo();
        ofile << setw(width) << setprecision(prec) << scientific << Tvec_(i)
        << setw(width) << setprecision(prec) << scientific << Eavg
        << setw(width) << setprecision(prec) << scientific << Mavg
        << setw(width) << setprecision(prec) << scientific << Esqrd
        << setw(width) << setprecision(prec) << scientific << Msqrd
        << endl;
    }
    ofile.close();
 }
 // Cycles Monte Carlo plot
 void Ising::cycle_plot(double temperature, string t){
    ofstream ofile;
    ofile.open("cycle_ordered" + t + ".txt"); // + "unordererd" for when order == false
    int width = 23; 
    int prec  = 9;
    beta_ = 1.0/temperature;
    dE_values();
    for (int i=1; i<mc_cycles_+1; i++){
        // 1 MC CYCLE SAMPLING 
        for (int j=0; j<N_; j++){ 
            metropolis();
        }
        Esum += E_;
        Msum += fabs(M_);
        cnorm_ = 1.0/( (double) i );
        Eavg = Esum * cnorm_;
        Mavg = Msum * cnorm_;
    
        ofile << setw(width) << setprecision(prec) << scientific << i
        << setw(width) << setprecision(prec) << scientific << Eavg
        << setw(width) << setprecision(prec) << scientific << Mavg
        << endl;
    }
    ofile.close();
 }
 // Printout Values for T = 1
 void Ising::printT1(){
    ofstream ofile;
    ofile.open("T=1_printout"+to_string(mc_cycles_)+".txt");
    int width = 23; 
    int prec  = 9;
    beta_ = 1.0/(kb*1.0);
    dE_values();
    monte_carlo();
    ofile << setw(width) << setprecision(prec) << scientific << mc_cycles_
    << setw(width) << setprecision(prec) << scientific << Eavg
    << setw(width) << setprecision(prec) << scientific << Mavg
    << setw(width) << setprecision(prec) << scientific << Esqrd
    << setw(width) << setprecision(prec) << scientific << Msqrd
    << endl;
 }