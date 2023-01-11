#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int *p1;
	double *p2;
	
	int tamanho,i;
	
	printf("Defina o tamanho dos vetores: ");
	scanf("%d",&tamanho);
	
	p1 = (int *)malloc(tamanho*4);
	p2 = (double *)malloc(tamanho*sizeof(double));
	
	
	for( i = 0 ; i<tamanho;i++){
		p1[i] = rand()%100;
		p2[i] = rand()%89;
	}
	
	printf("\nConteudo p1:#%p \t|Endereco p1:#%p\n", p1,&p1);
	for(i=0 ; i<tamanho ; i++){
		
		printf("\nConteudo de p1[%d]:%d \t| Endereco:#%p\n",i, p1[i], &p1[i]);
	}
	
	
	printf("\nConteudo de p2:#%p \t| Endereco de p2:#%p\n", p2, &p2 );
	for(i=0 ; i<tamanho ; i++){
		
		
		printf("\nConteudo de p2[%d]:%.3f \t| Endereco p2[%d]:#%p\n", i, p2[i] , i, &p2[i]  );
	}
	
	free(p2);
	free(p1);
	
	return 0;
}