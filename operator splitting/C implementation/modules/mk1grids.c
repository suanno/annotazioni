#define FFT_C
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

void mk1grids(int N, double a, double* xlattice, double* qlattice){
    /*Defines real and reciprocal lattices*/
    for(int i = 0; i < N; i++){
        xlattice[i] = a*i;
        //xlattice[i] = (-(double)(N-1)/2 + i)*a;
        qlattice[i] = 2*M_PI*((double)i/(N*a));
        //qlattice[i] = M_PI*((double)(i+1)/((N+1)*a));
    }
}