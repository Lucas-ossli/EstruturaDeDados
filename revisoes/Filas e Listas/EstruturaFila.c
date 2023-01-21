#include <stdio.h>
#define MAXQUEUE 100
//Fila Circular

//---------------------Estrutura Fila(Circular)-----------------------//
struct queue{
	int items[MAXQUEUE];
	int front,rear;
};

empty (struct queue *ps);
remove(struct queue *ps);
insert(struct queue *ps, int x);

//---------------------FIM Estrutura Fila-----------------------//

int main(){
	
	
	struct queue fila;
	fila.front = fila.rear = MAXQUEUE-1;
	

	return 0;
}


//---------------------Estrutura Fila(Circular)-----------------------//
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

insert(struct queue *ps, int x){
	
	if(ps->rear == MAXQUEUE-1){
		pq->rear = 0;
	}
	else{
		(pq->rear)++;
	}
	//Verifica ocorrência de estouro
	if(pq->rear == pq->front){
		printf("Overflow"){
			exit(1);
		}
	}
	pq->items[pq->rear] = x ;
	return;
}
       
       















