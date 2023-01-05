#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void selectionSort(int array[], int size, bool second);

void merge(int array[], int size );

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
	
	selectionSort(array1, size/2, false);
	selectionSort(array1, size, true);
	

	printf("\n\nVetor 2nd \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	//
	
	//
	merge(array1, size);
	
	printf("\n\nVetor 2nd \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	
	printf("\n\n");
	return 0;
	
	
	
	
}

void merge(int array[], int size ){
	//TO DO - Refatorar
	int halfSize = size/2; 
	int i,j,k;
	j=0;
	k=0;
	
	int lowHalf[size/2];
	int highHalf[size/2];
	
	for (i = 0 ; i<halfSize ; i++){
		
		lowHalf[i] = array[i];
		highHalf[i] = array[i+halfSize];
	}
	
	
	for(i=0 ; i < size ; i++){
		
		if(lowHalf[j] <= highHalf[k]){
			
			array[i] = lowHalf[j];
			j++;
			
			if(j+1 == size/2){
				i++;
				while(j+1 < size){
					i++;
					array[i] = highHalf[j-1];
					j++;
				}
				
			}
			
		}else{
			
			array[i] = highHalf[k];
			k++;
			
			if(k+1 == size/2){
				i++;
				while(k+1 < size){
					i++;
					array[i] = lowHalf[k-1];
					k++;
				}
			}
		}
		
		
	}
	
	
}



void selectionSort(int array[], int size,bool second){
	
	int i,j,min,place,i_min;
	
	place=0;
	
	i=1;
	
	if(second){
		i = (size/2) + (size%2);
		place = i;
	}
	
	
	
	for (i ; i <size ; i++){
		
		min = array[place];
		i_min = place;
		
		
		for(j=place+1; j < size ; j++){
			
			if(min > array[j]){
				
				min = array[j];
				i_min = j;
			}
			
		}
		
		array[i_min] = array[place];
		array[place] = min; 	
		
		place++;
	}
}