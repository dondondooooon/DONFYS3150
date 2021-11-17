#include "isingmodel.hpp"

// Constructor Definition
Ising::Ising(int L_in, vec Tvec_in, int cycles_in) : generate(rando()) { // Initialize Ising Model
    L_ = L_in;
    N_ = L_*L_;
    start_config();
    E_ = E(S_);
    M_ = M(S_);
    cout << "init m: " << M_ << endl;
    E2_ = E_*E_;
    M2_ = M_*M_;
    mc_cycles_ = cycles_in;
    invN_ = 1./N_;
    norm_ = 1.0/(mc_cycles_*N_*N_);
    invmc = 1.0/mc_cycles_;
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
void Ising::start_config(){
    // int randNum;
    // srand(time(NULL)); // Seed Generate
    S_ = mat(L_,L_).fill(1);
    // S_ = mat(L_,L_);
    // for (int i = 0;i< L_; i++){
    //     for(int j = 0;j< L_; j++){
    //         randNum =  rand() % 2; 
    //         if(randNum == 0){
    //             randNum = -1;
    //         }
    //         S_(i,j) = randNum;
    //     }
    // }
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
    cout << E << endl;
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
    int E_after = E_spin(i_flip, j_flip);
    //cout << "This: " << -2*E_after << endl; !! mistake was here what
    return 2*E_after;
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
 // Specific Heat Capacity
 double Ising::Cv(){
    return beta_*beta_*N_*(Esqrd-N_*Eavg*Eavg);
 }
 // Magnetic Susceptibility
 double Ising::Chi(){
    return beta_*N_*(Msqrd-N_*Mavg*Mavg);
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
        // M_ = fabs(M_);
    
        E2_ += E_*E_;
        M2_ += M_*M_;
    }
    else if(r <= accept){
        S_(i_flip,j_flip) *= -1.0;
        E_ += diff;
        M_ += 2.0*S_(i_flip,j_flip);
        // M_ = fabs(M_);
    
        E2_ += E_*E_;
        M2_ += M_*M_;
    }
 }
 // Monte Carlo
 void Ising::monte_carlo(){
    // MC CYCLES LOOP
    for (int k=0; k<mc_cycles_; k++){
        // 1 MC CYCLE SAMPLING 
        for (int i=0; i<N_; i++){ 
            metropolis();
            Eavg += E_;
            //cout << E_ << endl; 
            Mavg += fabs(M_);
            Esqrd += E2_;
            Msqrd += M2_;
            // cv_ += Cv();
            // chi_ += Chi();
        }
    }
    Eavg *= norm_;
    Mavg *= norm_;
    Esqrd *= norm_;
    Msqrd *= norm_;
    cv_ = Cv();
    chi_ = Chi();
    // cv_ *= norm_*norm_;
    // chi_ *= norm_*norm_;
 }
 // Printout for T = 1
 void Ising::printT1(){
    // T = 1
    beta_ = 1.0/(kb*1.0);
    dE_values();
    monte_carlo();
    cout << "Number of Monte Carlo Cycles: " << mc_cycles_ << endl;
    cout << "Energy per Spin: " << Eavg << endl;
    cout << "Magnetization per Spin: " << Mavg << endl;
    cout << "The Heat Capacity: " << cv_ << endl;
    cout << "The Magnetic Suscpeptibility: " << chi_ << endl;
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
        //  << setw(width) << setprecision(prec) << scientific << Esqrd
        //  << setw(width) << setprecision(prec) << scientific << Msqrd
         << setw(width) << setprecision(prec) << scientific << cv_
         << setw(width) << setprecision(prec) << scientific << chi_
          << endl;
    }
    ofile.close();
 }
 /////
 void Ising::printcycles(){
    mcmc_cycles(beta1_,1);
    mcmc_cycles(beta2_,2);
 }

void Ising::mcmc_cycles(double beta, int h){
    ofstream ofile;
    ofile.open("MCcycle_beta" + to_string(h) + ".txt");
    int width = 23; 
    int prec  = 9;
    beta_ = beta;
    dE_values();
    for (int i=0; i<mccycles_.size(); i++){
        mc_cycles_ = mccycles_[i];
        monte_carlo();
        ofile << setw(width) << setprecision(prec) << scientific << mc_cycles_(i)
          << setw(width) << setprecision(prec) << scientific << Eavg
          << setw(width) << setprecision(prec) << scientific << Mavg
          << endl;
    }
    ofile.close();
 }
 ////
 // Printout values
 void Ising::print(){
    cout << "This is E_average: " << Eavg << endl;
    cout << "This is M_avgerage: " << Mavg << endl;
    // cout << "This is E^2 avg: " << E2_/L_/L_ << endl;
    // cout << "This is M^2 avg: " << M2_ << endl;
    // cout << "This is the heat capacity: " << cv_/L_/L_ << endl;
    // cout << "This is the mag. suscp.: " << chi_ << endl;
 }