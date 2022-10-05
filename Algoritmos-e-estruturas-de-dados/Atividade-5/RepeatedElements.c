#include <stdio.h>

#define TAM 8

int partition(int, int, int*);
void quickSort(int, int, int*);
int coutintSort(int, int*);

int main(){ 

    int veti[TAM] = {8,3,7,4,7,1,9,1};
   
    quickSort(0, TAM-1, veti);
    
    for (int k = 0; k < TAM; k++)
    {
        printf("%d ", veti[k]);
    }
    printf("\n");

    int* repeated = coutingSort(10, veti);

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", repeated[k]);
    }
    
}

int partition(int l, int r, int veti[]){
    int x = veti[r];
    int aux, j = l;

    for (int i = l; i < r; i++)
    {
        if (veti[i] <= x)
        {
            aux = veti[j];
            veti[j] = veti[i];
            veti[i] = aux;
            j++;
        }
    }
    aux = veti[j];
    veti[j] = veti[r];
    veti[r] = aux;

    return j;
}

void quickSort(int l, int r, int veti[]){

    if (l < r)
    {
        int pivot = partition(l, r, veti);
        quickSort(l, pivot-1, veti);
        quickSort(pivot+1, r, veti);
    }
}

int* countingSort(int arr_count, int* arr, int* result_count) {
  *result_count = 100;
  int *result = malloc(100*sizeof(int));
  int *sorted = malloc(100*sizeof(int));
  
  int max = arr[0];
  for (int i = 1; i < arr_count; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  
  for(int i = 0 ; i <= 100; i++){
    result[i] = 0;
  }
  for(int i = 0; i < arr_count; i++){
    result[arr[i]]++; 
  }
  for (int i = 1; i <= max; i++) {
    result[i] += result[i-1];
  }
  for (int i = arr_count - 1; i >= 0; i--) {
    sorted[result[arr[i]]-1] = arr[i]; //i = 99
    result[arr[i]]--;
  }
  return sorted;
}