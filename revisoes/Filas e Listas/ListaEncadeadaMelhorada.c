#include <stdio.h>



struct node{
    int info;
	struct node* proximo;	
	
};

void inserirInicio(struct node **lista, int valor);
void inserirFinal(struct node **lista, int valor);
void inserirNoMeio(struct node **lista, int valor, int anterior);
void imprimir(struct node *lista);

int main(){
	
	int caminho = 0;	
	int x,anterior;
	//Inicializar List
	struct node *list = NULL;
	
	
	while(caminho != 6){
		
		
		printf("\n\t|Escolha a opcao desejada");
		printf("\n\t|1 - Incluir item no inicio da lista");
		printf("\n\t|2 - Incluir item no Final da lista");
		printf("\n\t|3 - incluir item apos uma referencia");
		printf("\n\t|4 - Imprimir Lista");
		printf("\n\t|5 - Limpar a tela system(\"cls\")");
		printf("\t");
		scanf("%d",&caminho);
		//system("cls");
		
		switch(caminho)
		{
		case 1:
			printf("\n\t|Digite o valor: ");
			scanf("%d",&x);
			inserirInicio(&list, x);
			break;
		case 2:
			printf("\n\t|Digite o valor: ");
			scanf("%d",&x);
			inserirFinal(&list, x);
			break;
		case 3:
			printf("\n\t|Digite o valor a ser inserido: ");
			scanf("%d",&x);
			printf("\n\t|Digite o valor de referencia( ira inserir apos ): ");
			scanf("%d",&anterior);
			inserirNoMeio(&list, x, anterior);
		
			break;
		case 4:
			imprimir(list);
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


void inserirInicio(struct node **lista, int valor){
	
	//cria o node novo
	struct node *novo = (struct node*)malloc(sizeof(struct node));
	(*novo).info = valor;
	(*novo).proximo = *lista;
	*lista = novo;
}

void inserirFinal(struct node **lista, int valor){
	
	struct node *novo = malloc(sizeof(struct node));
	struct node *aux = malloc(sizeof(struct node));
	
	novo->info = valor;
	novo->proximo = NULL;
	
	//é o primeiro
	if(*lista == NULL){
		*lista = novo;
	}else{
		aux = *lista;
		while(aux->proximo){
			aux = aux->proximo;
		}
			
		aux->proximo = novo;
	}
	
}

void inserirNoMeio(struct node **lista, int valor, int anterior){
	
	struct node *novo = (struct node*)malloc(sizeof(struct node));
	struct node *aux = (struct node*)malloc(sizeof(struct node));
	
	novo->info = valor;
	
	//é o primeiro ?
	if(*lista == NULL){
		novo->proximo = NULL;
		*lista = novo;
	}else{
		
		aux = *lista;
		
		//percorre a lista até achar o numero anterior, 
		//e também verifica se chegou no final,
		//pois corre o risco de o valor anterior não existir na lista
		while(aux->info != anterior && aux->proximo){
			aux = aux->proximo;
		}
		novo->proximo = aux->proximo;
		aux->proximo = novo;
		
	}
	
}


void imprimir(struct node *lista){
	
	printf("\n");
	while(lista){
		printf("\t|%d", lista->info);
		lista = lista->proximo;
	}
	printf("\n\n");
}










