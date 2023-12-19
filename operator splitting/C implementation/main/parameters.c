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
#define Nsteps 6000     /*Reduces packet velocity*/

double V(int n, int xi, int xf, double gamma);
double calc_norm(complex double* psi);

int main(int argc, char** argv) {
    /*User parameters*/
    double beta = 0.00000000001;        /*Increases precision*/
                                        /*A sto beta, si sbrodola già dopo 500 steps*/
    double alpha = 8;
    double gamma = 1000*alpha*alpha;           /*Increases barrier height*/


    /*Barrier parameters*/
    double xi, xf;
    /*Psi0 parameters*/
    double xc, sigma;
    complex double* psi = malloc(N*sizeof(complex double));     /*psi(x,t) (state)*/
    complex double* psi_k = malloc(N*sizeof(complex double));   /*psi FFT*/
    
    /*Packet and Barrier*/
    xc = 500;
    sigma = 100;
    xi = 1000;
    xf = 2000;

    /*Define psi0*/
    double norm;
    for (int n = 0; n < N; n++){
        psi[n] = exp(-0.5*((n-xc)/sigma)*((n-xc)/sigma))*cexp(I*alpha*n);
    }
    norm = calc_norm(psi);
    /*Normalize psi0*/
    for (int n = 0; n < N; n++)
        psi[n] = psi[n]/norm;
    write_complex_vector("before.txt", N, psi);
    /*Evolution*/
    complex double* Kterm = (complex double*)malloc(N*sizeof(complex double));
    complex double* Vterm = (complex double*)malloc(N*sizeof(complex double));

    for(int step = 0; step < 1000; step++){
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int n = 0; n < N; n++){
            Vterm[n] = -I*V(n, xi, xf, gamma)*beta/2;
            Kterm[n] = -I*(2*M_PI/N)*(2*M_PI/N)*n*n*beta;
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