#include <iostream>
#include"quantum.hpp"

int main(){
    // Initialization (Common for all Simulations)
    double h = 0.005; // Spacestep
    int M = 1/h; // Number of points along gird axis
    cout << "M = " << M << endl;
    double dt = 0.000025; // Timestep
    double xc = 0.25; // Center Coordinate of Initial Wave Packet
    double xsig = 0.05; // Initial Widths of Wave Packet
    double px = 200.; // Wave Packet Momenta
    double yc = 0.5; // Center Coordinate of Initial Wave Packet
    double py = 0.; // Wave Packet Momenta

    // // Simulation 1 (with 1 plot)
    // double T = 0.008; // End Time
    // double ysig = 0.05; // Initial Widths of Wave Packet
    // double v0 = 0.; // Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = false;
    // bool slit2 = false;
    // bool slit3 = false;
    // string simulation = "Simulation1";

    // // Simulation 2 (with 1 plot)
    // double T = 0.008; // End Time
    // double ysig = 0.10; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = false;
    // bool slit2 = true;
    // bool slit3 = false;
    // string simulation = "Simulation2";

    // // Simulation 3 (with 9 + 1(oppg.9) plot)
    // double T = 0.002; // End Time
    // double ysig = 0.20; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = false;
    // bool slit2 = true;
    // bool slit3 = false;
    // string simulation = "Simulation3";

    // // Simulation 4
    // double T = 0.002; // End Time
    // double ysig = 0.20; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = true;
    // bool slit2 = false;
    // bool slit3 = false;
    // string simulation = "Simulation4";

    // // Simulation 5
    // double T = 0.002; // End Time
    // double ysig = 0.20; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = false;
    // bool slit2 = false;
    // bool slit3 = true;
    // string simulation = "Simulation5";

    // Initialize Simulator
    quantum Schrondinger(M,h,dt,T,xc,xsig,px,yc,ysig,py,
    v0,slit1,slit2,slit3,simulation);

    // Run Simulation
    Schrondinger.Cranky();
    cout << "You have run " << simulation << endl;
    // Debug Check
    // Schrondinger.print();
    
    // Done
    cout << "Hello World!" << endl;
    return 0;
}



















    // For Proof that .as_col() should works
    // // declare:
    // int ind(int i, int j);
    //
    // // Put into main 
    // vec lin = regspace(0,1,25);
    // for (int i=0; i<5; i++){
    //     for (int j=0; j<5; j++){
    //         Schrondinger.V(i,j) = lin(j*5+i);
    //     }
    // }
    // mat vee = Schrondinger.V(span(1,3),span(1,3));
    // vec meth = vec(9).fill(0.);
    // for (int i=0; i<3; i++){
    //     for (int j=0; j<3; j++){
    //         meth(ind(i,j)) = vee(i,j);
    //     }
    // }
    // cout << "mat: " << endl <<  Schrondinger.V << endl;
    // cout << "vec: " << endl << Schrondinger.v << endl;
    // cout << "vec2: " << endl << meth << endl;
    // // .as_col method
    // Schrondinger.v = Schrondinger.V(span(1,3),span(1,3)).as_col();
    // Schrondinger.set_matsAB(); 
    // cout << "A: " << endl <<  Schrondinger.A << endl;
    // cout << "B: " << endl <<  Schrondinger.B << endl;
    // // j*L+i method
    // Schrondinger.v = meth;
    // Schrondinger.set_matsAB(); 
    // cout << "A: " << endl <<  Schrondinger.A << endl;
    // cout << "B: " << endl <<  Schrondinger.B << endl;
    //
    // // func def:
    // int ind(int i, int j){
    // return j*3+i;