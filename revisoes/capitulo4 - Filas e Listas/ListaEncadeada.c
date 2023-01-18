#include <stdio.h>

//criar node

struct node{
	int info;
	struct node *proximo;
};

struct list{
	struct node *inicio;
	int tam;
};
// start with size = 0;

void imprimirLista(struct list *lista);

void inserirInicio(struct list *lista, int valor);

void inserirFinal(struct list *lista, int valor);


int main(){
	
	
	struct list list1;
	
	list1.inicio = NULL;
	list1.tam = 0;
	
	inserirInicio(&list1, 10);
	inserirInicio(&list1, 20);
	inserirInicio(&list1, 30);
	
	inserirFinal(&list1, 90);
	inserirFinal(&list1, 91);
	
	imprimirLista(&list1);
	
	return 0;
}



void inserirInicio(struct list *lista, int valor){
	struct node *novo = (struct node*)malloc(sizeof(struct node));
	(*novo).info = valor;
	(*novo).proximo = (*lista).inicio;
	
	(*lista).inicio = novo;
	(*lista).tam++;
}


void inserirFinal(struct list *lista, int valor){
	struct node *novo =(struct node*)malloc(sizeof(struct node));
	struct node *aux = (struct node*)malloc(sizeof(struct node));
	
	novo->info = valor;
	novo->proximo = NULL;
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
	}else{
		aux = lista->inicio;
		
		while( aux->proximo != NULL){
			aux = aux->proximo;
		}
		
		aux->proximo = novo;
		
	}
	lista->tam++;
	//free(aux);
}


void imprimirLista(struct list *lista){
	
	struct node *aux;
	aux = (*lista).inicio;
	while( aux != NULL){
		
		printf("%d ", (*aux).info);
		aux = (*aux).proximo;
	}
	
}






















