// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html

#include "ll.h"

typedef struct ht_ HT;
struct ht_ {
    int M;
    celula **V;
};

int hash(int, int);
HT *cria_ht(int);
void put(HT *, int);
int get(HT *, int);
void printHT(HT *);
