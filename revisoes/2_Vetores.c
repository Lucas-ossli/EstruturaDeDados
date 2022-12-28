#include <stdio.h>

#define TAMANHO 100



void main(){
	
	int vetor[TAMANHO];
	vetor[0]= 0;
	int i;
	for( i = 1 ; i < TAMANHO ; i++ )
	{
		vetor[i] = vetor[i-1] + 1;
	}
	
	printf("\nvetor[1]: %d\n", vetor[2] );
	
	teste(vetor);
	
	printf("\nvetor[1]: %d", vetor[2] );
	
	
	return 0;
}

void teste(int b[])
//int vetor
{
	b[2]=100;
	printf("vetor da funcao:%d", b[2]);
}