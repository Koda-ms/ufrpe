#include <stdio.h>
#include "pq.h"

static void troca (int A, int B) {
    int t = A; A = B; B = t;
}

// Funções que implementam uma fila de prioridades

pq criapq(int N) {
    pq p = (pq) malloc(sizeof(struct spq));
    p->v = (int *) malloc(N * sizeof(int));
    p->N = N;
    p->m = 0;
}

void insere(pq p, int k) {
    p->m++;
    p->v[p->m] = k;
    corrigeSubindo(p->m, p->v);
}

int extraimax(pq p) {
    int max = p->v[1];
    p->v[1] = p->v[p->m];
    p->m--;
    peneira (p->m, p->v);
    return max;
}

void imprimepq(pq p) {
    int i;

    printf("N: %d \n", p->N);
    printf("m: %d \n", p->m);
    for(i = 1; i <= p->m; i++)
        printf("%d ", p->v[i]);
}


// Fonte: https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/heap.html#fix-up
static void
corrigeSubindo (int m, int v[]) {
    int k = m;
    while((k >= 2) && (v[k/2] < v[k])) {
        int x = v[k/2]; v[k/2] = v[k]; v[k] = x;
        k /= 2;
    }
}

// Na sequência, código literal ou adaptado de P. Feofiloff
// Tirado de https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void
constroiHeap (int m, int v[])
{
   for (int k = 2; k <= m; ++k) {
      // v[1..k-1] é um heap
      corrigeSubindo(k, v);
   }
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.
static void
peneira (int m, int v[])
{
   int p = 1, f = 2, x = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}


void
heapsort (int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      int x = v[1]; v[1] = v[m]; v[m] = x;
      peneira (m-1, v);
   }
}

