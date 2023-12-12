
#ifndef READ_MATRIX_H
#define READ_MATRIX_H

#ifndef READ_MATRIX_C

#include <complex.h>

#endif
void read_matrix(char inp_fn[], double* matrix);
void read_vector(char inp_fn[], double* x);
void read_complex_vector(char inp_fn[], complex double* x);
void write_vector(char outp_fn[], int n, double* x);
void write_complex_vector(char outp_fn[], int n, complex double* x);
void print_matrix(int rows, int cols, double* matrix);

#endif