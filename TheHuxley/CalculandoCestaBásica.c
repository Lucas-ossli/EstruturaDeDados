#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//https://www.thehuxley.com/problem/3658?locale=pt_BR


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[27],quantidadeCesta,i,j;
	float doacao,preco;
	preco=0;
	float cesta[27] = { 5.50 , 6.00,7.50,1.99,4,6.7,1.2,2.8,5.3,5,3,2,3.5,0.8,1,0.8,5.4,1.9,5,10,0.5,0.5,5,4.5,1.99,2.9,0.3};
	char vetorQuantidade[60];
	char *charNumber;
	
	
	
	
	scanf("%s", vetorQuantidade);
	
	for(i=0, j=0 ; i< 27 ; i++ ,j=j+2){
		charNumber = &vetorQuantidade[j];
		vetor[i] = atoi(charNumber);
	}

	scanf("%f", &doacao);	
	
	for(i=0 ; i< 27 ; i++){
		
		if(vetor[i] > 0){
			
			preco = preco+  vetor[i]*cesta[i];
		}
	} 
	
	quantidadeCesta= doacao/preco;
	printf("O valor da cesta básica ficou em: R$%.2f\n", preco);
	printf("Com o valor doado pode ser comprada %d cestas básicas", quantidadeCesta);
	
	
	return 0;
}