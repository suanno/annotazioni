#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include <math.h>
#include "global.h"
#include "fft.h"
#include "mk1grids.h"
#include "read_matrix.h"

double V(double x, double t, double xi, double xf, double V0);
double dVdt(double x, double t);
double calc_norm(int N, double a, complex double* psi);

int main(int argc, char** argv) {
    /*int N = strtol(argv[1], NULL, 10);  Space lattice size*/
    /*Lattice and time parameters*/
    int N = 2.24*1000;
    double a = 0.1;                          /*Real lattice spacing*/
    double* xlattice = (double*)malloc(N*sizeof(double));
    double* qlattice = (double*)malloc(N*sizeof(double));
    double tau = 0.01;
    int Nsteps = 10000;
    /*Barrier parameters*/
    double xi, xf, deltax, beta, V0;
    /*Psi0 parameters*/
    double m, p, E, alpha; /*Mass, momentum, kinetic energy, E/V0*/
    double xc, sigma, d;
    complex double* psi = malloc(N*sizeof(complex double));     /*psi(x,t) (state)*/
    complex double* psi_k = malloc(N*sizeof(complex double));   /*psi FFT*/
    
    /*Parameters*/
    xc = 50;
    sigma = 20;
    m = 1;
    p = 1.5;    /*hbar = 1, m = 1 -> k = p = v*/

    /*Make lattices*/
    mk1grids(N, a, xlattice, qlattice);

    /*Define psi0*/
    double x, norm;
    for (int n = 0; n < N; n++){
        x = xlattice[n];
        psi[n] = exp(-0.5*((x-xc)/sigma)*((x-xc)/sigma))*cexp(I*p*x);
    }
    norm = calc_norm(N, a, psi);
    /*Normalize psi0*/
    for (int n = 0; n < N; n++)
        psi[n] = psi[n]/norm;
    write_complex_vector("before.txt", N, psi);
    /*Evolution*/
    complex double* Kterm = (complex double*)malloc(N*sizeof(complex double));

    /*Check normalization after (IFFT * FFT)*/
    double t, q;

    for(int step = 0; step < Nsteps; step++){
        t = step*tau;
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int n = 0; n < N; n++){
            q = qlattice[n];
            Kterm[n] = -I*((q*q)/(2*m))*tau;
        }
        psi_k = fft(N, psi);
        for (int k = 0; k < N; k++){
            psi_k[k] = cexp(Kterm[k])*psi_k[k];
        }
        psi = ifft(N, psi_k);
    }
    norm = calc_norm(N, a, psi);
    printf("Final norm: %lf\n", norm);

    write_complex_vector("then.txt", N, psi);
}

double V(double x, double t, double xi, double xf, double V0){
    /* Potential Barrier [xi,xf] of height V0*/
    /*  If psi0 = e^-x^2*e^ikx, then its momentum (expectation value) is +k\sqrt(\pi/2) 
        This statement gives the energy scale of the problem, and you have to took care of it
        for defining the barrier height (must be >> k^2*\pi)
    */
    if (x > xi && x < xf)
        return V0;
    else
        return 0;
}
double dVdt(double x, double t){
    /* Time derivative of Potential barrier is 0 */
    return 0;
}
double calc_norm(int N, double a, complex double* psi){
    double norm;
    norm = 0;
    for (int n = 0; n < N; n++){
        norm = norm + cabs(psi[n])*cabs(psi[n])*a;
    }
    norm = sqrt(norm);
    return norm;
}