#include <complex.h>
#include <stdlib.h>
# define M_PI           3.14159265358979323846  /* pi */

complex double* fft(int N, double*  vector);

complex double* fft(int N, double* vector){
    // Calculates the FFT of vector of size N=2^n
    if (N > 1){
        //FFT of vector
        complex double* vector_k = malloc(N*sizeof(complex double));
        //Separate even and odd entries
        double* even = malloc((N/2)*sizeof(double));
        double* odd = malloc((N/2)*sizeof(double));
        //Their FFTs
        complex double* even_k = malloc((N/2)*sizeof(complex double));
        complex double* odd_k = malloc((N/2)*sizeof(complex double));
        for (int i = 0; i <= N/2-1; i++){    //N is always even because N=2^n
            even[i] = vector[2*i];
            odd[i] = vector[2*i+1];
        }
        //Calculate their FFTs
        even_k = fft(N/2, even);
        odd_k = fft(N/2, odd);
        //Calculate FFT of vector
        for(int k = 0; k < N; k++){
            vector_k[k] = even_k[k%(N/2)] + cexp(-I*2*M_PI*k/N)*odd_k[k%(N/2)];
        }

        return vector_k;
    }else{   //If N=1, then the fft of a number is the number itself
        complex double* vector_compex = malloc(sizeof(complex double));
        vector_compex[0] = vector[0];
        return vector_compex;
    }
}