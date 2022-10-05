#include <stdio.h>

#define TAM 7

void quickSort(int, int*);
int findMedian(int, int*);

int main(){ 

    int arr[TAM] = {0,1,2,4,6,5,3};
    
    quickSort(TAM, arr);
    int result = findMedian(TAM, arr);

    for (int k  = 0; k < TAM; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    printf("A mediana eh: %d", result);
    
    
}

void quickSort(int arr_count, int* arr){
  int aux, pivot = arr[TAM-1];
  
  for (int i = 0; i < arr_count-1; i++) {
    if (arr[i] <= pivot) {
      for(int j = i; j > 0; j--){
  
        aux = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = aux;
      }
    }
  }
}

int findMedian(int arr_count, int* arr) {

  int median = arr_count / 2;
  int x = arr[median];
  
  return x;
  
}








/*void quickSort(int arr_count, int* arr){
  int aux, pivot = arr[6], j =0;
  
  for (int i = 0; i < arr_count-1; i++) {
    if (arr[i] > pivot) {
      for( j = i; j > 0; j--){
          
        aux = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = aux;
        
      }
    }
  }
}

int findMedian(int arr_count, int* arr) {
  
  quickSort(arr_count, arr);
  int median = arr_count-1 / 2;
  int x = arr[median];
  
  return x;
  
}*/