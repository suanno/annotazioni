#include <stdio.h>
#include <stdlib.h>


void read_matrix(char inp_fn[], double* matrix);
void read_vector(char inp_fn[], double* x);
void write_vector(char outp_fn[], int n, double* x);
void print_matrix(int rows, int cols, double* matrix);

void read_matrix(char inp_fn[], double* matrix) {
    /* READ Matrix from .dat file 
    The matrix is saved in a 1D array (all rows concatenated)
    Returns a pointer to the matrix
    */

    FILE        *input;
    int n, rows, cols;

    /* CONVENTIONS:
    1) First row is square matrix dimension
    2) Then there is the matrix, with rows separated by \n
     */    
    input = fopen(inp_fn, "r");
    // Read n=rows=cols
    fscanf(input, "%d", &n);
    rows = n; cols = n;
    
    // Read matrix
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j){
            fscanf(input, "%lf", matrix + i*cols + j);
            //printf("A[%d] = %lf", i*cols+j, matrix[i*cols + j]);
        }
    }
    fclose (input);
}

void read_vector(char inp_fn[], double* x){
    /* Read Vector from .dat file
    Returns the lenght of the array
    */

    FILE        *input;
    int n;

    /* CONVENTIONS:
    1) First row is the vector's lenght
    2) Then there is the vector
     */    
    input = fopen(inp_fn, "r");
    // Read vector's lenght n
    fscanf(input, "%d", &n);
    
    // Read matrix
    for(int i = 0; i < n; ++i)
    {
        fscanf(input, "%lf", x + i);
    }
    fclose (input);
}


void write_vector(char outp_fn[], int n, double* x){
    /* Wirtes a vector to txt file */
    FILE        *file;
    file = fopen(outp_fn, "w");

    for(int i = 0; i < n; i++){
        fprintf(file, "%lf, ", x[i]);
    }
    fclose (file);
}


void print_matrix(int rows, int cols, double* matrix){
    /* Prints matrix */
    for(int i = 0; i < rows; i++){
        printf("\n");
        for(int j=0; j < cols; j++)
            printf("[%d][%d] %lf, ", i, j, matrix[i*cols + j]);
    }
}