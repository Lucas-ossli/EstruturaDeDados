#include <stdio.h>


struct stack{
    int *next;
    int info;

}

empty(struct stack pilha);
push(struct stack pilha, int x);
pop(struct stack pilha);
info(struct stack pilha);
next(struct stack pilha);


//TO DO
getnode();
freenode();

int main(){

    return 0;
}

push(struct stack pilha, int x){

    int *p = getnode();
    info(p) = x;
    next(p) = pilha;
    pilha = p;
}

empty(struct stack pilha){
    return (next(pilha) == NULL )
}

pop(struct stack pilha){

    int x;
    int *p = getnode(); 
    if(empty()){
        printf("UnderFlow na pilha");
        exit(1);
    }else{
        p = pilha;
        pilha = next(p);

        x = info(p);
        freenode(p);
        return x;
    }
}

info(struct stack pilha){
    return pilha.info;
}

next(struct stack pilha){
    return pilha.next;
}

//TO DO  -- sera ensinado na Seção 9.1 


getnode(){


}

freenode(){


}

