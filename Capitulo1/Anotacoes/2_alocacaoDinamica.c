#include <stdio.h>
#include <stdlib.h>



void main(){
	
	int * p1;
	double *p2;
	int tamanho;
	
	printf("tamhno de int: ");
	scanf("%d", &tamanho);
	p1 = (int *)malloc( tamanho * sizeof(int));
	
	
	printf("tamhno de double: ");
	scanf("%d", &tamanho);
	p2 = (double *)malloc(tamanho* sizeof(double));
	
	
	//endereços e conteúdos dos ponteiros  - MEMÓRIA STACK
	printf("\nendereco de p1:#%p conteudo de p1:#%p \n", &p1, p1);
	
	
	
	
	// preenche a área dinamicamente alocada com números aleatórios entre 0 e 99
	int k;
	for ( k = 0; k < tamanho; k++ ) {
		p1[k] = rand()%100;       // p1[k] é o mesmo que *(p1 + k)
	}
	
	for ( k = 0; k < tamanho; k++ ) {
		p2[k] = rand()%100;       // p2[k] é o mesmo que *(p2 + k)
	}
	
	
	int i;
	for( i=0 ; i< tamanho ; i++){
		printf("\nconteudo p1[%d]: %d ; Endereco p1[%d]:#%p ",i, p1[i], i , &p1[i] );
	}
	
	
	printf("\n\nDouble\n");
	
	printf("\nendereco de p2:#%p conteudo de p2:#%p \n", &p2, p2);
	
	for( i=0 ; i<tamanho ; i++){
		
		printf("\nConteudo p2[%d]:%f ; Endereco de p2[%d]:#%p", i, p2[i], i, &p2[i] );
	}
	
	return 0;
	
}





