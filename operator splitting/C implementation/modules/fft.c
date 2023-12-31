#define FFT_C
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

complex double* dft(int N, complex double*  vec){
    complex double* vec_k = malloc(N*sizeof(complex double));
    for (int k = 0; k < N; k++){
        for (int n = 0; n < N; n++){
            //printf("n,k,vec[n]: %d, %d, %lf +j%lf\n",n,k,creal(vec[n]),cimag(vec[n]));
            vec_k[k] = vec_k[k] + vec[n]*cexp(-I*2*M_PI*(double)k*n/N);
        }
    }
    return vec_k;
}

complex double* idft(int N, complex double*  vec){
    complex double* vec_k = malloc(N*sizeof(complex double));
    for (int k = 0; k < N; k++){
        for (int n = 0; n < N; n++){
            //printf("n,k,vec[n]: %d, %d, %lf +j%lf\n",n,k,creal(vec[n]),cimag(vec[n]));
            vec_k[k] = vec_k[k] + vec[n]*cexp(+I*2*M_PI*(double)k*n/N);
        }
        vec_k[k] = vec_k[k]/N;
    }
    return vec_k;
}

complex double* fft(int N, complex double* vector){
    // Calculates the FFT of vector of size N=2^n
    if (N % 2 == 0){
        //FFT of vector
        complex double* vector_k = malloc(N*sizeof(complex double));
        //Separate even and odd entries
        complex double* even = malloc((N/2)*sizeof(complex double));
        complex double* odd = malloc((N/2)*sizeof(complex double));
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
            vector_k[k] = even_k[k%(N/2)] + cexp(-I*2*M_PI*(double)k/N)*odd_k[k%(N/2)];
        }

        /*For unknown reason segments if you call free*/
        //free(even); free(odd); free(even_k); free(odd_k);
        return vector_k;
    }else{   //If N=1, then the fft of a number is the number itself
        //complex double* vector_compex = malloc(sizeof(complex double));
        //vector_compex[0] = vector[0];
        //return vector_compex;
        if (N == 1)
            return vector;
        else
            return dft(N, vector);
    }
}

complex double* ifft(int N, complex double* vector_k){
    // Calculates the FFT of vector of size N=2^n
    if (N % 2 == 0){
        //FFT of vector
        complex double* vector = malloc(N*sizeof(complex double));
        //Separate even and odd entries
        complex double* even_k = malloc((N/2)*sizeof(complex double));
        complex double* odd_k = malloc((N/2)*sizeof(complex double));
        //Their FFTs
        complex double* even = malloc((N/2)*sizeof(complex double));
        complex double* odd = malloc((N/2)*sizeof(complex double));
        for (int i = 0; i <= N/2-1; i++){    //N is always even because N=2^n
            even_k[i] = vector_k[2*i];
            odd_k[i] = vector_k[2*i+1];
        }
        //Calculate their IFFTs
        even = ifft(N/2, even_k);
        odd = ifft(N/2, odd_k);
        //Calculate IFFT of vector_k
        for(int n = 0; n < N; n++){
            vector[n] = 0.5*(even[n%(N/2)] + cexp(+I*2*M_PI*(double)n/N)*odd[n%(N/2)]);
        }

        /*For unknown reason segments if you call free*/
        //free(even); free(odd); free(even_k); free(odd_k);
        return vector;
    }else{   //If N=1, then the fft of a number is the number itself
        //complex double* vector_compex = malloc(sizeof(complex double));
        //vector_compex[0] = vector[0];
        //return vector_compex;
        if (N == 1)
            return vector_k;
        else
            return idft(N, vector_k);
    }
}


