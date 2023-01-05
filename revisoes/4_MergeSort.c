#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>


void selectionSort(int array[], int size, bool second);

void merge(int array[], int size );

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i,size;
	
	printf("\nSize of the array: ");
	scanf("%d", &size);
	int array1[size];
	
	printf("\n\nVetor Inicial Não ordenado \n\n");
	for(i=0 ; i < size ; i++){
		array1[i] = rand()%9874;
		
		printf("  %d", array1[i]);
	}
	
	selectionSort(array1, size/2, false);
	selectionSort(array1, size, true);
	
	
	printf("\n\nVetor dividido ao meio e cada uma das partes ordenadas por sí só \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	merge(array1, size);
	
	printf("\nVetor Ordenado \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	printf("\n\n");
	return 0;
	
}

void merge(int array[], int size ){
	
	int halfSize = size/2; 
	int i,j,k;
	j=0;
	k=0;
	
	int lowHalf[size/2];
	int highHalf[size/2];
	
	printf("\n\n");
	for (i = 0 ; i<halfSize ; i++){
		lowHalf[i] = array[i];
		highHalf[i] = array[i+halfSize];
	}
	

	for(i=0 ; i < size ; i++){
		
		if(lowHalf[j] <= highHalf[k]){
			
			array[i] = lowHalf[j];
			j++;
			
			if(j == (size/2)-1){
				
				while(k < size/2){
					i++;
					array[i] = highHalf[k];
					k++;
				}
				i++;
			}
			
		}else{
			
			array[i] = highHalf[k];
			k++;
			
			if(k == (size/2)-1){
				
				while(j < size/2){
					i++;
					array[i] = lowHalf[j];
					j++;
				}
				i++;
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