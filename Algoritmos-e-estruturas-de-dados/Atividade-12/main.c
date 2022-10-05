#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "ht.h"
#include "vutil.h"
#include "random.h"

#define N 50000000
#define M 1
#define low 0
#define high 100

int main()
{
    veti v = criaveti(N);
    int k;

    Randomize();
    HT *t = cria_ht(M);

    printf("M = %d\n", M);
    printf("Insere %d chaves aleatórias.\n", N);
    for(k = 0; k < N; k++)
        put(t, RandomInteger(low, high));

    printf("Faz %d buscas.\n", N);
    for(k = 0; k < N; k++)
        get(t, RandomInteger(low, high));

    //printHT(t);


    return 0;
}
