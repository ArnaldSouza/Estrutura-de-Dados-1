#include <stdio.h>
#include <stdlib.h>

typedef struct NodeFila NodeFilaPtr;

typedef struct NodeFila{
  int item;
  NodeFilaPtr *proximo;
  NodeFilaPtr *anterior;
} NodeFila;

typedef struct {
  NodeFilaPtr *inicio;
  NodeFilaPtr *fim;
  int tamanho;
} Fila;

void iniciaFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void enfileira(int item, Fila *fila){
    NodeFilaPtr *aux;
    aux = (NodeFilaPtr *) malloc(sizeof(NodeFila));
    aux->item = item;
    if(fila->tamanho == 0){
        fila->inicio = fila->fim = aux;
        aux->proximo = NULL;
    }
    else{
        aux->proximo = NULL;
        fila->fim->proximo = aux;
        fila->fim = aux;
    }
    fila->tamanho ++;
}

int desenfileira(Fila *fila){
    NodeFilaPtr *aux;
    aux = (NodeFilaPtr *) malloc(sizeof(NodeFila));
    aux->item = fila->inicio->item;
    int x;
    if(fila->tamanho != 0){
        aux = fila->inicio;
        x = fila->inicio->item;
        fila->inicio = fila->inicio->proximo;
        free(aux);
        fila->tamanho --;
        return x;
    }
    else
        return 0;
}

void imprimeFila(Fila *fila){
    NodeFilaPtr *aux;
    aux = (NodeFilaPtr *) malloc(sizeof(NodeFila));
    printf("{");
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
            printf("%i ", aux->item);
    }
    printf("}\n");
}

int estaVazia(Fila *fila){
    return(fila->tamanho == 0);
}

int tamanhoFila(Fila *fila){
    return(fila->tamanho);
}

int inicioFila(Fila *fila){
    return(fila->inicio->item);
}

int fimFila(Fila *fila){
    return(fila->fim->item);
}

int main(){
    Fila fila;
    iniciaFila(&fila);
    enfileira(10, &fila);
    enfileira(42, &fila);
    enfileira(-4, &fila);
    enfileira(25, &fila);
    enfileira(17, &fila);
    enfileira(3, &fila);
    desenfileira(&fila);
    inicioFila(&fila);
    fimFila(&fila);
    desenfileira(&fila);
    desenfileira(&fila);
    enfileira(desenfileira(&fila), &fila);
    enfileira(36, &fila);
    enfileira(67, &fila);
    desenfileira(&fila);
    fimFila(&fila);
    desenfileira(&fila);
    enfileira(90, &fila);

    imprimeFila(&fila);

return 0;
}
