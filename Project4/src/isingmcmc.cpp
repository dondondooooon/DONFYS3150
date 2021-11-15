/*include "isingmcmc.hpp"

// Constructor  
Lattice::Lattice(double N_in, double T_in, double samples_in, double cycles_in){ // vec Tvec_in
    samples_ = samples_in;
    mcycles_ = cycles_in;
    // S_ = mat(N_in,N_in);
    // Snew_ = mat(N_in,N_in);
    L_ = N_in;
    T_ = T_in; // Tvec_ = Tvec_in;
    beta_ = 1./(kb*T_); // balhin
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

 // Metropolis Rule && 1 Cycle of Monte Carlo
 void Lattice::MC_cycle(){
    for (int i=1; i<samples_; i++){
        S_rng(); // RNG 360 NO SCOPE FLIP
        int diff = dE(i_flip,j_flip);
        double accept = p(diff);
        double r = randu();
        if (diff < 0){
            E_ += diff;
          
            Esum_ += E_;
            Esumsquared += E_*E_;
            M_ += 2*S_
        }
        else if(r <= accept){
            S_ = Snew_;
        }

        E_sum += E;
        M_sum += M(S_);
        E_sqr += E*E;
        M_sqr += M*M;

        // Eavg_ += E_sum / i;
        // Mavg_ += M_sum / i;
        // E2_ += E_sqr/ i;
        // M2_ += M_sqr/ i;
    }
 }
 // REMOVE THE S_NEW!.. just work with S_
 // Bestemme i,j som skal flippes
 // Regn ut delta E
 // Test accept
    //Hvis Accept
    // spin ij = spin ij*-1
    // M_ += 2*spin ij
    // (THEN THIS UPDATES THE M)
    // (ESUM AND MSUM AFTER E AND M UPDATE)
    // (Update E2 AND M2 AFTER E_ AND M_ IS ITERATED / UPDATED)

 // Multiple Monte Carlo Cycles
 void Lattice::MCMC(){
    E_ = E(S_);
    M_ = M(S_);
    E_sqr = E_*E_;
    M_sqr = M_*M_;
    // mat S_old = S_;
    for (int i=0; i<mcycles_; i++){
        // S_ = S_gen();
        // S_ = S_old;

        E_sum = 0;
        M_sum = 0;
        E_sqr = 0;
        M_sqr = 0;

        MC_cycle();
// construct 1/samples and multiply
// MAYBE SAVE THE MATRIX OLD AND REINITIALIZE THE MATRIX
        Eavg_ += E_sum / samples_; 
        Mavg_ += M_sum / samples_;
        E2_ += E_sqr / samples_;
        M2_ += M_sqr / samples_; 
        cv_ += Cv() / samples_;
        chi_ += Chi() / samples_;

        // save(i);
    }
    Eavg_ = Eavg_ / mcycles_;
    Mavg_ = Mavg_ / mcycles_;
    E2_ = E2_ / mcycles_;
    M2_ = M2_ / mcycles_;
    cv_ = cv_ / mcycles_;
    chi_ = chi_ / mcycles_;
    // export();
    // filesave();
 }

 void Lattice::print(){
    cout << "This is E_average: " << Eavg_ << endl;
    cout << "This is M_avgerage: " << Mavg_ << endl;
    cout << "This is E^2 avg: " << E2_ << endl;
    cout << "This is M^2 avg: " << M2_ << endl;
    cout << "This is the heat capacity: " << cv_ << endl;
    cout << "This is the mag. suscp.: " << chi_ << endl;
 }

//  void Lattice::Tmcmc(vec T){
//     ofstream ofile;
//     ofile.open("ThingsVsTemp");
//     for (int i=0; i<T.size; i++){
//         T_ = T(i);
//         beta_ = 1./(kb*T_);
//         MCMC(); //
//     }
//     ofile.close();
//  }

//  void Lattice::filesave(){
//     int width = 12;
//     int prec  = 4;
//     ofile << setw(width) << setprecision(prec) << scientific << T_
//           << setw(width) << setprecision(prec) << scientific << Eavg_
//           << setw(width) << setprecision(prec) << scientific << Mavg_
//           << setw(width) << setprecision(prec) << scientific << E2_
//           << setw(width) << setprecision(prec) << scientific << M2_
//           << setw(width) << setprecision(prec) << scientific << cv_
//           << setw(width) << setprecision(prec) << scientific << chi_
//           << endl;
//  }

//  void save(int i){
//     vec e(i) = Eavg_;
//     vec m(i) = Mavg;
//     vec e2(i) = E2_;
//     vec m2(i) = M2_;
//     vec c(i) = cv_;
//     vec x(i) = chi_;
//  }

//  void export(){
//     e.save("Average_E_Temp_" + to_string(T_) + ".bin");
//     m.save("Average_M_Temp_" + to_string(T_) + ".bin");
//     e2.save("E_squared_Temp_" + to_string(T_) + ".bin");
//     m2.save("M_squared_Temp_" + to_string(T_) + ".bin");
//     c.save("Cv_Temp_" + to_string(T_) + ".bin");
//     x.save("Chi_Temp_" + to_string(T_) + ".bin");
//  }

*/