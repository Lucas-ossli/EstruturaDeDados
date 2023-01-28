#include <stdio.h>
#define MAXQUEUE 100
//Fila Circular

//---------------------Estrutura Fila(Circular)-----------------------//
struct queue{
	int items[MAXQUEUE];
	int front,rear;
};

int empty(struct queue *ps);
int remover(struct queue *ps);
void insert(struct queue *ps, int x);

//---------------------FIM Estrutura Fila-----------------------//



//--- HOW TO START THE QUEUE	
//	struct queue fila;
//	fila.front = MAXQUEUE-1;
//	fila.rear = MAXQUEUE-1;
//--- HOW TO START THE QUEUE	


//---------------------Estrutura Fila(Circular)-----------------------//
int empty (struct queue *ps){
	if(ps->front == ps->rear){
		return 1;
	}
	
	return 0;
}

int remover(struct queue *ps){
	
	if(empty(ps)){
		printf("UnderFlow na Fila");
		exit(1);
	}
	
	if(ps->front == MAXQUEUE-1){
		ps->front = 0;
	}
	else{
		(ps->front)++;
	}
	return (ps->items[ps->front]);
	
}

void insert(struct queue *ps, int x){
	
	if(ps->rear == MAXQUEUE-1){
		ps->rear = 0;
	}
	else{
		(ps->rear)++;
	}
	//Verifica ocorr�ncia de estouro
	if(ps->rear == ps->front){
		printf("Overflow");
		exit(1);
		
	}
	ps->items[ps->rear] = x ;
	
}
       
       















