#include <stdio.h>
#include <stdlib.h>
#include "read_matrix.h"
#include <time.h>

int main(int argc, char** argv) {
    int ti, tf;
    int n;
    double* A;
    double* x;
    double* y;
    printf("Inserisci la dimensione n = ");
    scanf("%d", &n);
    A = malloc(n*n*sizeof(double));
    x = malloc(n*sizeof(double));
    y = malloc(n*sizeof(double));

    read_matrix("data/A.dat", A);
    read_vector("data/x.dat", x);

    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock();  
    for(int i = 0; i < n; i++){
    // Cycle over the local_m rows assigned to the process
        y[i] = 0;
        for(int j = 0; j < n; j++){
            // Makes the i-th row * x product
            y[i] += A[i*n + j]*x[j];
            //printf("\nP%d: x[%d] = %lf", rank, j, x[j]);
        }
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("Computation time: %lf", time_taken);
    write_vector("out/outNOPAR.dat", n, y);
    free(A); free(x); free(y);
}