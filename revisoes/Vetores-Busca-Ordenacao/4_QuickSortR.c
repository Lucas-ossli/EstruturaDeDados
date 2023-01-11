#include <stdio.h>
#include <stdlib.h>

int partition(int array[], int inicio, int fim);

void quickSort(int array[], int inicio, int fim);

int main(){
	
	
	int i,size;
	
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);
	int array[size];
	
	printf("\n\nArray 1st \n\n");
	for(i=0 ; i < size ; i++){
		array[i] = rand()%10000 - 1000;
		printf("  %d", array[i]);
		
	}
	
	
	
	
	quickSort(array,0,size-1);
	
	
	
	printf("\n\nArray after being sorted 2nd \n\n");
	for(i=0 ; i < size ; i++){
		printf("  %d", array[i]);
	}
	
	printf("\n\n");
	
	return 0;
}



void quickSort(int array[], int inicio, int fim){
	
	int pivo;
	
	
	if(inicio < fim){
		
		pivo = partition(array,inicio,fim);
		quickSort(array, inicio , pivo-1);
		quickSort(array, pivo+1, fim);
		
	}
	
	return;
	
	
}


int partition(int array[], int inicio, int fim){
	
	
	int pivo = array[fim];
	int i = inicio;
	int j,aux;
	
	for(j= inicio ; j < fim ; j++){
		
		if(array[j] <= pivo){
			
			aux = array[j];
			array[j] = array[i];
			array[i] = aux ;
			i++;
			
		}
		
	}
	
	aux = array[i];
	array[i] = array[fim];
	array[fim] = aux;
	
	
	
	return i;
}



























