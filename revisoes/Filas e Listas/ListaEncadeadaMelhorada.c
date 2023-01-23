#include <stdio.h>
#include <locale.h>
struct node{
    int info;
	struct node* proximo;
};

void inserirInicio(struct node **lista, int valor);
void inserirFinal(struct node **lista, int valor);
void inserirOdenadoCrescente(struct node **lista,int valor);
void inserirNoMeio(struct node **lista, int valor, int anterior);
void removerIndice(struct node **lista, int indice);
void imprimir(struct node *lista);
struct node* buscar(struct node **lista, int valor);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int caminho = 1;	
	int x,anterior;
	//Inicializar List
	struct node *list = NULL;
	struct node *busca;
	
	
	while(caminho){
		
		printf("\n\t|Escolha a opção desejada");
		printf("\n\t|1 - Incluir item no início da lista");
		printf("\n\t|2 - Incluir item no Final da lista");
		printf("\n\t|3 - incluir item após uma referência");
		printf("\n\t|4 - Incluir item Ordenado Crescente");
		printf("\n\t|5 - Imprimir Lista");
		printf("\n\t|6 - Remover Índice da lista");
		printf("\n\t|7 - Buscar elemento na lista");
		printf("\n\t|8 - Limpar a tela system(\"cls\")");
		printf("\n\t|");
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
			printf("\n\t|Digite o valor de referência( ira inserir após ): ");
			scanf("%d",&anterior);
			inserirNoMeio(&list, x, anterior);
		
			break;
		case 4:
			printf("\n\t|Digite o valor: ");
			scanf("%d",&x);
			inserirOdenadoCrescente(&list, x);
			break;
		case 5:
			imprimir(list);
			break;
		case 6:
			printf("\n\t|Lista Antes da alteração: ");
			imprimir(list);
			printf("\n\t|Digite o Índice que deseja remover: ");
			scanf("%d",&x);
			removerIndice(&list, x);
			printf("\n\t|Lista Apos a alteração: ");
			imprimir(list);
			break;
		case 7:
			printf("\n\t|Digite o valor a ser procurado: ");
			scanf("%d",&x);
			busca = buscar(&list, x);
			if(busca){
				printf("\n\t|Elemento %d encontrado\n\n ", busca->info);
			}else{
				printf("\n\t|Elemento Não encontrado\n\n");
			}
			break;
			case 8:
			system("cls");
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

void inserirOdenadoCrescente(struct node **lista,int valor){
	
	struct node *novo = (struct node*)malloc(sizeof(struct node));
	struct node *aux = (struct node*)malloc(sizeof(struct node));
	
	novo->info = valor;
	//a lista esta vazia ?
	if(*lista == NULL){
		novo->proximo=NULL;
		*lista = novo;
	}else if(novo->info < (*lista)->info){
		novo->proximo = *lista;
		*lista = novo;
	}else{
		aux = *lista;
		
		while(aux->proximo && aux->proximo->info < novo->info){
			aux = aux->proximo ;
		}
		
		novo->proximo = aux->proximo;
		aux->proximo = novo;
		
	}
	
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


void removerIndice(struct node **lista, int indice){
	struct node *aux = (struct node*)malloc(sizeof(struct node));
	int i;
	aux = *lista;
	
	//a lista esta vázia?
	if(aux == NULL){
		printf("\n\t|A Lista esta vazia");
	}else if(!indice){
		*lista = (*lista)->proximo;
	}
	else{
		//0
		//1 2 3 4
		// se o indice for maior que o tamanho da lista
		for(i=0 ; i<indice-1 && aux->proximo->proximo != NULL ; i++){
			aux = aux->proximo;
		}
		
		//caso o indice seja maior que o limite da lista
		//e tbm caso o indice seja o ultimo da lista;
		if(aux->proximo->proximo == NULL){
			aux->proximo = NULL;
		}else{
			aux->proximo = aux->proximo->proximo;
		}
		
	}
	
}

struct node* buscar(struct node **lista, int valor){
	
	struct node *no = NULL;
	struct node *aux ;
	
	aux = *lista;
	
	while(aux && aux->info != valor){
		aux = aux->proximo;
	}
	if(aux){
		no = aux;
	}
	
	
	
	return no;
}

void imprimir(struct node *lista){
	
	printf("\n");
	while(lista){
		printf("\t|%d", lista->info);
		lista = lista->proximo;
	}
	printf("\n\n");
}










