#include <stdio.h>
#include <stdlib.h>


//https://www.thehuxley.com/problem/2818?locale=pt_BR


int main(){
	
	
	
	float n;
	
	scanf("%f", &n);
	printf("Digite o pH da solucao:");
	if(n < 0){
		printf("\nValor do pH deve estar entre 0 e 14");
	}
	else if(n<7){
		//ácida
		printf("\nSolucao acida");
	}else if(n>7){
		//básica
		printf("\nSolucao basica");
	}else{
		
		//neutra
		printf("\nSolucao neutra");
	}
	
	
	return 0;
}