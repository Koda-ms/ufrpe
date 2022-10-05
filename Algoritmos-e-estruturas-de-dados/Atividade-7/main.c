#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"
#include "random.c"

#define TAM_INI 1000
#define TAM_MAX 10000
#define INC 500

// simpio.h e random.h veem da biblioteca de
// Eric Roberts, acessível por exemplo em
// https://www.ime.usp.br/~pf/Roberts/C-library/standard/

typedef int *veti; // Apelida de "veti" ("vetor de inteiros") o tipo "int *".

veti criaveti(int);
int busca (int, int, int *);
void merge(int, int, int, int*);
void mergeSort(int, int, int*);
void insertionSort(int, int, int *);
void quickSortRec(int, int, int*);
void quickSortIte1(int, int, int*);
void quickSortIte2(int, int, int*);
int partition(int, int, int*);
int medianaAprox(int, int, int*);
int buscaBinaria(int, int, int*);
int maximo (int, int *);
int twosum (int, int, int *);
void troca(int, int, int*);

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

        //mergeSort(0, n, v);
        //insertionSort(1, n, v);
        //quickSortRec(0, n-1, v);
        quickSortIte1(0, n-1, v);
        //quickSortIte2(0, n-1, v);
        //x = RandomInteger(0, 100);
        //r = maximo(n, v);
        //r = busca(x, n, v);
        //r = buscaBinaria(x, n, v);
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

void merge(int p, int mid, int n, int v[]){
    int* e;
    int* d;
    e = malloc((mid-p+1)*sizeof(int));
    d = malloc((n-mid)*sizeof(int));

    int a1 = mid-p+1, a2 = n-mid; 
    int i, j ,k;

    for (i = 0; i < a1; i++)
    {
        e[i] = v[p+i];
    }
    for (j = 0; j < a2; j++)
    {
        d[j] = v[mid+j];//p+j
    }

    i = 1, j = 1, k = p; //i=0=j São os menores elementos de e[i] e d[j] que não foram copiados de volta em v[]
    while (i < a1 && j < a2)
    {
        if (e[i] <= d[j])
        {
            v[k] = e[i];
            i++;
        } else{
            v[k] = e[j];
            j++;
        }
        k++;
    }
    while (i < a1)
    {
        v[k] = e[i++];
        i++;
        k++;
    }
    while (j < a2)
    {
        v[k] = d[j++];
        j++;
        k++;
    }
    free(e);
    free(d);
}

void mergeSort(int p, int n, int v[]){
   
    if (p < n)
    {
        NOP++;
        int mid = (p+n)/2;

        if(n-p <= 16){
            insertionSort(p, mid, v); //ordenação na esquerda 
            insertionSort(mid+1, n, v); //ordenação na direita
            
        } else {
            mergeSort(p, mid, v); // divisão de listas à esquerda
            mergeSort(mid+1, n, v); // divisão de listas à direita
            merge(p, mid, n, v);
        }
    }
}

//Vetor ordenado em ordem crescente.
//Se aux > v[j], então o vetor estaria em ordem decrescente
void insertionSort(int p, int n, int v[]){
  int aux, j;
  NOP = 0;

  for (int i = p; i < n; i++)
  {
      NOP++;
      aux = v[i];
      j = i - 1;

      while (j >= 0 && aux < v[j])
      {
          v[j+1] = v[j];
          j--;
      }
      v[j+1] = aux;
  }
}

void quickSortRec(int p, int n, int v[]){

    NOP++;
    if(p < n){
        
        int pv = partition(p, n, v);
        quickSortRec(p, pv-1, v);
        quickSortRec(pv+1, n, v);
    }

}

void quickSortIte1(int p, int n, int v[]){
    int k = 0; //topo da pilha
    int* vp = malloc(n-p+1*sizeof(int)); //extremos inferiores
    int* vn = malloc(n-p+1*sizeof(int)); //extremos superiores
    
    vp[0] = p, vn[0] = n;
    
    while(k >= 0){ //Ou seja, enquanto não for vazia
        p = vp[k], n = vn[k], k--;
        NOP++;

        if(p < n){
            int pivot = partition(p, n, v);

            k++;
            vp[k] = p;
            vn[k] = pivot-1;

            k++;
            vp[k] = pivot+1;
            vn[k] = n;
        }
    }
}

/*void quickSortIte2(int p, int n, int v[]){
    int k = 0; 
    int* vp = malloc(n-p+1*sizeof(int)); 
    int* vn = malloc(n-p+1*sizeof(int)); 
    
    vp[0] = p, vn[0] = n;
    
    while(k >= 0){ 
        p = vp[k], n = vn[k], k--;
        //NOP++;

        if(p < n){
            int pivot = partition(p, n, v);

            //As condicionais seguintes são referentes à 4º questão: 
            //Após a partição vi[i...pivot-1] (esquerda)
            if(pivot - 1 > p){
                k++;
                vp[k] = p;
                vn[k] = pivot-1;
            }
            //vf[pivot+1...f] (direita)
            if(pivot + 1 < n){
                k++;
                vp[k] = pivot+1;
                vn[k] = n;
            }
        }
    }
}*/

int partition(int p, int n, int v[]){
    int meio = medianaAprox(p,n,v);
    int j = p;

    troca(meio, n, v);

    int piv = v[n];

    for(int l = p; l < n; l++){

        if(v[l] <= piv){
            troca(j, l, v);
            j++;
        }
    }
    troca(j, n, v);

    return j;
}

int medianaAprox(int p, int n, int v[]){
    int mid = (n+p) /2;
    int temp[3] = {v[p], v[mid], v[n]};

    //Tem que ordenar 'temp', caso não esteja, para saber a mediana
    if(temp[0] > temp[1]){
        troca(0, 1, v);
        
    } else if(temp[0] > temp[2]){
        troca(0, 2, v);
        
    } else if(temp[1] > temp[2]){
        troca(1, 2, v);
    }

    if(temp[1] == v[p]){
        return p;
    } else if(temp[1] == v[mid]){
        return mid;
    } else{
        return n;
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

void troca(int num1, int num2, int v[]){
  int aux;

  aux = v[num1];
  v[num1] = v[num2];
  v[num2] = aux;
}




// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n) {


   return (int *) malloc(n * sizeof(int));


}