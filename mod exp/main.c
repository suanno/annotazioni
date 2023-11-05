#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double modexp(int g, int x, int p, clock_t* t);

int main(int argc, char** argv) {
    int g, p, x_maxtime;
    clock_t t;
    double last_time, max_time;
    max_time = 0;
    g = strtol(argv[1], NULL, 10);
    p = strtol(argv[2], NULL, 10);
    printf("g = %d, p = %d\n", g, p);

    for (int x = 1; x < p-2; x++){
        last_time = modexp(g, x, p, &t);
        if (last_time > max_time){
            max_time = last_time;
            x_maxtime = x;
        }
    }
    printf("\nMax time: %lf seconds\nIn performing operation %d^%d mod %d\n\n", max_time, g, x_maxtime, p);
    //printf("\n %d^%d mod %d in tempo %lf \n", g, x, p, modexp(g, x, p, &t));
}


double modexp(int g, int x, int p, clock_t* t){
    *t = clock();

    // Performs g^x mod p
    int res = 1;
    while(x > 0){
        res = res * g % p;
        x--;
    }
    // Time measurement
    *t = clock() - *t;
    double time_taken = ((double)(*t))/CLOCKS_PER_SEC; // in seconds
    //printf("Tempo: %lf secondi", time_taken);

    return time_taken;
}