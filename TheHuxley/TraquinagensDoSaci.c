#include <stdio.h>
#include <stdlib.h>

void bubbleSort(float *array);

//https://www.thehuxley.com/problem/3773?locale=pt_BR


int main(){
	
	int i;
	int idade[5];
	float nota[5];
	char nomes[5][20];
	
	float *pnota;
	pnota = &nota;
	//nota = (float *)malloc( 5 * sizeof(float));
	
	for(i=0 ; i < 5 ; i++){
		scanf("%s",nomes[i]);
		scanf("%f %d", &nota[i], &idade[i]);
	}
	
	bubbleSort(pnota);
	
	for(i=0 ; i < 5 ; i++){
		printf("%s %.2f %d\n", nomes[i], nota[i], idade[i]);
	}
	
	
	return 0;
}


void bubbleSort(float *array){
	
	
	int i,j,aux;
	
	for(i=0 ; i< 5-1 ; i++){
		
		for(j=0 ; j < 5-i-1 ; j++){
			
			if(array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
		
	}
	
}