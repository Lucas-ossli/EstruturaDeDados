#include <stdio.h>
#include <stdlib.h>


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
	
	selectionSort(array1, size);
	
	printf("\n\nVetor 2nd \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	printf("\n\n");
	return 0;
}


void selectionSort(int array[], int size){
	
	int smaller, i_smaller, place, i,j;
	place = 0;
	
	for(i=1 ; i < size ; i++){
		
		smaller =  array[place];
		i_smaller = place;
		
		for(j=place+1 ; j <size ; j++){
			
			
			if(array[j] < smaller ){
				
				smaller = array[j];
				i_smaller = j;
				
			}
			
		}
		
		   array[i_smaller] = array[place];
		   array[place] = smaller; 	
		
		place++;
	}
	
}