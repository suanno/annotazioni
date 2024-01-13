#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include <math.h>
#include "global.h"
#include "fft.h"
#include "mk1grids.h"
#include "read_matrix.h"

#define N 2.24*1000     /*Increase resolution*/
#define Nsteps 40     /*Reduces packet velocity*/
#define a 0.01
#define tau 0.01
#define hbar 1

double calc_norm(complex double* psi);

int main(int argc, char** argv) {
    /*Lattice parameters*/
    double L = N*a;
    /*Psi0 parameters*/
    double xc, sigma, p, m, v;
    xc = N/2;
    sigma = N/20;
    //p = 0.01;
    v = (0.4*N*a)/(Nsteps*tau*hbar);   // v=p/m
    m = 1;
    p = m*v;

    complex double* psi = malloc(N*sizeof(complex double));     /*psi(x,t) (state)*/
    complex double* psi_k = malloc(N*sizeof(complex double));   /*psi FFT*/

    /*Define psi0*/
    double norm;
    for (int n = 0; n < N; n++){
        psi[n] = exp(-0.5*((n-xc)/sigma)*((n-xc)/sigma))*cexp(I*(p/hbar)*n*a);
    }
    norm = calc_norm(psi);
    /*Normalize psi0*/
    for (int n = 0; n < N; n++)
        psi[n] = psi[n]/norm;
    write_complex_vector("before.txt", N, psi);
    /*Evolution*/
    complex double* qlattice = (complex double*)malloc(N*sizeof(complex double));

    double next_step = 0;
    double delta_step = (int)((double)Nsteps/10);
    for(int step = 0; step < Nsteps; step++){
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int k = 0; k < N; k++){
            if (k < N/2)
                qlattice[k] = 2*k*M_PI/(N*a);
            else
                qlattice[k] = 2*(k-N)*M_PI/(N*a);
        }
        psi_k = fft(N, psi);
        for (int k = 0; k < N; k++){
            psi_k[k] = cexp(-I*(hbar*qlattice[k]*qlattice[k]*tau)/(2*m))*psi_k[k];
        }
        psi = ifft(N, psi_k);
        if (step > next_step){
            printf("Step %lf\n", next_step);
            next_step = next_step + delta_step;
        }
    }
    norm = calc_norm(psi);
    printf("Final norm: %lf\n", norm);

    write_complex_vector("then.txt", N, psi);
}

double V(int n, int xi, int xf, double gamma){
    /* Potential Barrier [xi,xf] of height V0*/
    /*  If psi0 = e^-x^2*e^ikx, then its momentum (expectation value) is +k\sqrt(\pi/2) 
        This statement gives the energy scale of the problem, and you have to took care of it
        for defining the barrier height (must be >> k^2*\pi)
    */
    if (n > xi && n < xf){
        return gamma;
    }
    else
        return 0;
}
double calc_norm(complex double* psi){
    double norm;
    norm = 0;
    for (int n = 0; n < N; n++){
        norm = norm + cabs(psi[n])*cabs(psi[n]);
    }
    norm = sqrt(norm);
    return norm;
}