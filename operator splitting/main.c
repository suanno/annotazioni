#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "fft.h"
#include "mk1grids.h"

int main(int argc, char** argv) {
    int N = strtol(argv[1], NULL, 10);  /*Space lattice size*/
    int a = 1;                          /*Real lattice spacing*/
    double tau = 1e-5;
    int Nsteps = 100;
    
    double* lattices = mk1grids(N, a);  /*Real lattice and after the Reciprocal lattice, in the same 2N array*/
    
    complex double* psi = malloc(N*sizeof(complex double));
    complex double* psi_k = malloc(N*sizeof(complex double));
    
    double t;
    for(int step = 0; step < Nsteps; step++){
        t = step*tau;
        /* Operator splitting */
        psi_k = fft(N, psi);
    }
}