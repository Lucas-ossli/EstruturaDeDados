#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int size);


int main(){
	
	
	int n,d,i,j;
	j=0;
	
	scanf("%d %d",&n,&d);
	int array1[n];
	int biggerN[n];
	
	
	for(i=0 ; i < n ; i++){
		scanf("%d", &array1[i]);
		biggerN[i] = -1;
	}
	
	for(i=0 ; i < n ; i++){
		
		// se (array[i] - d)%10 == 0  
		if( (array1[i]-d)%10 == 0 ){
			biggerN[j] = array1[i];
			j++;
		}
		
	}
	
	bubbleSort(biggerN, n);
		
	for(i=n-5 ; i < n ; i++){
		printf("\n%d", biggerN[i]);
	}
	
	return 0;
}

void bubbleSort(int array[], int size){
	
	int i,j;
	
	for(i=0 ; i<size-1 ; i++){
		
		for(j=0 ; j<size-i-1 ; j++){
			
			if(array[j] > array[j+1]){
				
				int aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
		
	}
	
}