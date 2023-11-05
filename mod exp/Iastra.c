#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int modexp(int g, int* rappr, int p, int n);
int inttobit(int x, int* rappr);

int main(int argc, char** argv) {
    int g, p, x_maxtime;
    clock_t t;
    double last_time;
    int* rappr = (int*)malloc(sizeof(int)*sizeof(int)*8);
    int scale = 10000; //Calculate time for "scale" executions of same command

    g = strtol(argv[1], NULL, 10);
    p = strtol(argv[2], NULL, 10);

    int res, min, x;
    for (int n = 3; n < 29; n++){
        // Calculate min = 2^n
        min = 1;
        for (int j = 0; j < n-2; j++)
            min = 2*min;
        // Generate random integer with n bits
        x = ( rand() % 2*min ) + min;
        inttobit(x, rappr);

        // Time measurement of "scale" iterates
        t = clock();
        for (int j = 0; j < scale; j++){
            res = modexp(g, rappr, p, n);
        }
        t = clock() - t;
        last_time = ((double)(t))/CLOCKS_PER_SEC; // in seconds
        printf("%d %lf\n", n, last_time);
    }
}

int inttobit(int x, int* rappr){
    // Converts x into its binary representation,
    // returns the index of last bit = 1
    int last = 0;
    for (int i = 0; i < sizeof(int)*8; i++){
        rappr[i] = x & 1;
        if (rappr[i] == 1)
            last = i;
        x = x >> 1;
    }
    return last;

    //
}

int modexp(int g, int* rappr, int p, int n){
    // Performs g^x mod p
    unsigned long long res = 1;
    for (int i = n - 1; i >= 0; i--){
        res = (res*res)%p;
        if (rappr[i] == 1)
            res = (res*g) % p;
    }
    
    return res;
}