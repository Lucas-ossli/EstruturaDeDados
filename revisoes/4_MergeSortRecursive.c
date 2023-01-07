#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void mergeSortR(int array[], int size );
void merge(int lowHalf[],int lowSize, int upperHalf[],int upperSize, int array[]);

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
	
	mergeSortR(array1,size);
	
	
	
	printf("\nVetor Ordenado \n\n");
	for(i=0 ; i < size ; i++){
		
		printf("  %d", array1[i]);
	}
	
	printf("\n\n");
	return 0;
	
}

void mergeSortR(int array[], int size ){
	
	
	if(size == 1){
		return;
	}
	
	int i;
	int *lowHalf;
	int lowSize;
	int *upperHalf;
	int upperSize;
	
	
	
	lowSize = size/2;
	lowHalf = (int *)malloc(lowSize*sizeof(int));
	for(i=0 ; i < lowSize ; i++){
		
		lowHalf[i] = array[i];
		
	}
	
	
	upperSize = size-lowSize;
	upperHalf =(int *)malloc(upperSize*sizeof(int));
	for(i=lowSize ; i<size ; i++){
		
		upperHalf[i-lowSize] = array[i];
		
	}
	
	
	mergeSortR(lowHalf, lowSize);
	mergeSortR(upperHalf, upperSize);
	
	
	merge(lowHalf, lowSize, upperHalf, upperSize, array);
	//Compreensão: da a entender de que o         array  é o primeiro passado la
	//no código principal(Main), mas se vc reparar bem na verdade é o array dividido ao meio
	//o lowHalf OU upperHalf, então isso significa que oque está sendo juntado(merge)
	//é os array dividos, e não o principal passado dentro da função Main.
	

		return;	
}

void merge(int lowHalf[],int lowSize, int upperHalf[],int upperSize, int array[]){
	
	int i,j,p,size;
	
	i = 0;
    j = 0;
    size = lowSize+upperSize;
	
	for(p=0 ; p < size ; p++ ){
	   
        
        if ( lowHalf[i] <= upperHalf[j] ) {
			array[p] = lowHalf[i];
			i++;
			if ( i == lowSize ) {
				while ( j < upperSize ) {
					p++;
					array[p] = upperHalf[j];
					j++;
				}
			}
		}
		else {
			array[p] = upperHalf[j];
			j++;
			if ( j == upperSize ) {
				while ( i < lowSize ) {
					p++;
					array[p] = lowHalf[i];
					i++;
				}
			}
		}
		
                	
	}
}




























