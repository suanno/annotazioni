#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "mylib.h"

double my_fun(double* vec, double val);

int main(int argc, char** argv) {
    double res;
    printf("Hello world from main\n");
    res = mylibfun(1);
    
    return 1;
}


double my_fun(double* vec, double val){
    return 1;
}