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
	
	struct pessoa *aluno;
	aluno = (struct pessoa *)malloc(100*sizeof(struct pessoa));
	char *fim = "FIM";
	char palavra[50];
	int i,j,x;
	x=0;
	char * token;
	
	
	for(i=0 ; i<100 && x != 1 ; i++){
		
      gets(palavra);
      token = strtok(palavra," ");
      
      if( strcmp( token, fim ) == 0 ){
		  x=1;
	  }
	  else{
		  strcpy( aluno[i].nome, token);
      	  token = strtok(NULL, " ");
      	  strcpy( aluno[i].confirmacao, token);
	  }
   }
	
	
	
	struct pessoa amigoHabay ;
	amigoHabay = aluno[maiorNome(aluno,i)];
	
	selectionSort(aluno,i);
	
	
	for(j=0 ; j<i ; j++){
		
		if(aluno[j].confirmacao[0] == 'Y'){
			if(strcmp(aluno[j].nome, aluno[j+1].nome) == 0  /*aluno[j].nome == aluno[j+1].nome*/){
				
				continue;
			}else{
				printf("\n%s", aluno[j].nome);
			}
		}
	}
	
	for(j=0 ; j<i ; j++){
		
		if(aluno[j].confirmacao[0] == 'N'){
			printf("\n%s", aluno[j].nome);
		}
		
	}
	
	printf("\n\nAmigo do Habay:\n%s", amigoHabay.nome);
	
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

void selectionSort(struct pessoa *aluno, int size){
	
	int  i_smaller, place,i,j;
	struct pessoa *smaller;
	smaller = (struct pessoa*)malloc(sizeof(struct pessoa));
	
	place = 0;
	
	for(i=1 ; i < size ; i++){
		
		(*smaller) =  aluno[place];
		i_smaller = place;
		
		for(j=place+1 ; j <size ; j++ ){
			if( strcmp(aluno[j].nome, smaller[0].nome) == -1 || strcmp(aluno[j].nome, smaller[0].nome) == 0){
				*smaller = aluno[j];
				i_smaller = j;
			}
		}
	    aluno[i_smaller] = aluno[place];
		aluno[place]= *smaller;
		
		place++;
	}
}