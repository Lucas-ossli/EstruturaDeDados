#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct node{
	int info;
	struct node *esquerda;
	struct node *direita;
}Node;

typedef struct {
	Node *raiz;
}ArvoreB;

Node* inserir(Node *raiz, int valor);
void imprimir(Node *raiz);
int tamanhoDaArvore(Node *raiz);
int buscar(Node *raiz, int chave);
Node* buscarReturnNode(Node *raiz, int chave);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int escolha,valor;
	
	Node *raizDaArvore = NULL;
	
	
	
	do{
		printf("\n");
		printf("\t _______________________________");
		printf("\n\t|1 - Inserir conteudo na Árvore\t|");
		printf("\n\t|2 - Imprimir Árvore           \t|");
		printf("\n\t|3 - Tamanho da Árvore         \t|");
		printf("\n\t|4 - Buscar Elemento           \t|");
		printf("\n\t|5 - Buscar Elemento e atribuir\t|");
		printf("\n\t|9 - Limpar a tela             \t|");
		printf("\n\t|                              \t|\n\t ");
		scanf("%d",&escolha);
		
		switch(escolha)
		{
		case 1:
			printf("\n\t|Escolha o valor que deseja inserir na Árvore: ");
			scanf("%d",&valor);
			raizDaArvore = inserir(raizDaArvore, valor);
			break;
		case 2:
			printf("\n\t|");
			imprimir(raizDaArvore);
			
			break;
		case 3:
			printf("\n\t|");
			printf("Tamanho da Árvore: %d ", tamanhoDaArvore(raizDaArvore));
			break;
		case 4:
			
			printf("\n\t|Escolha o valor que deseja Procurar: ");
			scanf("%d",&valor);
			if(buscar(raizDaArvore, valor)){
				printf("\n\t|");
				printf("Valor %d Encontrado dentro da Árvore ", valor);
			}else{
				printf("\n\t|");
				printf("Valor %d NÃO Encontrado dentro da Árvore ", valor);
			}
			
			break;
		case 5:
			printf("\n\t|Escolha o valor que deseja Procurar: ");
			scanf("%d",&valor);
		 	
		 	Node *aux;
			aux =  buscarReturnNode(raizDaArvore, valor);
			if(aux == NULL){
				printf("\n\t|Valor %d NÃO Encontrado dentro da Árvore", valor);    
				break;
			}
		    printf("\n\t|Valor %d Encontrado dentro da Árvore e atribuido na variável aux ", aux->info);    
			 
			break;
		case 9:
			system("cls");
			break;
		default:
			break;
		}
	}while(escolha);
	
	
	
}


void imprimir(Node *raiz){
	
	if(raiz != NULL){
		
		//Ordem crescente
		
		imprimir(raiz->esquerda);
		printf("%d ", raiz->info);
		imprimir(raiz->direita);
				
		//Ordem Drescente
		/*
		imprimir(raiz->direita);
		printf("%d ", raiz->info);
		imprimir(raiz->esquerda);
		*/
	}
}


//OBS da para retornar o Node encontrado, caso sua arvore tenha varios elementos 
int buscar(Node *raiz, int chave){
	
	if(raiz == NULL){
		return NULL;//irei tratar o return fora dessa função 
	}
	else{
		if(raiz->info == chave){
			return raiz->info;
		}
		else{
			
			if(chave < raiz->info){
				return buscar(raiz->esquerda, chave);
			}
			else{
				return buscar(raiz->direita, chave);
			}
			
		}
		
	}
	
}

Node* buscarReturnNode(Node *raiz, int chave){
	
	if(raiz == NULL){
		return NULL;//irei tratar o return fora dessa função 
	}
	else{
		if(raiz->info == chave){
			return raiz;
		}
		else{
			
			if(chave < raiz->info){
				return buscarReturnNode(raiz->esquerda, chave);
			}
			else{
				return buscarReturnNode(raiz->direita, chave);
			}
			
		}
		
	}
	
}

Node* inserir(Node *raiz, int valor){
	
	if(raiz == NULL){
		Node *novo = (Node *)malloc(sizeof(Node));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		return novo;
	}	
	else{
		
		if(valor < raiz->info){
			raiz->esquerda = inserir(raiz->esquerda, valor);
		}
		if(valor > raiz->info){
			raiz->direita = inserir(raiz->direita, valor);
		}
	}
	
	if(raiz->info == valor){
		printf("\n\t|Não é possivel inserir valores repetidos dentro de uma Árvore ");
	}
	
	return raiz;
}


int tamanhoDaArvore(Node *raiz){
	
	if(raiz == NULL){
		return 0;
	}else{
		return 1 + tamanhoDaArvore(raiz->esquerda) + tamanhoDaArvore(raiz->direita);
	}
	
}

