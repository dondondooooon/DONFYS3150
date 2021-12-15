#include "quantum.hpp"

quantum::quantum(int M_, double h_, double dt_, double T_, double xc_,
double xsig_, double px_, double yc_, double ysig_, double py_,
double v0_, bool slit1in, bool slit2in, bool slit3in, string sim_){
    M = M_; // Number of points along gird axis
    L = M-2; // Length of Inner Points
    N = L*L; // Number of Inner Points
    h = h_; // Spacestep
    dt = dt_; // Timestep
    T = T_; // End Time
    tn = T/dt; // Number of Time Points
    xc = xc_ * M; // Center Coordinate of Initial Wave Packet
    xsig = xsig_ * M; // Initial Widths of Wave Packet
    px = px_; // Wave Packet Momenta
    yc = yc_ * M; // Center Coordinate of Initial Wave Packet
    ysig = ysig_ * M; // Initial Widths of Wave Packet
    py = py_; // Wave Packet Momenta
    v0 = v0_; // 10*10*10*10*10*10*10*10*10*10 // High Potential
    r = cx_double (0, dt/(2*h*h) );
    dt_half = cx_double (0, dt/2);
    a = cx_vec(N); // Initialize a vector
    b = cx_vec(N); // Initialize b vector
    A = sp_cx_mat(N,N); // Initialize A Sparse Matrix
    B = sp_cx_mat(N,N); // Initialize B Sparse Matrix
    slit1 = slit1in;
    slit2 = slit2in;
    slit3 = slit3in;
    sim = sim_; 
    xvec = regspace(1*h, h, (M-1)*h); // Space Vector x-axis
    yvec = regspace(1*h, h, (M-1)*h); // Space Vector y-axis

    // Set up Simulation
    V = mat(M,M).fill(0.); // Initialize Potential 
    if (slit2 == true){ // Double Slit
        slit_2();
    }
    else if (slit1 == true){ // Single Slit
        slit_1();
    }
    else if (slit3 == true){ // Triple Slit
        slit_3();
    }
    // V.save("bin_files/" + sim + "_V.bin"); // Save Potential Matrix as well
    v = V(span(1,L),span(1,L)).as_col(); // Vectorize Potential
}

//************************//
//Potential Class Methods//
//************************//

// Initialize Potential w/ 2 slit
void quantum::slit_2(){
    int start_wall = M/2-3; // Start of Wall
    int end_wall = start_wall + 4; // End of Wall
    // Fill First 5x41 Wall
    V(span(start_wall,end_wall),span(1,start_wall-6)) = mat(5,91).fill(v0);
    // Fill 5x5 Slit
    V(span(start_wall,end_wall),span(start_wall,end_wall)) = mat(5,5).fill(v0);
    // Fill Last 5x41 Wall
    V(span(start_wall,end_wall),span(end_wall+7,M-2)) = mat(5,91).fill(v0);
}
// Initialize Potential w/ 1 slit
void quantum::slit_1(){
    int start_wall = M/2-3; // Start of Wall
    int end_wall = start_wall + 4; // End of Wall
    // Fill First 5x41 Wall
    V(span(start_wall,end_wall),span(1,start_wall-6)) = mat(5,91).fill(v0);
    // Fill Last 5x41 Wall
    V(span(start_wall,end_wall),span(end_wall+7,M-2)) = mat(5,91).fill(v0);
}
// Initialize Potential w/ 3 slit
void quantum::slit_3(){
    int start_wall = M/2-3; // Start of Wall
    int end_wall = start_wall + 4; // End of Wall
    // Fill First 5x41 Wall
    V(span(start_wall,end_wall),span(1,start_wall-6-4)) = mat(5,87).fill(v0);
    // Fill First 5x5 Slit
    V(span(start_wall,end_wall),span(start_wall-5,start_wall-1)) = mat(5,5).fill(v0);
    // Fill Second 5x5 Slit
    V(span(start_wall,end_wall),span(end_wall+1,end_wall+5)) = mat(5,5).fill(v0);
    // Fill Last 5x41 Wall
    V(span(start_wall,end_wall),span(end_wall+11,M-2)) = mat(5,87).fill(v0);
}

//*********************//
//System Initialization//
//*********************//

