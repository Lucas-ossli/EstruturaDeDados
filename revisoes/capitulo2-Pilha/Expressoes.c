#include <stdio.h>
//#include <stdbool.h>
#define STACKSIZE 100000

//https://www.thehuxley.com/problem/209?locale=pt_BR



//-----------------------Estrutura Pilha------------------------------//
struct stack {
	int top;
	char items[STACKSIZE];
} ;

empty(struct stack *ps);

pop(struct stack *ps);

push(struct stack *ps, char x);
//-----------------------Fim Estrutura Pilha------------------------------//

void verificar(char *expresao, struct stack *ps);

void clean(struct stack *ps);
int main(){
	
	struct stack pilha;
	pilha.top=-1;
	int t,i;
	char expresao[100000];
	
	scanf("%d", &t);
	
	
	for(i=0 ; i < t ; i++){
		
		scanf("%s",&expresao);
		verificar(&expresao, &pilha);
		clean(&pilha);
		printf("\n");
	}
	
	
	return 0;
	
}


void verificar(char *expresao,struct stack *ps){
	int i;
	i=0;
	for(i=0 ;expresao[i]!= NULL || expresao[i] != '\0'; i++){
		
		if( expresao[i] == '{' ||expresao[i] == '[' ||expresao[i] =='(' ){
			
			push(ps,expresao[i]);
			
		}else{
			if(empty(ps)){
				printf("N");
				return;
			}
			
			char aux = expresao[i];
			char aux2 = pop(ps);
			switch(aux)
			{
			case '}':
				if(aux2 != '{'){
					printf("N");
					return;
				}
				break;
			case ']':
				if(aux2 != '['){
					printf("N");
					return;
				}
			break;
			case ')':
				if(aux2 != '('){
					printf("N");
					return;
				}
				break;
			}
			
		}
		//printf("%c", expresao[i]);
	}
	
	if(ps->top == 0){
		printf("N");
		return;
	}
	printf("S");
	return;
}

void clean(struct stack *ps){
	
	while(!(empty(ps))){
		pop(ps);
	}
}



//-----------------------Estrutura Pilha------------------------------//
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

push(struct stack *ps, char x){
	if(ps->top == STACKSIZE-1){
		printf("Overflow");
	}else{
		ps->items[++(ps->top)] = x;// faz o incremento em ps.top antes de chamar ele;
	}
	return;
}