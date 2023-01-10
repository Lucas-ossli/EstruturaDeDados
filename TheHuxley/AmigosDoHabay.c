#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.thehuxley.com/problem/2834?locale=pt_BR

//O critério para ser o escolhido é a quantidade de letras do primeiro nome, 
//e em caso de empate, vence aquele que realizou primeiro a inscrição

int maiorNome(char array[][50][100],int size);
int partition(char array[][50][100], int inicio, int fim);
void quickSort(char array[][50][100], int inicio, int fim);
void converterParaArray(char array[][50][100], char *copia, int posicao);

int main(){
	
	char aluno[2][50][100];
	char fim[3] = {'F','I','M'};
	int i,j,x;
	x=0;
	
	for(i=0 ; i<100 ; i++){
		
			//Nome
			scanf("%s", &aluno[0][i]);	
			//aux = aluno[0][i];
			for(j=0 ; j<3 ; j++){
				
				if(fim[j] == aluno[0][i][j]){
					x++;
				}
				else{
					x=0;
				}
				
			}
			if(x == 3){
				
				break;
			}
			else{
				scanf("%s", &aluno[1][i]);	
			}
		
	}
	
	char *amigoDoHabay;
	amigoDoHabay= aluno[0][maiorNome(aluno,i)];
	
	
	quickSort(aluno,0,i-1);
	
	
	for(j=0 ; j<i ; j++){
		
		printf("\n\nnome:%s  Inscricao: %s ", aluno[0][j], aluno[1][j]);
		
	}
	
	printf("Amigo do Habay:\n%s", amigoDoHabay);
	
	return 0;
}




int maiorNome(char array[][50][100],int size){
	
	int i,j,k,letras,aux,posicao;
	j=0;
	aux=0;
	
	for(i=0 ; i<size ; i++, j=0){
		letras = 0;
		while(array[0][i][j] != '\0'){
			letras++;
			j++;
			
		}
		
		if(letras > aux ){
			
			for(k=0 ; array[1][i][k] != '\0' ; k++);
			
			if(k==3){
				posicao = i;
				aux=letras;
			}
		}
			
		
	}
	
	return posicao;
	
}




//////////////////////////////////////////

void quickSort(char array[][50][100], int inicio, int fim){
	
	int pivo;
	
	
	if(inicio < fim){
		
		pivo = partition(array,inicio,fim);
		quickSort(array, inicio , pivo-1);
		quickSort(array, pivo+1, fim);
		
	}
	
	return;
	
	
}


int partition(char array[][50][100], int inicio, int fim){
	
	
	char *pivo = array[0][fim];
	int i = inicio;
	int j,aux;
	char *letraAux;
	char *letraAux2;
	letraAux2 = (char *)malloc(100*sizeof(int));
	
	for(j= inicio ; j < fim ; j++){
		
		
		if(array[0][j] <= *pivo){
			
			//TO DO - FUNÇÃO CONVERT TO ARRAY
			letraAux = array[0][j];
			//array[0][j] = array[0][i];
			
			
			
			letraAux2 = array[0][i];
			array[0][j] = *letraAux;
			
			
			
			
			
			array[0][i] = *letraAux ;
			i++;
			
		}
		
		
	}
	
	*letraAux = array[0][i];
	array[0][i] = array[0][fim];
	array[0][fim] = *letraAux;
	
	
	
	
	
	
	
	
	return i;
}



//TO DO - fazer a copia completa de uma string para uma string simples
void converterParaArray(char array[][50][100], char *copia, int posicao){
	
	
	
}



