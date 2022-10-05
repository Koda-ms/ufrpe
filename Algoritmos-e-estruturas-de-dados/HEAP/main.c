#include <stdio.h>
#include <stdlib.h>
#include "pq.h"


int main() {

    pq p = criapq(500);

    insere(p, 40);
    insere(p, 90);
    insere(p, 100);
    insere(p, 60);
    insere(p, 150);
    insere(p, 110);
    insere(p, 105);
    insere(p, 200);
    insere(p, 70);
    insere(p, 130);

    imprimepq(p);

    int x = extraimax(p);
    printf("\nMaximo: %d\n", x);
    imprimepq(p);


    return 0;
}
