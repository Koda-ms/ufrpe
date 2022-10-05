#include <stdio.h>

#define TAM_VETOR 10

//Teste da função "quickSort" e "partition"
void quickSort(int*, int, int);
int partition(int*, int, int);
int NOP;
int main(){ 

    
    int veti[TAM_VETOR] = {2,9,7,3,5,10,4,8,1,6};

    quickSort(veti, 0, TAM_VETOR-1);

    for (int l = 0; l < TAM_VETOR; l++)
    {
        printf("%i ", veti[l]);
    }
    printf("\n");
    printf("%d ", NOP);
    return 0;
}

//Método recursivo
void quickSort(int veti[], int p, int u){
    //NOP=0;
    if(p < u){
        NOP++;
        int j = partition(veti, p, u);
        quickSort(veti, p, j-1);
        quickSort(veti, j+1, u);
    }
}

int partition (int veti[], int p, int u) {
   int x = veti[u]; // pivô (o último)
   int aux, j = p;

   for (int i = p; i < u; ++i)
      
      if (veti[i] <= x) {
         
         aux = veti[j]; 
         veti[j] = veti[i]; 
         veti[i] = aux;
         ++j; 
      } 

   aux = veti[j];
   veti[j] = veti[u];
   veti[u] = aux;

   return j; 
}