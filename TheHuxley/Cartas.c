#include <stdio.h>

//https://www.thehuxley.com/problem/387?locale=pt_BR

int main(){
	
	
	int cartas[5];
	int i,k,j;
	
	scanf("%d %d %d %d %d", &cartas[0], &cartas[1], &cartas[2], &cartas[3], &cartas[4]);
	
	
	for(k=0,j=0 ,i=1 ; i < 5 ; i++){
		
		if(cartas[i-1] > cartas[i]){
			k++;
		}
		
		if(cartas[i-1] < cartas[i]){
			j++;
		}
	}
	
	if(k==4){
		
		printf("D");
		return 0;
	}
	
	if(j==4){
		printf("C");
		return 0;
	}
	
	printf("N");
	return 0;
}