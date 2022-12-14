#include <stdio.h>


void main(){
	
	
 int x = 5;
 int y = 10;
 int *pverificacao = &x;
 printf("%d\n", x);
 funct(&x);
 printf("%d\n", x);
 
 //Meu teste para entender o conteudo:
 x = 5;
 
 printf("\nFuncao Soma: \n\n");
 
 printf("valor de x:%d\n", x);
 printf("Valor de y:%d\n\n", y);
 soma(&x,&y);
 
 printf("\n\nDepois da funcao Soma\n\nx:%d\n", x);
 printf("y:%d\n\n", y);
 
 
 printf("\n\nLocal da memoria de x: #%p", &x);
 printf("\nValor de x: %d", x);
 
 printf("\n\nLocal da memoria do ponteiro (pverificacao): #%p", &pverificacao);
 printf("\nvalor do ponteiro (pverificacao) #%p\n\n", pverificacao);
	return 0;
}

void funct(int *py)
 //int *py;
 {
 ++(*py);
 printf("%d\n", *py);
 } /* end funct */

 
void soma(int *p1, int *p2)
 //int *p1,*p2;
 {
 	*p1 =*p1+*p2;
 	*p2 = *p1;
 	printf("p1:%d \np2:%d", *p1, *p2);
 }