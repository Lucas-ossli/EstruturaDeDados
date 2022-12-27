#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int main(){
	
	
	clock_t time;
	time = clock();
	
	
	char *filename = "Pi1MDP.txt" ;
	
	FILE *fp = fopen(filename, "r");
	
	if(fp == NULL){
		
		printf("ERROR");
		return 1;
	}
	
	const int MAX_LENGTH = 5; // quantidade de caracteres = n-1 
	char *buffer;
	
	int  i;
	char *a;

	for(i=0 ; i< 10/*0000/(MAX_LENGTH-1)*/ ; i++){
		
			fgets(buffer, MAX_LENGTH, fp);
			printf("Numero:%s | Ocorrencia:%d\n\n" , buffer,i);
			if(i==5){
				a = buffer;
				printf("\nchar 1:%c\n", a[1]);
				
			}
	}
	
	int b = atoi(a);
	//b[1] = atoi(a);
	printf("\nchar:%c",a[2]);
	
	if(a[2] == '7'){
		
		printf("\n O TESTE FUNCIONOU\n");
	}
	
	printf("\nint:%d",b);
	
	
	
	
	
	
	
	
	//tempo tomado
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	//tempo
	
	fclose(fp);
	
	
	printf("\nsegundos %f", time_taken);
	printf("\n%s", filename);
	
	
	
	
	
	return 0;
}



int palindromoDePi(int palindromo, char *string ){
	int i;
	for(i=palindromo ; i>0 ; i--);
//	char *copiaReversa = string[palindromo].
	
}