#include "trap.hpp"
#include "part.hpp"

trap::trap(double B0_in, double V0_in, double d_in){
    double B0 = B0_in;
    double V0 = V0_in;
    double d = d_in;

}

void trap::add_particle(particle p_in){
    particles.push_back(p_in);
}

vec external_E_field(vec r){
    vec E(0) = (V0/2*d*d)*(-2*r(0));
    vec E(1) = (V0/2*d*d)*(-2*r(1));
    vec E(2) = (V0/2*d*d)*(4*r(2));
}

vec external_B_field(vec r){
    vec B = B0*r(2);
}

vec force_particle(int i, int j){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            F[i] = q*E[i] + q*v[i] + B
        }
    }
}

void evolve_RK4(double dt){
    for (int i = 0; i < N: i++){
        K1 = h*f(t[i], y[i]);
        K2 = h*f(t[i]+(1/2)h,y[i]+(1/2)K1);
        K3 = h*f(t[i]+(1/2)h,y[i]+(1/2)K2);
        K4 = h*f(t[i+1], y[i]+K3);
        y[i+1] = y[i] + (1/6)*(K1+2*K2+2*K3*K4);
    }
}

void evolve_EC(double dt){
    for (int i = 0; i < N; i++){
        v[i+1] = v[i] + h*f[i];
        x[i+1] = x[i] + h*v[i+1];
    }
}
