#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int modexp(int g, int x, int p);
int int2bit(int x, int* rappr);

int int2bit(int x, int* rappr){
    /*  Converts integer x into its binary representation,
        returns the index of last bit = 1
    */

    int last = 0;
    for (int i = 0; i < sizeof(int)*8; i++){
        rappr[i] = x & 1;
        if (rappr[i] == 1)
            last = i;
        x = x >> 1;
    }
    return last;
}

int modexp(int g, int x, int p){
    /* Performs g^x mod p w/ Square and Multiply algorithm */

    //Calculate bit representation of x
    int* rappr =  (int*)malloc(sizeof(int)*sizeof(int)*8);
    int n = int2bit(x, rappr) + 1;  //Lengh of bits necessary
    //Calculate modexp
    unsigned long long res = 1;
    for (int i = n - 1; i >= 0; i--){
        res = (res*res)%p;
        if (rappr[i] == 1)
            res = (res*g) % p;
    }
    
    return res;
}