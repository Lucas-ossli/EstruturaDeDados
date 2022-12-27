#include <stdio.h>


void main(){
	int a,b;
	scanf("%d", &a);
    scanf("%d", &b);
	printf("a: %d b: %d\n", a, b);
	
	trocaValor(&a,&b);
	
	printf("a: %d b: %d\n", a, b);
	
	return 0;	
}

void trocaValor(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}