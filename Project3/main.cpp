#include "part.hpp"
#include "trap.hpp"
using namespace std; 



int main(){
    double q;
    double m; 
    double ke;
    vec r; 
    vec v; 
    vec E;
    double T, B0,V0, d, V;

    

    trap my_trap; 


    // //Coloumbs constant 
    // ke = 1.38935333e5;

    // //SI units for magnetic-field strengt T(Tesla) and electric potential V(Votl)
    // T = 9.64852558e1;
    // V = 9.64852558e7;

    // //Default penning trap configurations
    // B0 = 1.0*T;
    // V0 = 10.0*V;
    // d = 10.0e4;

    

    particle proton(q, m, r, v);

    my_trap.add_particle(proton);
    return 0; 
}