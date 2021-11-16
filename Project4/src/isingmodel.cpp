#include "isingmodel.hpp"

// Constructor Definition
Ising::Ising(int L_in, vec Tvec_in, int cycles_in){ // Initialize Ising Model
    L_ = L_in;
    start_config();
    E_ = E(S_);
    M_ = M(S_);
    mc_cycles_ = cycles_in;
    int N = L_*L_;
    norm_ = 1.0/(mc_cycles_*N*N);
    Tvec_ = Tvec_in;
    tsize_ = Tvec_.size();
    bvec_ = vec(tsize_);
    for (int i=0; i<tsize_; i++){
        bvec_(i) = 1./(kb*Tvec_(i));
    }
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
int Ising::Periodic(int i, int L){
    int correct_index = (i+L) % L;
    return correct_index;
}
// Effektivisere
// Energy Around The Original Spin
int Ising::E_spin_orig(int i, int j){
    int s = S_(i,j);
    int up = s * S_(Periodic(i-1,L_),Periodic(j,L_));
    int down = s * S_(Periodic(i+1,L_),Periodic(j,L_));
    int left = s * S_(Periodic(i,L_),Periodic(j-1,L_));
    int right = s * S_(Periodic(i,L_),Periodic(j+1,L_));
    return up+down+left+right;
}
// Energy Around The Flipped Spin
int Ising::E_spin_flip(int i, int j){
    int s = S_(i,j)*-1;
    int up = s * S_(Periodic(i-1,L_),Periodic(j,L_));
    int down = s * S_(Periodic(i+1,L_),Periodic(j,L_));
    int left = s * S_(Periodic(i,L_),Periodic(j-1,L_));
    int right = s * S_(Periodic(i,L_),Periodic(j+1,L_));
    return up+down+left+right;
}
// Energy Difference
int Ising::dE(int i, int j){
    int E_before = E_spin_orig(i_flip, j_flip);
    int E_after = E_spin_flip(i_flip, j_flip);
    return E_after-E_before;
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
// // 1 Spin Change
// void Ising::flip(){
//     srand(time(NULL)); // Seed Generate
//     i_flip = rand() % L_;
//     j_flip = rand() % L_;

// 	for (int i=0; i<L_; i++) {
// 		for (int j=0; j<L_; j++) {
// 			int ix = (int)(distribution(gen) * (double)l);
// 			int iy = (int)(distribution(gen) * (double)l);
//         }
//     }
// }

//*******// Desired Quantities //*******//

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
            M += abs(S(i,j));
        }
    }
    return M;
}

//  // Specific Heat Capacity
//  double Ising::Cv(){
//     // E2_ = mcE2_;
//     // Eavg_ = mcEavg_;
//     return (1./(L_*L_*kb*T_*T_))*(E2_-Eavg*Eavg);
//  }

//  // Magnetic Susceptibility
//  double Ising::Chi(){
//     // M2_ = mcM2_;
//     // Mavg_ = mcMavg_;
//     return beta_*(M2_-Mavg_*Mavg_);
//  }

 //*******// Markov Chain Monte Carlo: Metropolis //*******//

 // Metropolis Rule
 void Ising::metropolis(){
    // Seed Generate
    random_device rando;
    mt19937_64 generate(rando());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    // Flip 
    i_flip = distribution(generate) * L_;
	j_flip = distribution(generate) * L_;
    // Calculate Difference in Energy 
    double diff = dE(i_flip,j_flip); 
    // Get Correct Probability Ratio
    double accept = p(diff);
    // Generate r From A Uniform RNG
    double r = distribution(generate);
    // To Accept Proposed Or Not
    if (diff<0){
        S_(i_flip,j_flip) *= -1;
        E_ += diff;
        
        M_ += 2.0*S_(i_flip,j_flip);
        // E_sqrsum += E_*E_;
        // M_sqr += M_*M_;
        // cv_ += Cv();
    }
    else if(r <= accept){
        S_(i_flip,j_flip) *= -1;
        E_ += diff;
        M_ += 2.0*S_(i_flip,j_flip);
        // E_sqrsum += E_*E_;
        // M_sqr += M_*M_;
        // cv_ += Cv();
    }
 }
 // Monte Carlo
 void Ising::monte_carlo(){

    // MC CYCLES LOOP
    for (int k=0; k<mc_cycles_; k++){
        // 1 MC CYCLE SAMPLING 
        for (int i=0; i<L_; i++){ 
            for(int j=0; j<L_; j++){
            //flip();
            metropolis();

            Eavg += E_; 
            Mavg += M_;

            // E2_ += E_sqr / samples_;
            // M2_ += M_sqr / samples_; 
            // cv_ += Cv() / samples_;
            // chi_ += Chi() / samples_;
            }
        }
        // Eavg += E_; 
        // Mavg += M_;
        // E2_ += E_sqrsum;
        // M2_ += M_sqrsum;
    }
    Eavg *= norm_;
    Mavg *= norm_;
    // E2_ = E2_ * divide_;
    // cv_ = cv_ * divide_;
 }
 // Temperature Monte Carlo plots
 void Ising::mc_temp(){
    ofstream ofile;
    ofile.open("ThingsVsTemp2.txt");
    int width = 23; 
    int prec  = 9;
    for (int i=0; i<tsize_; i++){
        beta_ = bvec_(i);
        dE_values();
        monte_carlo();
        // filesave(i);
        ofile << setw(width) << setprecision(prec) << scientific << Tvec_(i)
          << setw(width) << setprecision(prec) << scientific << Eavg
          << setw(width) << setprecision(prec) << scientific << Mavg
        //  << setw(width) << setprecision(prec) << scientific << E2_
        //  << setw(width) << setprecision(prec) << scientific << M2_
        //  << setw(width) << setprecision(prec) << scientific << cv_
        //  << setw(width) << setprecision(prec) << scientific << chi_
          << endl;
    }
    ofile.close();
 }
//  // Export
//  void Ising::filesave(int i){
//     ofstream ofile;
//     ofile.open("ThingsVsTemp.txt");
//     int width = 12;
//     int prec  = 4;
//     ofile << setw(width) << setprecision(prec) << scientific << Tvec_(i)
//           << setw(width) << setprecision(prec) << scientific << Eavg
//           << setw(width) << setprecision(prec) << scientific << Mavg
//         //  << setw(width) << setprecision(prec) << scientific << E2_
//         //  << setw(width) << setprecision(prec) << scientific << M2_
//         //  << setw(width) << setprecision(prec) << scientific << cv_
//         //  << setw(width) << setprecision(prec) << scientific << chi_
//           << endl;
//  }
 // Printout values
 void Ising::print(){
    cout << "This is E_average: " << Eavg << endl;
    cout << "This is M_avgerage: " << Mavg << endl;
    // cout << "This is E^2 avg: " << E2_/L_/L_ << endl;
    // cout << "This is M^2 avg: " << M2_ << endl;
    // cout << "This is the heat capacity: " << cv_/L_/L_ << endl;
    // cout << "This is the mag. suscp.: " << chi_ << endl;
 }