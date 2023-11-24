#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_matrix.h"


void Mat_vec_mult(
    int n,
    int local_n,
    double* local_A,
    double* x,
    double* local_y,
    MPI_Comm comm,
    int rank
);

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // P0 Reads square matrix / vector dimension n
    int n;
    if (world_rank == 0){
        printf("Matrix / vector dimension n = ");
        scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); //Bcast n to all processes

    /* P0 Reads A, x */
    double* A;
    double* x = malloc(n*sizeof(double));   // EACH process has to allocate memory for x (?)
    if (world_rank == 0){
        /* Read A, x */
        A = malloc(n*n*sizeof(double));
        read_vector("x.dat", x);
        read_matrix("A.dat", A);
        //print_matrix(n, n, A);
    }
    
    
    //free(A);
    //free(x);
    // Finalize the MPI environment.
    MPI_Finalize();
}

void Mat_vec_mult(
    int n,
    int local_n,
    double* local_A,
    double* x,
    double* local_y,
    MPI_Comm comm,
    int rank
){
    /*
    Contribute of a single process to the problem A*x=y
    Each process computes local_m elements of y vector,
    so makes local_m vector'*vector products


    local_A contains the rows of
    the matrix assigned to the
    process.
    If those rows are >1, they are stored in
    a vector, concatenating them. I know how to
    recover the rows because i know the matrix dimension

    local_n is the Matrix Dimension
    local_m is the number of rows reseved to the process
    comm is the group of processes that solve the main problem A*x=y,
    tipycally is MPI_COMM_WORLD (all processes)
    */

   for(int i = 0; i < local_n; i++){
    // Cycle over the local_m rows assigned to the process
    local_y[i] = 0;
    for(int j = 0; j < n; j++){
        // Makes the i-th row * x product
        local_y[i] += local_A[i*n + j]*x[j];
        //printf("\nP%d: x[%d] = %lf", rank, j, x[j]);
    }
   }

}