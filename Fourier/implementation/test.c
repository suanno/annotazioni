#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "fft.h"
#include "read_matrix.h"

int main(int argc, char** argv) {
    //int N = strtol(argv[1], NULL, 10);  /*Space lattice size*/
    
    int N = 100;
    complex double* psi = (complex double*)malloc(N*sizeof(double));
    complex double* psi_k = (complex double*)malloc(N*sizeof(complex double));
    printf("A");
    read_complex_vector("output.txt", psi);
    printf("%lf",creal(psi[0]));
    //psi[2] = 1.0;
    complex double a;
    a = 1;
    //read_complex_vector("output.txt", psi);
    printf("B");
    //psi_k = fft(N, psi);
    printf("C");
    //write_complex_vector("result.txt", N, psi_k);

}