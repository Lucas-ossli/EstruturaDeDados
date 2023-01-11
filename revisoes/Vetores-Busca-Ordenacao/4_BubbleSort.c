#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int size);

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
	
	bubbleSort(array, size);
	
	
	printf("\n\nArray after being sorted 2nd \n\n");
	for(i=0 ; i < size ; i++){
		printf("  %d", array[i]);
	}
	
	printf("\n\n");
	
	return 0;
}


void bubbleSort(int array[], int size){
	
	int i,j;
	
	for(i=0 ; i < size-1 ; i++){
		
		for ( j=0 ; j< size-i-1 ; j++){ // Toda vez que o i passa no vetor e ordena, o maior elemento sempre ira para o final do vetor, 
										// por isso é possivel fazer (size-i-1 ) ( isso diminui o tamanho máximo que sera percorrido na próxima vez ) 
										//pois vc já tem a certeza que o maior valor sempre estará no ultimo elemento vigente;
			if(array[j] > array[j+1]){
				
				int aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
				
			}
		}
	}
	
}

