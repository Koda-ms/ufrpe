#include "random.h"
#include "vutil.h"

// Funções utilitárias para criação de vetores

// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n) {

   return (int *) malloc(n * sizeof(int));

}

// Devolve um vetor crescente de inteiros
// de tamanho n.
veti
vcresc(int n) {

    int *v = (int *) malloc(n * sizeof(int));
    int j;
    for(j = 0; j < n; j++)
        v[j] = j;

    return v;

}

// Devolve um vetor decrescente de inteiros
// de tamanho n.
veti
vdecresc(int n) {

    veti v = criaveti(n);
    int j;
    for(j = 0; j < n; j++)
        v[j] = n - 1 - j;

    return v;

}

// Devolve um vetor de inteiros
// pseudo-aleatórios, cada um
// no intervalo entre low e high, inclusive.
veti
valeat(int n, int low, int high) {

    Randomize();
    veti v = criaveti(n);
    int j;
    for(j = 0; j < n; j++)
        v[j] = RandomInteger(low, high);

    return v;

}
