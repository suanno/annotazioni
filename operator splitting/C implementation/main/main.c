#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "global.h"
#include "fft.h"
#include "mk1grids.h"
#include "read_matrix.h"

double V(double x, double t, double xi, double xf, double V0);
double dVdt(double x, double t);

int main(int argc, char** argv) {
    /*int N = strtol(argv[1], NULL, 10);  Space lattice size*/
    /*Lattice and time parameters*/
    int N = 2048;
    int a = 0.001;                          /*Real lattice spacing*/
    double* xlattice = (double*)malloc(N*sizeof(double));
    double* qlattice = (double*)malloc(N*sizeof(double));
    double tau = 1e-5;
    int Nsteps = 100;
    /*Psi0 parameters*/
    double k = 1;  /*Momentum*/
    complex double* psi = malloc(N*sizeof(complex double));
    complex double* psi_k = malloc(N*sizeof(complex double));
    /*Barrier parameters*/
    double xi,xf,V0;
    xi = 5;
    xf = 10;
    V0 = 10*k*k*M_PI;


    printf("A");
    /*Make lattices*/
    mk1grids(N, a, xlattice, qlattice); /*FIXARE STO PROBLEMA DEL PASSAGGIO DEL PUNTATOREEE*/
    print_matrix(N,1,xlattice);

    printf("B");

    /*Evolution*/
    double t;
    complex double* Vterm = (complex double*)malloc(N*sizeof(complex double));
    complex double* Kterm = (complex double*)malloc(N*sizeof(complex double));

    printf("C");
    double x, q;
    for(int step = 0; step < Nsteps; step++){
        t = step*tau;
        /* Operator splitting */
        /* Calculate the terms at the exponent of operator splitting Vterm and Kterm*/
        for (int n = 0; n < N; n++){
            x = xlattice[n];
            q = qlattice[n];
            Vterm[n] = -I*(V(x, t, xi, xf, V0)+dVdt(x,t)*tau/2)*tau/2;
            Kterm[n] = -I*q*q;
        }
        printf("D");
        psi_k = fft(N, psi);
    }
}

double V(double x, double t, double xi, double xf, double V0){
    /* Potential Barrier [xi,xf] of height V0*/
    /*  If psi0 = e^-x^2*e^ikx, then its momentum (expectation value) is +k\sqrt(\pi/2) 
        This statement gives the energy scale of the problem, and you have to took care of it
        for defining the barrier height (must be >> k^2*\pi)
    */
    if (x < xi || x > xf)
        return V0;
    else
        return 0;
}
double dVdt(double x, double t){
    /* Time derivative of Potential barrier is 0 */
    return 0;
}