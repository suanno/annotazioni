#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SquareNmultiply.h"

int classicShor(int a, int N);
int check(int a, int N, int r);
int gcd(int a, int b);

int main(int argc, char** argv) {
    /* Prints first 2N positions of the trajectory a^t mod N, showing it must have a periodicity < N */
    
    int a, N;
    a = strtol(argv[1], NULL, 10);
    N = strtol(argv[2], NULL, 10);

    int pos = 1;
    for (int i = 1; i < 2*N; i++){
        pos = (pos * a) % N;
        printf("%d^%i = %d;  ", a, i, pos);
    }
}