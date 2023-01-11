#include <stdio.h>
//#include <stdbool.h>
#define STACKSIZE 100

struct stack {
	int top;
	int items[STACKSIZE];
} ;

empty(struct stack *ps);

pop(struct stack *ps);

push(struct stack *ps, int x);

int main(){
	
	struct stack pilha;
	pilha.top=-1;
	int i;
	
	for(i=0 ; i < 15 ; i++){
		
		push(&pilha, 2*i);
	}
	
	printf("\nTOPO DA PILHA -----------");
	for(i=14 ; i > -1 ; i--){
		
		printf("\n[%d] : %d ", i, pop(&pilha));
	}
	printf("\nFUNDO DA PILHA -----------\n\n");
	
	return 0;
	
}

empty(struct stack *ps){
	
	return(ps->top == -1);
	
}

pop(struct stack *ps){
	
	if(empty(ps)){
		printf("stack underflow");
		exit(1);
	}
	return(ps->items[ps->top--]);//pega o valor top e dps tira -1;
	
}

push(struct stack *ps, int x){
	if(ps->top == STACKSIZE-1){
		printf("Overflow");
	}else{
		ps->items[++(ps->top)] = x;// faz o incremento em ps.top antes de chamar ele;
	}
	return;
}





