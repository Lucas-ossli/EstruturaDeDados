#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int isPalidrome(int decimalpi, int sizeOfDecimal);
void rearrange(int *array, int size);
int isPrime(long num);
int convertToInt(int array[], int size);
int convertToArray(int array[],int number, int size);

int main(){
	
	int palindromeSize,tamanho,i,j,index,decimalPi;
	char *filename = "Pi1MDP.txt" ;
	char *charNumber;
	int MAX_LENGTH;
	index=1;
	
	printf("\nInput Palindrome size ");
	scanf("%d",&palindromeSize);
	while(palindromeSize > 9){
		printf("\n\nMax Palindrome size: 9,  Try again");
		scanf("%d",&palindromeSize);
	}
	MAX_LENGTH = palindromeSize+1; 
	int number[MAX_LENGTH-1];
	int numero; //APAGAR
	char buffer[MAX_LENGTH];
	//quantidade de caractere n-1;
	FILE *fp = fopen(filename, "r");
	
	if(fp == NULL){
		printf("ERROR");
		return 1;
	}
	
	tamanho = 1000000%(MAX_LENGTH-1);
	tamanho = tamanho + (1000000/(MAX_LENGTH-1));
	
	clock_t time;
	time = clock();
	
	fgets(buffer, MAX_LENGTH, fp);
	charNumber = buffer;
	
	numero = atoi(charNumber);
	
	convertToArray(number ,numero, MAX_LENGTH-1);
	
	
	printf("\n\n%d ", number[1]);
	
	//To Do Converter o numero para array;
	if(isPalidrome(number, MAX_LENGTH-1)){
		if(isPrime(number)){
			printf("\n\nFirst ocorrency of a Palindrome and Prime:%d Index:%d",number, index );
			return 0;
		}
	}
	
	
	for(i=1 ; i< tamanho ; i++){
		
			
			for(j=0 ; j< MAX_LENGTH-1 ; j++ ){
				
				rearrange( &number, MAX_LENGTH-1);
				number[MAX_LENGTH-2] = atoi(buffer[j]);
				
				
				//TO DO Convert the array to an integer;
				decimalPi = convertToInt(number, MAX_LENGTH-1);
			//	if(isPalidrome(number, MAX_LENGTH-1))
			//	{
					if(isPrime(decimalPi))
					{
						printf("\n\nFirst ocorrency of a Palindrome and Prime:%d Index:%d",number, index );
						return 0;
					}
	  	  	   // }
			}	
			
			fgets(buffer, MAX_LENGTH, fp);
			printf("Numero:%s | Ocorrencia:%d\n\n" , buffer,i);
			
	}
	
	
	
	//time take
	time = clock() - time;
	double time_taken = ((double)time)/CLOCKS_PER_SEC;
	//time
	
	fclose(fp);
	
	printf("\n\nseconds%f", time_taken);
	printf("\n\n%s", filename);
	
	
	
	
	
	return 0;
}


int convertToInt(int array[], int size){
	
	int number,i;
	number = 0;
	
	for (i = 0; i < size; i++) {
	    number *= 10;
	    number += array[i];
	}
	
	return number;

}


int isPrime(long num)
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

int isPalidrome(int decimalpi, int sizeOfDecimal){
	int i;
	for(i = decimalpi ; i>0 ; i--);
//	char *copiaReversa = string[palindromo].
	return 0;
}

void rearrange(int *array, int size){
	int i;
	for (i=1 ; i< size ; i++){
		array[i-1]  = array[i];
	}
}

int convertToArray(int array[], int number, int size){
	
	int digits[size];
	int i;
	for ( i = size; i >= 0; i--)
	{
	    digits[i] = number % 10;
	    number = number / 10;
	}
	
	*array =  digits;
	
}