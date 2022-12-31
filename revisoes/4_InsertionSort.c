#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[] , int size);



int main(){
	
	int i,size;
	
	printf("\nSize of the array: ");
	scanf("%d", &size);
	int array1[size];
	
	printf("\n\nArray 1st \n\n");
	for(i=0 ; i < size ; i++){
		array1[i] = rand()%10000 - 1000;
		
		printf("  %d", array1[i]);
	}
	
	insertionSort(array1, size);
	
	printf("\n\nVetor 2nd \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	printf("\n\n");
	
	
	return 0;
}


void insertionSort(int array[] , int size){
	
	int i,j,aux,place;
	place = 1;
	
	for(i=1 ; i <size ; i++ ){
		
		for(j = i ; j > 0 && array[j] < array[j-1] ;j-- ){
			
			aux = array[j];
			array[j] = array[j-1];
			array[j-1] = aux;
									
		}
			
	}
	
}









