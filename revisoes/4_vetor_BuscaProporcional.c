#include <stdlib.h>
#include <stdio.h>


void buscaProporcional(int vetor[] , int chave , float inclinacao, int tamanho);

int main(){
	
	
	int tamanho,i;
	float inclinacao;
	
	printf("Escolha o tamanho do vetor: ");
	scanf("%d",&tamanho);
	//vetor = (int *) malloc(tamanho * sizeof(int));
	int vetor[tamanho];
	if (vetor == 0 ){
	 	printf("\nErro na alocacao dinamica\n");
		return 0;
	}
	
	vetor[0] = rand()%999;
	for(i=1 ; i<tamanho ; i++){
		vetor[i] = vetor[i-1] + rand()%999;
	}
	
	
	
	inclinacao = (float)(vetor[0] - vetor[tamanho-1]) /tamanho;
	
	printf("\nVetor:\n");
	for(i=0 ; i < tamanho ; i++){
		printf("%d ", vetor[i]);
	}
	
	buscaProporcional(vetor, vetor[rand()%(tamanho-1)], inclinacao, tamanho);
	
	
	
	return 0;
}



void buscaProporcional(int vetor[] , int chave , float inclinacao, int tamanho){
	
	printf("\nCHAVE: %d", chave);
	int estimativa,tentativa,i;
	tentativa = 0;
	
	
	estimativa =  vetor[0] >= chave  ? 0 : (int)(chave - vetor[0])/inclinacao;
	estimativa = ( (estimativa >= tamanho-1) ? tamanho-1 : estimativa*-1 );
	estimativa = ( estimativa < 0 ? estimativa*-1 : estimativa);
	printf("\n\nestimativa:%d\n\n", estimativa);
	if(vetor[estimativa] == chave){
		printf("\n\nAchou o numero: %d na posicao: %d na %d tentativa\n\n"  , vetor[estimativa], estimativa , tentativa+1 );
		return;
	}
	
	
	if( vetor[estimativa] > chave){
		
		for(i=estimativa ; i >= 0 ; i--){
			tentativa++;
			if(vetor[i] == chave){
				printf("\n\nAchou o numero: %d na posicao: %d na %d tentativa\n\n"  , vetor[i], i , tentativa );
				return;
			}
			
		}
	}else{
		
		for(i = estimativa ; i< tamanho ; i++){
			tentativa++;
			if(vetor[i] == chave){
				printf("\n\nAchou o numero: %d na posicao: %d na %d tentativa\n\n"  , vetor[i], i , tentativa );
				return;
				
			}
		}
	}
	
	
	printf("\n\nNão Achou\n\n");
	return;
}
