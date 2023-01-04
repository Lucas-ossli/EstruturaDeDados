#include <stdlib.h>
#include <stdio.h>

void selectionSort(int array[], int size);

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
	
	selectionSort(array1, size/2);
	size = size + (size%2);
	size = size/2;
	selectionSort(array1[size], size)
	
	//TO DO
	merge();
	
	
	
	printf("\n\nVetor 2nd \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	printf("\n\n");
	return 0;
	
	
	
	
}


void selectionSort(int array[], int size){
	
	int i,j,min,place,i_min;
	
	place=0;
	
	for (i=1 ; i <size ; i++){
		
		min = array[place];
		i_min = place;
		
		
		for(j=place+1; j < size ; j++){
			
			if(min > array[i]){
				
				min = array[j];
				i_min = j;
			}
			
		}
		
		array[i_min] = array[place];
		array[place] = smaller; 	
		
		place++;
	}
}