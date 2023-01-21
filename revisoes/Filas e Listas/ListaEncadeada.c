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

void removerItem(struct list *lista, int posicao);


int main(){
	
	int caminho = 0;	
	int x;
	//Inicializar List
	struct list list1;
	list1.inicio = NULL;
	list1.tam = -1;
	
	while(caminho != 6){
		
		
		printf("\n\t|Escolha a opcao desejada");
		printf("\n\t|1 - Incluir item no inicio da lista");
		printf("\n\t|2 - Incluir item no Final da lista");
		printf("\n\t|3 - Remover uma posicao da lista");
		printf("\n\t|4 - Imprimir Lista");
		printf("\n\t|5 - Limpar a tela: sytem(\"cls\")");
		printf("\n\t|6 - Finalizar\n");
		printf("\t");
		scanf("%d",&caminho);
		//system("cls");
		
		switch(caminho)
		{
		case 1:
			printf("\n\t|Digite o valor a inserir na lista: ");
			scanf("%d",&x);
			inserirInicio(&list1, x);
			printf("\n\t|Item %d inserido no inicio da lista\n", x);
			
			break;
		case 2:
			printf("\n\t|Digite o valor a inserir na lista: ");
			scanf("%d",&x);
			inserirFinal(&list1, x);
			printf("\n\t|Item %d inserido no final da lista\n", x);
			
			break;
		case 3:
			
			if(list1.tam == -1){
				printf("\n\t|A lista esta vazia, insira algum item para seguir com esta operacao\n");
				
				break ;
			}
			printf("\n\t|Lista antes da alteracao");
			imprimirLista(&list1);
			printf("\n\t|Digite o indice que deseja remover: ");
			scanf("%d",&x);
			removerItem(&list1, x);
			printf("\n\t|Indice: %d Removido da lista\n", x);
			printf("\n\t|Lista apos a alteracao");
			imprimirLista(&list1);
			
			break;
		case 4:
			printf("\n\n");
			imprimirLista(&list1);
			break;
		case 5:
			system("cls");
			break;
		case 6:
			break;
		}
		
	}
	
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
}


void imprimirLista(struct list *lista){
	
	struct node *aux;
	aux = (*lista).inicio;
	printf("\t|Lista:");
	while( aux != NULL){
		printf(" %d", (*aux).info);
		aux = (*aux).proximo;
	}
	printf("\n\n");
}



void removerItem(struct list *lista, int posicao){
	
	if(lista->tam < posicao){
		printf("Overflow - Remoção: posicao outOfRange");
		exit(1);
	}
	
	int i;
	struct node *anterior;
	struct node *aux;
	struct node *seguinte;
	//aux = (struct node*)malloc(sizeof(struct node));
	aux = lista->inicio; //lista.inicio == lista[0]
	
	
	if(posicao == 0){
		lista->inicio = aux->proximo;
		lista->tam--;
		return;
	}
	
	for(i=0 ; i < posicao ; i++){
		anterior = aux;
		aux = aux->proximo;
	}
	
	if(posicao == lista->tam){
		anterior->proximo = NULL;
		lista->tam--;
	}else{
		seguinte = aux->proximo;
		anterior->proximo = seguinte ;
	}
}




















