#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//https://www.thehuxley.com/problem/3127?locale=pt_BR

int main(){
	
	float gravidade,velocidade;
	float altura;
	float tetha;
	
	scanf("%f", &tetha);
	scanf("%f", &velocidade);
	scanf("%f", &gravidade);
	tetha = sin(tetha);
	printf("%f  %f  %f", tetha, velocidade, gravidade);
	altura = ((velocidade*velocidade)*tetha*tetha  )/2*gravidade;
	
	printf("\n%f",altura);
	return 0;
}