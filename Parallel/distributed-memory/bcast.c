#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
        int rank;
        double a = 0;
        double* x = &a;
        const int root=0;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int n = 3;
        /**/
        x = malloc(n*sizeof(double));
        
        if(rank == root) {
            for(int i = 0; i < n; i++){
                scanf("%lf", x+i);
            }
        }

        //printf("[%d]: Before Bcast, buf is %lf\n", rank, *buf);

        /* everyone calls bcast, data is taken from root and ends up in everyone's buf */
        MPI_Bcast(x, n, MPI_DOUBLE, root, MPI_COMM_WORLD);

        for(int i = 0; i < n; i++){
            printf("From process %d, x[%d] = %lf \n", rank, i, x[i]);
        }
        
        //printf("[%d]: After Bcast, buf is %lf\n", rank, *buf);

        MPI_Finalize();
        return 0;
}