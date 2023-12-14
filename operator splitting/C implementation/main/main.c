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
double calc_norm(int N, complex double* psi);

int main(int argc, char** argv) {
    /*int N = strtol(argv[1], NULL, 10);  Space lattice size*/
    /*Lattice and time parameters*/
    int N = 2048;
    double a = 0.01;                          /*Real lattice spacing*/
    double* xlattice = (double*)malloc(N*sizeof(double));
    double* qlattice = (double*)malloc(N*sizeof(double));
    double tau = 0.01;
    int Nsteps = 5;
    /*Barrier parameters*/
    double xi, xf, deltax, beta, V0;
    /*Psi0 parameters*/
    double m, p, E, alpha; /*Mass, momentum, kinetic energy, E/V0*/
    double xc, sigma, d;
    complex double* psi = malloc(N*sizeof(complex double));     /*psi(x,t) (state)*/
    complex double* psi_k = malloc(N*sizeof(complex double));   /*psi FFT*/

    /*Energy scale*/
    alpha = 0.8;    /* 0 < alpha < 1 for tunneling (E < V0)*/
    V0 = 1;         /*Just the ratio with E (alpha) is relevant for evolution, at least I hope so*/
    E = alpha*V0;
    /*Lenght scale*/
    xi = 5;     /*Barrier start location*/
    sigma = 1;  /*Psi0 width*/
    beta = 2;   /*beta > 1 for barrier less wide than psi0*/
    deltax = 2*sigma/beta;
    xf = xi + deltax;
    d = 1;
    xc = xi-sigma-d;
    /*Velocity scale*/
    m = (2*alpha*V0*200*tau*tau)/(d*d); /*In order to have at least 10 steps before psi 'touches' the barrier*/
    p = sqrt(2*m*E);

    /*Make lattices*/
    mk1grids(N, a, xlattice, qlattice);

    /*Define psi0*/
    double x, norm;
    for (int n = 0; n < N; n++){
        x = xlattice[n];
        psi[n] = exp(-0.5*((x-xc)/sigma)*((x-xc)/sigma))*cexp(I*p*x);
    }
    norm = calc_norm(N, psi);
    /*Normalize psi0*/
    for (int n = 0; n < N; n++)
        psi[n] = psi[n]/norm;
    /*Evolution*/
    double t;
    complex double* Vterm = (complex double*)malloc(N*sizeof(complex double));
    complex double* Kterm = (complex double*)malloc(N*sizeof(complex double));

    /*Check normalization after (IFFT * FFT)*/
    double q;
    double tunneled = 0;    /*Probability of finding the particle AFTER the barrier*/
    for (int n = 0; n < N; n++){
        x = xlattice[n];
        if (x > xf){
            tunneled = tunneled + cabs(psi[n])*cabs(psi[n]);
        }
    }
    printf("Prob AFTER the barrier: %lf\n", tunneled);

    for(int step = 0; step < Nsteps; step++){
        t = step*tau;
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int n = 0; n < N; n++){
            x = xlattice[n];
            q = qlattice[n];
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

        tunneled = 0;
        for (int n = 0; n < N; n++){
            x = xlattice[n];
            if (x > xf){
                tunneled = tunneled + cabs(psi[n])*cabs(psi[n]);
            }
        }
        printf("Prob AFTER the barrier: %lf\n", tunneled);
    }
    norm = calc_norm(N, psi);
    printf("Final norm: %lf\n", norm);
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
double calc_norm(int N, complex double* psi){
    double norm;
    norm = 0;
    for (int n = 0; n < N; n++){
        norm = norm + cabs(psi[n])*cabs(psi[n]);
    }
    norm = sqrt(norm);
    return norm;
}