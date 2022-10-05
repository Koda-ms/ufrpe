#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"
#include "random.c"
 
#define TAM_INI 1000
#define TAM_MAX 5000
#define INC 100
 
// simpio.h e random.h veem da biblioteca de
// Eric Roberts, acessível por exemplo em
// https://www.ime.usp.br/~pf/Roberts/C-library/standard/
 
typedef int *veti; // Apelida de "veti" ("vetor de inteiros") o tipo "int *".
 
veti criaveti(int);
int busca (int, int, int *);
void insertionSort(int, int *);
int buscaBinaria(int, int, int*);
int maximo (int, int *);
int twosum (int, int, int *);
 
int NOP;
 
int main() {
 
    int n, k, x, r;
    veti v;
 
    Randomize();
 
    FILE *saida;
    saida = fopen ("dados.dat", "w");
 
    for(n = TAM_INI; n <= TAM_MAX; n += INC) {
        v = criaveti(n);
        for(k = 0; k < n; k++)
            v[k] = RandomInteger(0, 100);
 
        insertionSort(n, v);
        x = RandomInteger(0, 100);
        //r = maximo(n, v);
        //r = busca(x, n, v);
        r = buscaBinaria(x, n, v);
        //r = twosum(x, n, v);
        fprintf(saida, "%d %d\n", n, NOP);
 
        free(v);
    }
 
    fclose(saida);
 
    return 0;
}
 
int busca (int x, int n, int v[]) {
    int k;
    k = n - 1;
    NOP = 0;
    while (k >= 0 && v[k] != x) {
        k -= 1;
        NOP++;
    }
    return k;
}
 
void insertionSort(int n, int v[]){
  int aux, j;
  NOP = 0;
 
  for (int i = 1; i < n; i++)
  {
      aux = v[i];
      j = i - 1;
 
      while (j >= 0 && aux < v[j])
      {
	    NOP++;
          v[j+1] = v[j];
          j--;
      }
      v[j+1] = aux;
  }
}
 
int buscaBinaria(int x, int n, int v[]){
    int b = 1, e = n, m;
    NOP = 0;
 
    while (b <= e)
    {
        NOP++;
        m = (b+e) / 2;
 
        if(x > v[m]){
            b = m + 1;
        } else if(x < v[m]){
            e = m - 1;
        } else{
            return m;
        }
    }
    return 0;  
}
 
int maximo (int n, int v[]) {
    int k, m = v[0];
    NOP = 0;
    for(k = 1; k < n; k++) { 
        NOP++;
        if(v[k] > m) 
            m = v[k]; 
    }
    return m;
}
 
 
int twosum (int k, int n, int v[]) {
 
    int i, j, r;
 
    NOP = 0;
    r = 0;
 
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            NOP++;
            if(v[i] + v[j] == k)
                r = 1;
        }
 
 
    return r;
 
}
 
 
 
 
 
 
// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n) {
 
 
   return (int *) malloc(n * sizeof(int));
 
 
}
