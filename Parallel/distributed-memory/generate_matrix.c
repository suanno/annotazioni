#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    /* Generate rows*cols matrix and prints to file argv[3] */
    double* matrix;
    int rows = strtol(argv[1], NULL, 10);
    int cols = strtol(argv[2], NULL, 10);

    FILE        *file;
    int n;
    file = fopen(argv[3], "w");

    matrix = malloc(rows*cols*sizeof(double));
    srand(time(NULL));   // Initialization, should only be called once.
    int r;
    fprintf(file, "%d\n", rows);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            //matrix[i*cols + j] = rand()/(RAND_MAX/5);
            r = rand();
            fprintf(file, "%lf ", (double)r/(RAND_MAX/5));
        }
        fprintf(file, "\n");
    }

    fclose (file);
}