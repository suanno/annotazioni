#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int modexp(int g, int x, int p);

int main(int argc, char** argv) {
    int g, p, x_maxtime;
    clock_t t;
    double last_time;
    g = strtol(argv[1], NULL, 10);
    p = strtol(argv[2], NULL, 10);
    //printf("g = %d, p = %d\n", g, p);

    int res;
    for (int x = 1; x < p-2; x++){
        // Time measurement
        t = clock();
        res = modexp(g, x, p);
        t = clock() - t;
        last_time = ((double)(t))/CLOCKS_PER_SEC; // in seconds
        printf("%d %d %lf\n", x, res, last_time);
    }
}


int modexp(int g, int x, int p){
    // Performs g^x mod p
    int res = 1;
    while(x > 0){
        res = res * g % p;
        x--;
    }
    
    return res;
}