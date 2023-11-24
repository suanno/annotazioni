#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_matrix.h"
#include <time.h>


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
    int ti, tf;

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
    double* x = malloc(n*sizeof(double));   // EACH process has to allocate memory for x BECAUSE EACH PROCESS HAS ITS **PRIVATE** MEMORY!!!
    //double** x = malloc(sizeof(double *));
    if (world_rank == 0){
        /* Read A, x */
        printf("P%d: AAA\n", world_rank);
        A = malloc(n*n*sizeof(double));
        read_matrix("data/A.dat", A);
        read_vector("data/x.dat", x);
        //printf("From P0\n");
        //print_matrix(1, n, x);
    }
    clock_t t; 
    if(world_rank == 0) {
        t = clock();
    }
    MPI_Bcast(x, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* Scatter the rows between the processes */
    // Define number of rows per process
    int local_n;
    if (world_rank == 0) local_n = (int) (n/world_size);
    MPI_Bcast(&local_n, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    // Scatter rows among processes
    double* local_A;
    local_A = malloc(n*local_n*sizeof(double)); //Each row has lenght n, so you pass n*local_n doubles to each process

    // Scatter the rows
    MPI_Scatter(A, local_n*n, MPI_DOUBLE, local_A, local_n*n, MPI_DOUBLE, 0, MPI_COMM_WORLD); 

    // Calculate the matrix products
    double* local_y;
    local_y = malloc(local_n*sizeof(double));


    if(world_rank == 0) {
        // Propagation time
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("\n\nPropagation time: %lf\n\n", time_taken);
        t = clock();
    }
    Mat_vec_mult(n, local_n, local_A, x, local_y, MPI_COMM_WORLD, world_rank);
    if (world_rank == 0){
        t = clock() - t; 
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("\n\nComputation time: %lf\n\n", time_taken);
    }


    // Receive elements of y and unify them
    double* y;
    if (world_rank == 0) y = malloc(n*sizeof(double));
    MPI_Gather(local_y, local_n, MPI_DOUBLE, y, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (world_rank == 0){
        write_vector("out/outPAR.dat", n, y);
    }
    

    free(A); free(local_A); free(x); free(y); free(local_y);
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

    //printf("\nP%d:\n", rank);
    //print_matrix(1, n, x);

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