// Gaussian Wave Packet
cx_double quantum::func(double xi, double yj){
    cx_double euler( -((xi-xc)*(xi-xc))/(2*xsig*xsig) - ((yj-yc)*(yj-yc))/(2*ysig*ysig)
    , px*(xi-xc) + py*(yj-yc) );
    return exp(euler);
}
// Initialize & Normalize U 
void quantum::wavepoints(){
    cx_double normsum;
    for (int i=0; i<L; i++){ 
        for(int j=0; j<L; j++){
            U(i,j) = func(xvec(i),yvec(j));
            normsum += norm(U(i,j));
        }
    }
    U = U/sqrt(normsum);
}
// Initialize System
void quantum::grid_init(){
    grid_tid = cx_cube(M,M,tn); // Cube for System Grid with Time slices
    // Add Boundary Condition (Fill zeros)
    grid_tid.slice(0).col(0) = cx_vec(M).fill(0.);
    grid_tid.slice(0).col(M-1) = cx_vec(M).fill(0.);
    grid_tid.slice(0).row(0) = cx_vec(M).fill(0.).st();
    grid_tid.slice(0).row(M-1) = cx_vec(M).fill(0.).st();
    U = grid_tid.slice(0)(span(1,L),span(1,L)); // Initialize Inner Points Matrix (IP)
    wavepoints(); // Build wavepacket in U
    grid_tid.slice(0)(span(1,L),span(1,L)) = U; // Add Wave Function into Grid Matrix
}

//***********************************//
//System Evolution via Crank Nicolson//
//***********************************//

/* Har ikke brukt dette fordi .col_as() funker like fint:D
// Convert 2 index ij to 1 index k
int quantum::correct_index(int i, int j){
    return j*L+i;
} */

// A diagonal value
cx_double quantum::af(int k){
    cx_double send( 1.0 , 4*imag(r) + imag(dt_half)*v(k) );
    return send;
}
// B diagonal value
cx_double quantum::bf(int k){
    cx_double send( 1.0 , -4*imag(r) - imag(dt_half)*v(k) );
    return send;
}
// Set up Matrix A and B
void quantum::set_matsAB(){
    for (int k=0; k<N; k++){ // fill a and b vector
        a(k) = af(k);
        b(k) = bf(k);
    }
    // Fill Main Diagonals
    A.diag(0) = a;
    B.diag(0) = b;
    // Fill Diagonal Submatrices' U- & L-Diagonals
    for (int i=0; i<L; i++){
        for (int j=0; j<L-1; j++){ // Upper & Lower Diag in DiaSubMat
            int ind = j + i*L;
            A(ind,ind+1) = -r;
            A(ind+1,ind) = -r;
            B(ind,ind+1) = r;
            B(ind+1,ind) = r;
        }
    }
    // Fill Main 3rd Upper & Lower Diagonals
    for (int i=0; i<N-L; i++){
        A(i+L,i) = -r;
        A(i,i+L) = -r;
        B(i+L,i) = r;
        B(i,i+L) = r;
    }
}
// Solve A*u_new = B*u_old via Armadillo Solver for Sparse Matrices
void quantum::solver(){
    u = spsolve(A,B*u);
    U = cx_mat(u);
    U.reshape(L,L); // New Inner Points Matrix
}
// Run Crank-Nicolson for time steps
void quantum::Cranky(){
    grid_init(); // Initialize System Grid
    set_matsAB(); // Set up Matrix A & B for CN Method
    for (double i=dt; i<T; i+=dt){ // See comment below for this loop
        cout << "i: " << i << endl;
        cout << "t_iteration: " << t_iteration << endl;
        u = U.as_col(); // Coloumn-wise Vectoring of IP
        solver();
        grid_tid.slice(t_iteration)(span(1,L),span(1,L)) = U;
        t_iteration += 1; 
    }
    cout << "Final Iteration: " << t_iteration << endl;
    // Save Cube Matrix
    grid_tid.save("bin_files/Grid_" + sim + ".bin");
}
/* 
Comment on the time loop:
For some reason when running simulation 1 and 2, i had to 
add "i<T-dt" part on the loop condition since it for some 
bizzare reason it would run 1 extra loop. In other words, 
in simulation 1 & 2, this loop accepted the condition i=0.008 < 0.008... 
which doesnt make sense.
*/



// Debug Check
void quantum::print(){
    grid_init();
    set_matsAB();
    u = U.as_col();
    solver();
    cx_mat Uconj = conj(U);
    cx_mat Uprob = U % Uconj;
    cx_double sum;
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            sum += Uprob(i,j);
        }
    }
    cout << "This: " << endl << setprecision(10) << sum << endl;
}