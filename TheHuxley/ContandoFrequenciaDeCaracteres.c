#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.thehuxley.com/problem/2835?locale=pt_BR



typedef struct{
		char *letra;
		int quantidade;
}UNIDADE;

void existeNaStruct(char array[], UNIDADE *unidades, int *local);



int main(){
	
	int i,local;
	char texto[256];
	UNIDADE unidades[128];
	local=0;
	
	for(i=0 ; i < 128 ; i++){
		unidades[i].letra = '\0';
		unidades[i].quantidade = 0;
	}
	
	
	
	scanf("%[^\n]%*c", texto);
	
	//unidades[0].letra = texto[0];
	//unidades[0].quantidade = 1;
	//local++;
	
	for(i=0 ; i < strlen(texto) ; i++){
		
		existeNaStruct(texto[i], &unidades, &local);
		
	}
	
	//TO DO: Ordenar a lista de letras//
	
	for(i=0 ; unidades[i].letra != '\0' ;i++){
		printf("\n%c  %d",unidades[i].letra, unidades[i].quantidade );
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


//TO DO: Ordenar a lista de letras//












