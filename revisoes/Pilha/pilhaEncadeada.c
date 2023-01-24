#include <stdio.h>


struct stack{
    struct stack *next;
    int info;

}

empty(struct stack pilha);
push(struct stack *pilha, int x);
pop(struct stack *pilha);
info(struct stack pilha);
next(struct stack pilha);


//TO DO
getnode();
freenode();

int main(){

    return 0;
}

push(struct stack *pilha, int x){

    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    p->info = x;
    p->next = pilha;
    pilha = p;
}



pop(struct stack *pilha){

    int x;
    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    if(pilha->next == NULL){
        printf("UnderFlow na pilha");
        exit(1);
    }else{
        p = pilha;
        pilha = p->next;

        x = p->info;
        free(p);
        return x;
    }
}

info(struct stack pilha){
    return pilha.info;
}

next(struct stack pilha){
    return pilha.next;
}

