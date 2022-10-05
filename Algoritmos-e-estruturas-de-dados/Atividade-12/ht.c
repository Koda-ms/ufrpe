#include "ht.h"
#include <stdlib.h>
#include <stdio.h>


// Cria uma nova tabela de hashing com colisões
// tratadas por encadeamento
HT *cria_ht(int M) {
    HT *t = malloc(sizeof(HT));
    t->M = M;
    t->V = malloc (M * sizeof (celula *));
    for(int k = 0; k < M; t->V[k++] = NULL);
    return t;
}

int hash(int ch, int M) {
    return ch % M;
}


// Insere uma chave ch na tabela de hashing t.
// Se ch não pertence à tabela, o valor da nova
// célula criada é 1.
// Se já pertence, incrementa o valor.

void put(HT *t, int ch) {
    int h = hash (ch, t->M);
    celula *p = t->V[h];

    p = busca(ch, p);
    if (p != NULL)
        p->v += 1;
    else
        t->V[h] = insere(ch, 1, t->V[h]);
}

// Devolve o valor associado à chave ch na tabela t.
// Se ch não está na tabela, devolve -1.
int get(HT *t, int ch) {

    int h = hash (ch, t->M);
    celula *p = t->V[h];

    p = busca(ch, p);

    return p ? p->v : -1;

}

void printHT(HT *t) {

    int k;
    celula *p;

    for(k = 0; k < t->M; k++) {
        printf("%d: ", k);
        for(p = t->V[k]; p != NULL; p = p->prox)
            printf("(%d, %d) ", p->chave, p->v);
        printf("\n");
    }

}
