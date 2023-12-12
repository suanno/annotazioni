#ifndef FFT_H
#define FFT_H

#ifndef FFT_C

#include <complex.h>

#endif

complex double* fft(int N, complex double*  vector);
complex double* dft(int N, complex double*  vector);

#endif