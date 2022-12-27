#include <stdlib.h>
#include <stdio.h>

//https://thehuxley.com/problem/2342?locale=pt_BR

int main(){
	
	float x,y;
	
	scanf("%f", &x);
	scanf("%f", &y);
	
	reduz(&x,&y);
	
	return 0;
}

void reduz(float *x ,float *y){
	
	*x = *x-*y ;
	
	printf("%.2f %.2f", *x, *y );
}
