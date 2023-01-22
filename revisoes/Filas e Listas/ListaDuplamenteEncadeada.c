#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
	struct node *prior;
    struct node *next;
};

createList(struct node* lista,int x);
insertItem(struct node *lista, int valor);
imprimir(struct node*lista);

int main(){

    struct node* lista;
    createList(lista,10);

    insertItem(lista, 10);
    insertItem(lista, 20);
    insertItem(lista, 30);
    insertItem(lista, 15);

    imprimir(lista);

    return 0;

}

createList(struct node* lista,int x){
    lista->info = x;
    lista->next = NULL;
    lista->prior = NULL;
    
}

//Ordem Crescente
insertItem(struct node *lista, int valor){

    struct node* novo,p,old;
    novo = (struct node*)malloc(sizeof(struct node));
    novo->info = valor;

    if( !(lista->next)){
        lista->next = novo;
        novo->prior = lista;
        novo->next = NULL;
        return;
    }

    p = lista;

    while(p){
                
        if(p->info < valor){
            old = p;
            p = p->next
        }
        else{
            old->next = novo;
            novo->prior = old;
            novo->next = p;
            return;
        }

    }


}


imprimir(struct node*lista){

    struct node aux;
    aux = *lista;

    printf("\n\n");
    while(aux){
        printf("%d ",aux.info);
        aux = aux->next;
    }
}