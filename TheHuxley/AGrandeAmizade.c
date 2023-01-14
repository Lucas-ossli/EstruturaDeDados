#include <stdio.h>

//https://www.thehuxley.com/problem/3000?locale=pt_BR


struct pessoas{
	char nome[100];
	int idade;
};

int main(){
	
	int n,i,k,idade;
	k=0;
	scanf("%d", &n);
	
	struct pessoas amigos[n];
	
	for(i=0 ; i<n ; i++){
		
		scanf("%s %d",&amigos[i].nome, &amigos[i].idade);
	}
	scanf("%d", &idade);
	
	for(i=0 ; i<n ; i++){
		if(idade == amigos[i].idade){
			printf("%s ",amigos[i].nome);
			k++;
		}
	}
	
	if(!(k)){
		printf("Eleven nao tem amigos com essa idade.");
	}
	
	
	return 0;
}