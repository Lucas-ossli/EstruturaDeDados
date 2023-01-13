#include <stdio.h>
#define MAXQUEUE 100
//Fila Circular

//---------------------Estrutura Fila-----------------------//
struct queue{
	int items[MAXQUEUE];
	int front,rear;
};

empty (struct queue *ps);

remove(struct queue *ps);

//---------------------FIM Estrutura Fila-----------------------//

int main(){
	
	
	struct queue fila;
	fila.front = fila.rear = MAXQUEUE-1;
	

	return 0;
}

//TO DO PAG 214 - PDF:234
//---------------------Estrutura Fila-----------------------//
empty (struct queue *ps){
	return((ps->front == ps->rear));
}

remove(struct queue *ps){
	
	if(empty(ps)){
		printf("UnderFlow na Fila");
		exit(1);
	}
	
	if(pq->front == MAXQUEUE-1){
		ps->front = 0;
	}
	else{
		(ps->front)++;
	}
	return (ps->items[pq->front]);
	
}