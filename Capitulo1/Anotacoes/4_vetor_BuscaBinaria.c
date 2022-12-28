#include <stdio.h>
#include <stdlib.h>


int main(){
	
	
	int *vetor;
	int tamanho,i;
	
	printf("Digite o tamanho do vetor");
	scanf("%d",&tamanho);
	
	vetor = (int *)malloc(tamanho * sizeof(int));
	
	vetor[0] = 1 + rand()%100;
	printf("\n\nVetor\n");
	printf("%d  ",vetor[0]);
	for(i=1 ; i<tamanho ; i++){
		vetor[i] = vetor[i-1] + rand()%100;
		printf("%d  ",vetor[i]);
	}
	
	int chave = vetor[rand()%tamanho];
	printf("\n\nchave:%d",chave);
	buscaBinaria(vetor, tamanho, chave);
	return 0;
}



void buscaBinaria(int *vetor2, int tamanho,int chave){
	
	int i,inicio,condicao,final,meio;
	condicao = 1;
	
	inicio=0;
	final=tamanho-1;
	
	printf("\n\nvetor 2:\n\n");
	for(i=0 ; i< tamanho ; i++){
		printf("%d  ", vetor2[i]);
	}
	i=0;
	while(condicao == 1){
		i++;
		meio = (inicio +final)/2;
		
		if(chave == vetor2[meio])
		{
			printf("\n\nachou o numero:%d na posicao:%d  na %d tentativa \n\n\n",chave, meio, i);
			condicao=0;
		}
		else
		{
			if(chave > vetor2[meio])
			{
				inicio = meio+1;
			}
			else
			{
				final = meio-1;
			}
		}
	}
	
}
