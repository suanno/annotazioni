#ifndef FFT_H
#define FFT_H

#ifndef FFT_C

#include <complex.h>

#endif

complex double* dft(int N, complex double*  vector);
complex double* idft(int N, complex double*  vector);
complex double* fft(int N, complex double*  vector);
complex double* ifft(int N, complex double* vector_k);

#endif