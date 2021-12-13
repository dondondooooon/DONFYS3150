#include <iostream>
#include"quantum.hpp"

int single_index(mat A);

int main(){
    // Initialization (Common for all Simulations)
    int M = 100; // Number of points along gird axis
    double h = 0.005; // Spacestep
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

    // Simulation 3 (with 9 + 1(oppg.9) plot)
    double T = 0.002; // End Time
    double ysig = 0.20; // Initial Widths of Wave Packet
    double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // Set to true to turn on selected slit
    bool slit1 = false;
    bool slit2 = true;
    bool slit3 = false;
    string simulation = "Simulation3";

    // // Simulation 4
    // double T = 0.002; // End Time
    // double ysig = 0.20; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = true;
    // bool slit2 = false;
    // bool slit3 = false;
    // string simulation = "Simulation3";

    // // Simulation 5
    // double T = 0.002; // End Time
    // double ysig = 0.20; // Initial Widths of Wave Packet
    // double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // High Constant Potential
    // // Set to true to turn on selected slit
    // bool slit1 = false;
    // bool slit2 = false;
    // bool slit3 = true;
    // string simulation = "Simulation3";

    // Initialize Simulator
    quantum Schrondinger(M,h,dt,T,xc,xsig,px,yc,ysig,py,
    v0,slit1,slit2,slit3,simulation);

    // Run Simulation
    Schrondinger.Cranky();
    // Debug Check
    // Schrondinger.print();
    
    // Done
    cout << "Hello World!" << endl;
    return 0;
}

