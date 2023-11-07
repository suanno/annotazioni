#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SquareNmultiply.h"

int classicShor(int a, int N);
int check(int a, int N, int r);

int main(int argc, char** argv) {
    /* Factorizes N = pq with (classic)Shor */
    int a, q, p;
    a = strtol(argv[1], NULL, 10);
    q = strtol(argv[2], NULL, 10);
    p = strtol(argv[3], NULL, 10);
    int N = p*q;

    // Calculate r and check if a is good
    int r = classicShor(a, N);
    int c = check(a, N, r);
    printf("\nr = %d\ncheck a goodness = %d \n", r, c);
    if (c == 1){
        // Calculate x,y
        int x, y;
        x = (modexp(a, r/2, N) - 1)%N;
        y = (modexp(a, r/2, N) + 1)%N;
        printf("\nN = %d\nx = %d\ny = %d\n", N, x, y);
    }else{
        printf("\n a is not good, please change it!\n");
    }
}

int classicShor(int a, int N){
    /*  Finds the SMALLEST r such that a^r = 1 mod N 
        It always exists
    */
    int r = 1;
    int res = modexp(a,r,N);
    while (res != 1){
        r++;
        res = modexp(a,r,N);
        //printf("%d %d\n", r, res);
    }

    return r;
}

int check(int a, int N, int r){
    /*  Checks properties that a must have in order to use it for
        factorization of N = pq:
    - a is even
    - y = (a^{r/2} + 1) mod N != 0
    */

    if (a%2 != 0)
        return 0;
    int y = (modexp(a, r/2, N) + 1)%N;
    if (y == 0)
        return 0;
    return 1;
}