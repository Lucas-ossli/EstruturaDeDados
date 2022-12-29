#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>

//https://thehuxley.com/problem/1041?locale=pt_BR

int main(){
	
	char palavra[10];
	int tamanho,i;
	
	scanf("%s",&palavra);
	
	for(i = 0; verificar(&palavra) != 1  ; i++){
		tamanho = tamstr(&palavra);
		printf("%d\n",tamanho);
		scanf("%s",&palavra);
	}
	
	return 0;
}

int tamstr (char *palavra){
	 char *ponteiro;
	 ponteiro = palavra;
 	 int comprimento = 0;
      
	  while ( palavra[comprimento] != NULL ){
	      ponteiro = ponteiro + sizeof(char);
		  ++comprimento;
	}
	
	int tamanho;
	tamanho = ponteiro-palavra;//Subtração de ponteiros de acordo com o exercício;
	
	return tamanho; //ou return comprimento;
	
}


int verificar(char *palavra){
	
	int i;
	char chave[] = "FIM";
	for(i=0 ; i<4 ; i++){
		
		if(palavra[i] != chave[i]){
			return 0;
		}
	}
	 return 1;
}
