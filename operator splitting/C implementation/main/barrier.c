#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include <math.h>
#include "global.h"
#include "fft.h"
#include "mk1grids.h"
#include "read_matrix.h"

#define N 2.24*1000
#define Nsteps 6000
#define a 0.1       /*Real lattice spacing*/
#define sigma 10    /*Currently DISABLED:
                    Not only the packet size, but even the boundary of the box are [sigma,N*a-sigma]:
                    it's important that the limits of the box contain sigma, because we are implicitly adopting PBCs*/

double V(double x, double t, double xi, double xf, double V0);
double dVdt(double x, double t);
double calc_norm(complex double* psi);

int main(int argc, char** argv) {
    /*int N = strtol(argv[1], NULL, 10);  Space lattice size*/
    /*Lattice and time parameters*/
    double* xlattice = (double*)malloc(N*sizeof(double));
    double* qlattice = (double*)malloc(N*sizeof(double));
    double tau = 0.01;
    /*Barrier parameters*/
    double xi, xf, deltax, beta, V0;
    /*Psi0 parameters*/
    double m, p, E, alpha; /*Mass, momentum, kinetic energy, E/V0*/
    double xc, d;
    complex double* psi = malloc(N*sizeof(complex double));     /*psi(x,t) (state)*/
    complex double* psi_k = malloc(N*sizeof(complex double));   /*psi FFT*/
    
    /*Parameters*/
    xc = 80;
    m = 1;
    p = 1.5;    /*hbar = 1, m = 1 -> k = p = v*/
    
    E = p*p/2;
    /*Barrier*/
    V0 = 2*E;
    xi = 150;
    xf = 180;

    /*Make lattices*/
    mk1grids(N, a, xlattice, qlattice);

    /*Define psi0*/
    double x, norm;
    for (int n = 0; n < N; n++){
        x = xlattice[n];
        psi[n] = exp(-0.5*((x-xc)/sigma)*((x-xc)/sigma))*cexp(I*p*x);
    }
    norm = calc_norm(psi);
    /*Normalize psi0*/
    for (int n = 0; n < N; n++)
        psi[n] = psi[n]/norm;
    write_complex_vector("before.txt", N, psi);
    /*Evolution*/
    complex double* Kterm = (complex double*)malloc(N*sizeof(complex double));
    complex double* Vterm = (complex double*)malloc(N*sizeof(complex double));

    /*Check normalization after (IFFT * FFT)*/
    double t, q;

    for(int step = 0; step < Nsteps; step++){
        t = step*tau;
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int n = 0; n < N; n++){
            q = qlattice[n];
            x = xlattice[n];
            Vterm[n] = -I*(V(x, t, xi, xf, V0)+dVdt(x,t)*tau/2)*tau/2;
            Kterm[n] = -I*((q*q)/(2*m))*tau;
            psi[n] = cexp(Vterm[n])*psi[n];
        }
        psi_k = fft(N, psi);
        for (int k = 0; k < N; k++){
            psi_k[k] = cexp(Kterm[k])*psi_k[k];
        }
        psi = ifft(N, psi_k);
        for (int n = 0; n < N; n++){
            psi[n] = cexp(Vterm[n])*psi[n];
        }
    }
    norm = calc_norm(psi);
    printf("Final norm: %lf\n", norm);

    write_complex_vector("then.txt", N, psi);
}

double V(double x, double t, double xi, double xf, double V0){
    /* Potential Barrier [xi,xf] of height V0*/
    /*  If psi0 = e^-x^2*e^ikx, then its momentum (expectation value) is +k\sqrt(\pi/2) 
        This statement gives the energy scale of the problem, and you have to took care of it
        for defining the barrier height (must be >> k^2*\pi)
    */
    if (x < xi || x > xf){
        return V0;
    }
    else
        return 0;
}
double dVdt(double x, double t){
    /* Time derivative of Potential barrier is 0 */
    return 0;
}
double calc_norm(complex double* psi){
    double norm;
    norm = 0;
    for (int n = 0; n < N; n++){
        norm = norm + cabs(psi[n])*cabs(psi[n])*a;
    }
    norm = sqrt(norm);
    return norm;
}