#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "EstruturaFila.h"


int isPrime(long long int num);
long long int convertToInt(struct queue decimaispi, int size);
int isPalidrome(struct queue decimaispi, int sizeOfDecimal);
void imprimirSemRemover(struct queue decimaispi, int sizeOfDecimal);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int palindromeSize=19,escolhaDeArquivo=4;
	int i,j;
	char *filename;
	int ocorrencia,testes;
	
	while(palindromeSize > 17)
	{	
		printf("\n|Número limite de casas decimais: 17");
		printf("\n|Digite o tamanho do palindromo que deseja procurar:  ");
		scanf("%d",&palindromeSize);//MAX 17 -- MAX (LONG LONG INT ) == 17
	}
	
	printf("\n|Digite a quantidade de ocorrências que deseja procurar ");
	printf("\n|Caso queira procurar todas as ocorrências digite 0:  ");
	scanf("%d",&testes);
	
	while(escolhaDeArquivo > 3){
		printf("\n|Em quantas casas decimais você deseja procurar?");
		printf("\n|1 -| 1   Milhão de casas decimais");
		printf("\n|2 -| 125 Milhão de casas decimais");
		printf("\n|3 -| 1   Bilhão de casas decimais");
		printf("\n|Digite sua opção: ");
		scanf("%d",&escolhaDeArquivo);
		system("cls");
	}
			
	switch(escolhaDeArquivo){
		case 1:
			filename = "Pi1MDP.txt";
			ocorrencia = 1000000-palindromeSize;
			break;
		case 2:
			filename = "Pi125MDP.txt";
			ocorrencia = 125000000-palindromeSize;
			break;
		case 3:
			filename = "Pi1BDP.txt";
			ocorrencia = 1000000000-palindromeSize;
			break;
		default:
			break;
	}
	
	if(testes==0){
		testes = ocorrencia;
	}
	
	system("cls");
	
	//Registrar o tempo da execucao
	clock_t time;
	time = clock();
	//--------------------------------//

	
	//Abrir o Arquivo txt-------------//
	FILE *fp = fopen(filename, "r");
	
	if(fp == NULL){
		printf("ERROR %s",*filename);
		return 0;
	}
	//---------------------------------//
	
	
	//cria a fila
	struct queue decimalpi;
	decimalpi.front = MAXQUEUE-1;
	decimalpi.rear = MAXQUEUE-1;
	//----------------
	
	
	
	char auxUnidade[1];
	for(i=0 ;  i < palindromeSize ; i++){
		fgets(auxUnidade, 2, fp);
		insert(&decimalpi, auxUnidade[0] - '0');
	}
	
	//Necessário remover a primeira ocorrencia 
	remover(&decimalpi);
	fgets(auxUnidade, 2, fp);
	insert(&decimalpi, auxUnidade[0] - '0');
	//----------------------------------------
	
	
	
	j=palindromeSize,i=1;
	printf("\n|Procurando...");
	while(ocorrencia && testes ){
		
		j++;
		if(isPalidrome(decimalpi, palindromeSize)){
			
			if(isPrime(convertToInt(decimalpi,palindromeSize))){
				
				printf(" \n|Posição:%d \t\t |palindromo Primo: |",j);
			    imprimirSemRemover(decimalpi, palindromeSize);
			    printf("  |Ocorrência: %d", i);
			    i++;
			    testes--;
			}
		}
		remover(&decimalpi);
		fgets(auxUnidade, 2, fp);
		insert(&decimalpi, auxUnidade[0] - '0');
		ocorrencia--;
		
		if(ocorrencia%10000000 == 0){
			printf("\n|Ocorrência: %d Procurando... ",j);
		}
	}


	//Imprimir tempo de execucao--------------------------------
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	printf("\n\nseconds%f", time_taken);
	//-------------------------------------------------
	
	fclose(fp);
	printf("\n\n%s", filename);
	
	return 0;
}


long long int convertToInt(struct queue decimaispi, int size){
	
	long long int number;
	int i;
	number = 0;
	
	for (i = 0; i < size; i++) {
	    number *= 10;
	    number += remover(&decimaispi);
	}
	
	return number;

}


int isPrime(long long int num)
{
    int k = 1, a = 0, b = 0;
    long sr;
    switch(num)
        {
        case 1: return 0;
        case 2: return 1;
        case 3: return 1;
        case 4: return 0;
        case 5: return 1;
        case 6: return 0;
        case 7: return 1;
    }
    if (num % 2 == 0){ 
		return 0; 
		}
    if (num % 3 == 0){
		return 0;
	}
    	
    sr = (int) sqrt(num);
    while (b < sr) {
        a = (6 * k) - 1;
        b = (6 * k) + 1;
        if (num % a == 0)
            return 0;
        if (num % b == 0)
            return 0;
        k += 1;
    }
    return 1;
}

void imprimirSemRemover(struct queue decimaispi, int sizeOfDecimal){
	int  i;
	for(i=0 ; i < sizeOfDecimal ; i++){
		printf("%d",remover(&decimaispi));
	}
}
					      //decimaispi é uma copia da fila, pode alterar sem nenhum problema;
int isPalidrome(struct queue decimaispi, int sizeOfDecimal){
	int i;
	int copia[sizeOfDecimal];
	
	for(i=0 ; i < sizeOfDecimal ; i++){
		copia[i] = remover(&decimaispi);
	}
	 

    for(i=0 ; i < sizeOfDecimal/2 ; i++){
		
		if(copia[i] != copia[sizeOfDecimal-1 - i] ){
			return 0;
		}

	}
	
	return 1;
}

