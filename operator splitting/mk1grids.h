#include <stdlib.h>
#include <stdio.h>
# define M_PI           3.14159265358979323846  /* pi */

double* mk1grids(int N, double a);

double* mk1grids(int N, double a){
    /*Defines real and reciprocal lattices*/
    double* arrays = (double*)malloc((2*N)*sizeof(double)); 
    /*Put the two lattices one after the other in the same array*/ 
    /*Real space lattice*/
    for(int i = 0; i < N; i++){
        arrays[i] = i*a;
    }
    /*Reciprocal lattice*/
    for(int k = N; k < 2*N; k++){
        arrays[k] = 2*M_PI*k/(N*a);
    }
}