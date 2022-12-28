#include <stdlib.h>
#include <stdio.h>


//https://thehuxley.com/problem/3622?locale=pt_BR


int main(){
	
	int a,b;
	int sobra=0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	calcularMedia(&a,&b,&sobra);
	
	return 0;
}

void calcularMedia(int *a, int *b,int *sobra)
{
	if(*a < *b){
		*sobra = (*b+*a)%2;
		* a = (*a+*b)/2;
		*b = *sobra;
	}else{
		*sobra = (*a+*b)%2;
		*b = (*a+*b)/2;
		*a = *sobra;
	}
	printf("A = %d\nB = %d",*a,*b);
}