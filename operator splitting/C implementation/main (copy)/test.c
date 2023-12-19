#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "fft.h"
#include "read_matrix.h"
#include "global.h"

int main(int argc, char** argv) {
    /*Space lattice size
    int N = strtol(argv[1], NULL, 10);
    */
    clock_t tempo;
    double tempo_sec;

    int N = 65536;
    /*Real space wavefunction*/
    complex double* psi = malloc(N*sizeof(complex double));
    /* FFT */
    complex double* psi_k = malloc(N*sizeof(complex double));
    /* DFT (computed from definition) */
    complex double* psi_k_ = malloc(N*sizeof(complex double));

    /*printf("A");*/
    read_complex_vector("input.txt", psi);
    /*
    for(int i = 0; i < N; i++){
        printf("%d: %lf +j%lf\n",i, creal(psi[i]), cimag(psi[i]));
    }
    */

    tempo = clock();
    psi_k = fft(N, psi);
    psi = ifft(N, psi_k);
    tempo_sec = (double)(clock()-tempo)/CLOCKS_PER_SEC;
    
    for(int i = 0; i < N; i++){
        printf("%lf +i%lf\n", creal(psi[i]), cimag(psi[i]));
    }
    /*
    psi_k_ = dft(N,psi);

    //Sow the two results are the same 
    for (int i = 0; i < N; i++){
        printf("%d: (%lf + j%lf) - (%lf + j%lf) = %lf + j%lf \n", i, creal(psi_k[i]), cimag(psi_k[i]), creal(psi_k_[i]), cimag(psi_k_[i]), creal(psi_k[i]-psi_k_[i]), cimag(psi_k[i]-psi_k_[i]));
    }
    */
    printf("\nTime FFT: %lfs\n", tempo_sec);

    write_complex_vector("output.txt", N, psi_k);
}