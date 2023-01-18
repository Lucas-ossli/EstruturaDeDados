#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.thehuxley.com/problem/2834?locale=pt_BR


struct pessoa{
	char nome[50];
	char confirmacao[3];
};


int maiorNome(struct pessoa *aluno ,int size);
void selectionSort(struct pessoa *aluno, int size);


int main(){
	
	struct pessoa aluno[100];
	//struct pessoa smaller[100];
	struct pessoa amigoDoHabay;
	//char aluno[2][50][100];
	char fim[3] = {'F','I','M'};
	
	int i,j,x;
	x=0;
	
	for(i=0 ; i<100 ; i++){
		
			scanf("%s", &aluno[i].nome);
			for(j=0 ; j<3 ; j++){
				
				if(fim[j] == aluno[i].nome[j]){
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
				scanf("%s", &aluno[i].confirmacao);	
				
			}
	
	}
	
	
	struct pessoa amigoHabay ;
	amigoHabay = aluno[maiorNome(&aluno,i)];
	
	selectionSort(&aluno,i);
	
	for(j=0 ; j<i ; j++){
		
		//if(aluno[j].confirmacao[0] == 'Y'){
			printf("\nnome:%s ", aluno[j].nome);
		//}
	}
	
	printf("\nAmigo do Habay:\n%s", amigoHabay.nome);
	
	return 0;
}




int maiorNome(struct pessoa *aluno ,int size){
	
	int i,j,k,letras,aux,posicao;
	j=0;
	aux=0;
	char yes[3] = {'Y','E','S'};
	
	for(i=0 ; i<size ; i++, j=0){
		
		letras = 0;
		while(aluno[i].nome[j] != '\0'){
			letras++;
			j++;
		}
		
		if(letras > aux ){
			
			for(k=0 ; aluno[i].confirmacao[k] == yes[k] ; k++);
			
			if(k==3){
				posicao = i;
				aux=letras;
			}
			
		}
			
		
	}
	
	return posicao;
	
}

//TO DO - TENHO QUE FAZER UM OUTRO VETOR ORDENADO
void selectionSort(struct pessoa *aluno, int size){
	
	int  i_smaller, place,i,j;
	struct pessoa smaller;
	place = 0;
	
	for(i=1 ; i < size ; i++){
		
		memcpy(&smaller, &aluno[place], sizeof(struct pessoa));
		/
		i_smaller = place;
		
		for(j=place+1 ; j <size ; j++){
			
			
			if(aluno[j].nome < smaller.nome){
				
				memcpy(&smaller, &aluno[j], sizeof(struct pessoa));
				i_smaller = j;
				
			}
			
		}
		
		memcpy(&aluno[i_smaller], &aluno[place], sizeof(struct pessoa));
			
	    //aluno[i_smaller].nome = aluno[place].nome;
	    //aluno[i_smaller].confirmacao = aluno[place].confirmacao;
	   
		memcpy(&aluno[place], &smaller, sizeof(struct pessoa));
		// aluno[place].nome = nome;
		// aluno[place].confirmacao = confirmacao;
	   
		   
		place++;
	}

}





