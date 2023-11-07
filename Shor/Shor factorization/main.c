#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SquareNmultiply.h"

int classicShor(int a, int N);
int check(int a, int N, int r);
int gcd(int a, int b);

int main(int argc, char** argv) {
    /* Factorizes N = pq with (classic)Shor */
    int a, q, p;
    //a = strtol(argv[1], NULL, 10);
    //q = strtol(argv[2], NULL, 10);
    //p = strtol(argv[3], NULL, 10);
    //int N = p*q;
    int N = strtol(argv[1], NULL, 10);
    a = 1;

    int r, c;
    c = 0;
    while (c == 0 && a < N+1){ //Check if a is good UNTIL a < N+1 because on Z_N N+1 and 1 are the same
        // Calculate r
        a = a + 1;
        //if (gcd(a+1, N) == 1){  // a must be coprime with N in order to apply Small Fermat Theorem (to say it exist surely a value of r < N)
            r = classicShor(a, N);
            c = check(a, N, r);
            printf("; a = %d r = %d y mod %d = %d; a is not good\n", a, r, N, (modexp(a, r/2, N) + 1)%N);
        //}
    }
    if (a < N+1){
        // Calculate x,y
        int x, y;
        x = (modexp(a, r/2, N) - 1)%N;
        y = (modexp(a, r/2, N) + 1)%N;
        printf("\nx = %d\ny = %d\n", x, y);
        p = gcd(x,N);
        q = gcd(y,N);
        printf("\nN = %d\np = %d\nq = %d\n", N, p, q);
    }else
        printf("\n\nUnable to Factorize!\n");
}

int classicShor(int a, int N){
    /*  Finds the SMALLEST r such that a^r = 1 mod N 
        It always exists
    */
    clock_t t; 
    t = clock();

    printf("Testing a = %d.", a);
    int r = 1;
    int res = modexp(a,r,N);
    while (res != 1 && r < N){
        r++;
        res = modexp(a,r,N);
        //printf("%d %d\n", r, res);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("(Classic) Shor computation time: %lf sec\n", time_taken);
    if (r == N) //In this case that a is not good
        return 1;
    else
        return r;
}

int check(int a, int N, int r){
    /*  Checks properties that a must have in order to use it for
        factorization of N = pq:
    - a is even
    - y = (a^{r/2} + 1) mod N != 0
    */

    if (r%2 != 0)
        return 0;
    int y = (modexp(a, r/2, N) + 1)%N;
    if (y == 0)
        return 0;
    return 1;
}

int gcd(int a, int b){
    /*  Calculates the greatest common divisor 
        Using Euler identity that gcd(a,b) = gcd(a,b-a) if b > a
        In general gcd(a,b) = gcd(a,b%a)
    */
    if ((b > a && b%a != 0) || (a > b && a%b != 0)){
        if (b > a)
            return gcd(a, b%a);
        else
            return gcd(a%b, b);
    }else{
        if (b > a)
            return a;
        else
            return b;
    }
}