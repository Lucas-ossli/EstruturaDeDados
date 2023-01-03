#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.thehuxley.com/problem/954?locale=pt_BR

int main(){
	
	
	int n,i,j;
	scanf("%d", &n);
	int matricula[n],auxMatricula;
	float nota[n],media,auxNota;
	char aluno[n+1][100], auxAluno[100],auxAluno2[100], temp;
	//char ;
	//char temp;
	media=0;
	
	for(i=0 ; i<n ; i++){
		scanf("%d", &matricula[i]);
		scanf("%c",&temp); // temp statement to clear buffer
		scanf("%[^\n]",aluno[i+1]);
		scanf("%f", &nota[i]);
		
	}
	
	
	// Bubble Sort();
	for(i=0 ; i<n-1 ;i++){
		
		for(j=0 ; j < n-i-1 ; j++){
			
			if(nota[j] > nota[j+1]){
				
					auxMatricula = matricula[j];
					matricula[j] = matricula[j+1];
					matricula[j+1] = auxMatricula;
					
					auxNota  = nota[j];
					nota[j] = nota[j+1];
					nota[j+1] = auxNota;
					
					
					
					strcpy(&auxAluno,aluno[j+1]);
					//auxAluno[0] = aluno[j+1];
					strcpy(&auxAluno2, aluno[j+2]);
					strcpy(aluno[j+1],&auxAluno2);
					//aluno[j+1] = aluno[j+2];
					strcpy(aluno[j+2],&auxAluno);
					//aluno[j+2] = auxAluno[0];
					
			}else if(nota[j] == nota[j+1]){
				
				if(matricula[j] > matricula[j+1]){
					
					auxMatricula = matricula[j];
					matricula[j] = matricula[j+1];
					matricula[j+1] = auxMatricula;
					
					auxNota  = nota[j];
					nota[j] = nota[j+1];
					nota[j+1] = auxNota;
					
					
					
					strcpy(&auxAluno,aluno[j+1]);
					//auxAluno[0] = aluno[j+1];
					strcpy(&auxAluno2, aluno[j+2]);
					strcpy(aluno[j+1],&auxAluno2);
					//aluno[j+1] = aluno[j+2];
					strcpy(aluno[j+2],&auxAluno);
					//aluno[j+2] = auxAluno[0];
					
					
				}
				
			}
		}
	}
	//
	
	for(i = 0 ; i < n ; i++){
		media = media+nota[i];
	}
	
	media = media/n;
	
	for(i=0 ; i < n ; i++){
		if(nota[i]> media){
			printf("Matricula: %d Nome: %s Nota: %.1f\n", matricula[i], aluno[i+1] , nota[i]);
		}
	}
	printf("Media = %.2f", media);
	
	return 0;
}

