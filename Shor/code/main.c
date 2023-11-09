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
    int N = strtol(argv[1], NULL, 10);

    int r, c;
    /*  In order to calculate the factors p and q, we need to find an integer a such that:
        - It exists the order r of a respect to N;
        - r is good (even and y is not 0 mod N)
        And THEN we can calculate p and q.

        "c" is the "check variable". It is initialized c = -1 and it becomes
        - c = -1 if r does not exist for any a
        - c = 0 if an r exist for at least one a, but there are no a such that exists a good r
        - c = 1 if it exists an a such that exists an r and r is good
    */

    c = -1;
    a = 1;
    while (c != 1 && a < N){ //Check if a is good UNTIL a < N, because "N = 0 (mod N)"
        a = a + 1;  // We start from a = 2

        if (N%a != 0){  // Discard a if it divides N. In that case r does not exist!
            printf("a = %d ", a);
            r = classicShor(a, N);
            c = check(a, N, r);
            printf("r = %d y mod %d = %d; a is not good\n", r, N, (modexp(a, r/2, N) + 1)%N);
        }
    }

    // Calculate p and q
    // If c = 1, it means it exists a good r
    if (c == 1){
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
        Looks for r in range 1,2,...,N-1 because it exists in this range or it does not exist at all 
        If it does not exists, returns -1
    */
    clock_t t; 
    t = clock();

    printf("(Classic) Shor a = %d... ", a);
    int r = 1;
    int res = modexp(a,r,N);
    while (res != 1 && r < N){
        r++;
        res = modexp(a,r,N);
        //printf("%d %d\n", r, res);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Computation time: %lf sec\n", time_taken);

    if (r == N) //In this case that r does not exists
        return -1;
    else
        return r;
}

int check(int a, int N, int r){
    /*  Checks properties that a must have in order to use it for
        factorization of N = pq:
    - a is even
    - y = (a^{r/2} + 1) mod N != 0
    */

    if (r%2 != 0 || r < 0)
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