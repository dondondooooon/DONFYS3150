#include <iostream>
#include"quantum.hpp"

int single_index(mat A);

int main(){
    // Initialization
    int M = 100; // Number of points along gird axis
    double h = 0.005; // Spacestep
    double dt = 0.000025; // Timestep
    double T = 0.008; // End Time
    double xc = 0.25; // Center Coordinate of Initial Wave Packet
    double xsig = 0.05; // Initial Widths of Wave Packet
    double px = 200.; // Wave Packet Momenta
    double yc = 0.5; // Center Coordinate of Initial Wave Packet
    double ysig = 0.10; // 0.05; // Initial Widths of Wave Packet
    double py = 0.; // Wave Packet Momenta
    double v0 = 10.*10.*10.*10.*10.*10.*10.*10.*10.*10.; // 0.; // High Potential
    // Set to true to turn on selected slit
    bool slit1 = false;
    bool slit2 = true; // false;
    bool slit3 = false;
    string simulation = "Simulation2"; // Simulation 1

    quantum Schrondinger(M,h,dt,T,xc,xsig,px,yc,ysig,py,
    v0,slit1,slit2,slit3,simulation);

    Schrondinger.Cranky();
    // Schrondinger.print();

    cout << "Hello World!" << endl;
    // Done
    return 0;
}

