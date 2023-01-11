#include <stdio.h>

#define STACKSIZE 100

struct stack {
	int top;
	int items[STACKSIZE];
} ;



int main(){
	
	
	stack pilha;
	int i;
	for(i=0 ; i < 15 ; i++){
		
		push(pilha, i*i);
	}
	
	for(i=0 ; i < 15 ; i++){
		
		printf("\n[%d] : %d ",pilha.pop());
	}
	
	
	return 0;
	
}
//pag 101 - 2p

//TO DO
void push(stack *pilha, int n){
	
}

//TO DO
void pop(stack *pilha){
	
	
}