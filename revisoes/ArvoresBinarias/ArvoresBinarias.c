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

void inserirEsquerda(Node *node, int valor);
void inserirDireita(Node *node, int valor);
void inserir(ArvoreB *arv, int valor);
int tamanhoDaArvore(Node *raiz);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int escolha,valor;
	
	ArvoreB arvore;
	arvore.raiz = NULL;
	
	
	
	//inserir(&arvore,50);
	//inserir(&arvore,60);
	//inserir(&arvore,55);
	//inserir(&arvore,70);
	//inserir(&arvore,40);
	//inserir(&arvore,30);
	//inserir(&arvore,35);
	
	//imprimir(arvore.raiz);
	
	do{
		printf("\n");
		printf("\t _______________________________");
		printf("\n\t|1 - Inserir conteudo na Árvore\t|");
		printf("\n\t|2 - Imprimir Árvore           \t|");
		printf("\n\t|3 - Tamanho da Árvore         \t|");
		printf("\n\t|9 - Limpar a tela             \t|");
		printf("\n\t|                              \t|\n\t ");
		scanf("%d",&escolha);
		
		switch(escolha)
		{
		case 1:
			printf("\n\t|Escolha o valor que deseja inserir na Árvore: ");
			scanf("%d",&valor);
			inserir(&arvore, valor);
			break;
		case 2:
			printf("\n\t|");
			imprimir(arvore.raiz);
			break;
		case 3:
			printf("\n\t|");
			printf("Tamanho Da Árvore: %d ",tamanhoDaArvore(arvore.raiz));
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


void inserirEsquerda(Node *node, int valor){
	
	if(node->esquerda == NULL){
		Node *novo = (Node *)malloc(sizeof(Node));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		node->esquerda = novo;
		return;
	}else{
		//eu verifico o proximo node pois quando essa funcao
		//for chamada ele ja verificou o node ATUAL anteriormente
		if(node->esquerda->info > valor){
			inserirEsquerda(node->esquerda, valor);
			return;
		}
		if(node->esquerda->info < valor){
			inserirDireita(node->esquerda, valor);
			return;
		}
	}
	
	printf("\n\t|Não é possivel inserir valores repetidos dentro de uma Árvore ");

}

void inserirDireita(Node *node, int valor){
	
	if(node->direita == NULL){
		Node *novo = (Node*)malloc(sizeof(Node));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		
		node->direita = novo;
		
		return;
	}else{
		if(node->direita->info < valor){
			inserirDireita(node->direita, valor);
			return;
		}
		if(node->direita->info > valor){
			inserirEsquerda(node->direita, valor);
			return;	
		}
	}
	printf("\n\t|Não é possivel inserir valores repetidos dentro de uma Árvore ");

}

void inserir(ArvoreB *arv, int valor){
	
	if(arv->raiz == NULL){
		Node *novo = (Node *)malloc(sizeof(Node));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
		
		return;
	}
	else{
		
		if(valor < arv->raiz->info){
			inserirEsquerda(arv->raiz, valor);
			return;
		}
		if(valor > arv->raiz->info){
			inserirDireita(arv->raiz, valor);
			return;
		}
		
	}
		
	printf("\n\t|Não é possivel inserir valores repetidos dentro de uma Árvore ");

}

int tamanhoDaArvore(Node *raiz){
	
	if(raiz == NULL){
		return 0;
	}else{
		return 1 + tamanhoDaArvore(raiz->esquerda) + tamanhoDaArvore(raiz->direita);
	}
	
}