#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int local_n = 2;
    double* local_a =  malloc(local_n*sizeof(double));
    if (world_rank == 0){
        int n = 10;
        double* a = malloc(n*sizeof(double));
        printf("Enter the vector \n");
        for (int i = 0; i < n; i++){
            scanf("%lf", &a[i]);
        }
        MPI_Scatter(a, 2, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        for (int j = 0; j < local_n; j++)
            printf("From process %d: %lf", world_rank, local_a[j]);
    }else{
        MPI_Scatter(NULL, 2, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        for (int j = 0; j < local_n; j++)
            printf("From process %d: %lf", world_rank, local_a[j]);
    }
    
    // Finalize the MPI environment.
    MPI_Finalize();
}