#include <stdio.h>
#include <stdlib.h>


int multipleOfSix(int number);
int sumAlgorism(int number);
int isPrime(long num);
int nextPrime(int number);
void checkDuplicity(int array[2][100], int size);
void MudancaDeLivros (int *codigo, int *posicao);


//https://www.thehuxley.com/problem/3731?locale=pt_BR
 
int main(){
	
	int i,j,codigo,posicao;
	i=0;
	int livros[2][101];
	
	while(codigo != 0){
		
		scanf("%d %d", &codigo, &posicao);
		if(codigo != 0){
			MudancaDeLivros(&codigo,&posicao);
			livros[0][i]=codigo;
			livros[1][i]=posicao;
			checkDuplicity(livros,i);
			i++;
			
		}
	}
	
	checkDuplicity(livros,i);
	
	for(j=i-1 ; j >= 0 ; j--){
		
		printf("\n%d - %d", livros[0][j],livros[1][j]);
	}
	
	return 0;
}

void MudancaDeLivros (int *codigo, int *posicao){
	 
	 int i,aux,auxCodigo;
	 
	 auxCodigo = (*codigo + nextPrime(*codigo))/sumAlgorism(*codigo);
	 aux =  multipleOfSix(*codigo) - *posicao ; 
	 *codigo = auxCodigo;
	 *posicao = (aux < 0 ) ? aux*-1 : aux;
	 
	 
 }
void checkDuplicity(int array[2][100], int size){
	
	int i,j;
	
	for( i = 0 ; i <size ; i++){
		
		for( j = 0 ; j <size ; j++){
			
			if(array[1][size] == array[1][j]){
				
				array[1][size] = array[1][size] + 1;
			}
			
			if(array[0][size] == array[0][j]){
				array[0][size] = array[0][size] + 1;
			}
		}
	}
	
}
 
int nextPrime(int number){
	
	int aux ;
	number = number+1;
	while(1){
		
		if(isPrime(number) == 1){
			return number;
		}
		number++;
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

int sumAlgorism(int number){
	
	int i,m,sum;
	sum = 0;
	while(number>0)    
	{    
		m=number%10;    
		sum=sum+m;    
		number=number/10;    
	}   
	return sum;
}

int multipleOfSix(int number){
	
	int i,aux;
	aux = 0;
	for(i=6 ; i < number ; i=i+6){
		
		aux = aux + i;
		
	}
	return aux;
	
}

