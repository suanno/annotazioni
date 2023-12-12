#define FFT_C
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

void mk1grids(int N, double a, double* xlattice, double* qlattice){
    /*Defines real and reciprocal lattices*/
    for(int i = 0; i < N; i++){
        xlattice[i] = i*a;
        qlattice[i] = 2*M_PI*i/(N*a);
    }
}