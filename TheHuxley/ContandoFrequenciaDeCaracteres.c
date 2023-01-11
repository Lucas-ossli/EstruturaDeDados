#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.thehuxley.com/problem/2835?locale=pt_BR



typedef struct{
		char *letra;
		int quantidade;
}UNIDADE;


void selectionSort(UNIDADE *unidades, int size);

void existeNaStruct(char array[], UNIDADE *unidades, int *local);



int main(){
	
	int i,local;
	char texto[256];
	UNIDADE unidades[256];
	local=0;
	
	for(i=0 ; i < 256 ; i++){
		unidades[i].letra = '\0';
		unidades[i].quantidade = 0;
	}
	
	scanf("%[^\n]%*c", texto);
	
	for(i=0 ; i < strlen(texto) ; i++){
		
		existeNaStruct(texto[i], &unidades, &local);
		
	}
	
	
	selectionSort(&unidades, strlen(texto));
	
	
	for(i=255 ; i > 0 /*&& unidades[i].quantidade > 0 */  ;i--){
		if(unidades[i].quantidade > 0){
			printf("\n%c %d",unidades[i].letra, unidades[i].quantidade );
		}
	}
	return 0;
}


void existeNaStruct(char array[], UNIDADE *unidades, int *local){
	
 	int i;
	
 	for(i=0 ; unidades[i].letra != '\0' ; i++){
		
 		if(unidades[i].letra == array){
 			unidades[i].quantidade++;
			 return;	
 		}
 	}
	
	 unidades[*local].letra = array;
	 unidades[*local].quantidade++;
	 *local= *local+1;
	return;
 }


void selectionSort(UNIDADE *unidades, int size){
	
	int  i_smaller, place, i,j;
	
	UNIDADE *smaller;
	
	smaller=(UNIDADE *)malloc(1*sizeof(UNIDADE));
	
	place = 0;
	
	for(i=1 ; i < size ; i++){
		
		*smaller =  unidades[place];
		i_smaller = place;
		
		for(j=place+1 ; j <size ; j++){
			
			
			if(unidades[j].letra < smaller[0].letra ){
				
				*smaller = unidades[j];
				i_smaller = j;
				
			}
			
		}
		
		   unidades[i_smaller] = unidades[place];
		   unidades[place] = *smaller; 	
		
		place++;
	}
	
}
