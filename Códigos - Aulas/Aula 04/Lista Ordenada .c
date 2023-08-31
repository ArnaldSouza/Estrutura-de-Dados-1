//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//---------------------------------------------
// PtrNoLista -> NoLista*
typedef struct NoLista* PtrNoLista;

typedef struct NoLista{
  int chave; //- chave (int)
  PtrNoLista proximo; //- proximo (NoLista*)
} NoLista;

// Lista Ordenada
typedef struct{
  PtrNoLista inicio; // - inicio (NoLista)
  int qtdeElementos; // - contador (opcional) // eficiente
} ListaOrdenada;

//---------------------------------------------
// Operações:
//---------------------------------------------

// Iniciar
void iniciaListaOrdenada(ListaOrdenada *l){
  //inicio
  l->inicio = NULL;
  //contador
  l->qtdeElementos = 0;
}

// EstaVazia
bool estaVaziaListaOrdenada (ListaOrdenada *l){
  // return(l->qtdeElementos == 0)
  return(l->inicio == NULL);
}

// Tamanho
int tamanhoListaOrdenada(ListaOrdenada *l){
  return(l->qtdeElementos);
}

//---------------------------------------------
// Inserir = X casos (situações)
void insereListaOrdenada(ListaOrdenada *l, int x){

  //Criar novo no (alocar memoria)
  PtrNoLista novo =  malloc(sizeof(NoLista));
  //copiar valor para novo no
  novo->chave = x;

  // *** Sit 1: primeira inserção ou se X é menor que o primero
  if(estaVaziaListaOrdenada(l) || x < l->inicio->chave){
    // L->inicio ->NULL || não ser nulo
    novo->proximo = l->inicio;
    // inicio apontar p novo
    l->inicio = novo;
  }else{
    //*** Sit2: todas as outras situações

    PtrNoLista aux = l->inicio;
    // Aux (percorrer a lista) -> ponto de inserção
    // (parar uma posição antes)
    while(aux->proximo != NULL && x > aux->proximo->chave){
      aux = aux->proximo;
    }

    //depois do while: ponto de inserção
    //novo ->entre (aux,?) -> (aux, novo,...)
    // proximo do novo recebe o proximo do aux (percorre)
    novo->proximo = aux->proximo;
    // proximo do auxiliar recebe o novo
    aux->proximo = novo;
  }
  l->qtdeElementos++;
}

// -----------------------------------------------
// ImprimirLista
// -----------------------------------------------
void imprimirListaOrdenada(ListaOrdenada *l) {
  printf("Lista = { ");
  PtrNoLista percorre;
  for(percorre = l->inicio; percorre!=NULL; percorre = percorre->proximo) {
    printf("%d ", percorre->chave);
  }
  printf("} \n");
}

// -----------------------------------------------
// Remover
// -----------------------------------------------

//4 situações de remoção:
//remover(lista, número)
// Lista = {0 2 2 3 5 50}

bool removeListaOrdenada(ListaOrdenada *lista, int numero) {
  //numero - não existe na Lista
  //retornar (warning + false)

  //c1 - a lista é vazia ? -> não consigo remover nada
  //c2 - elemento < primeiro elemento na lista (não existe!)
  if(estaVaziaListaOrdenada(lista) || numero < lista->inicio->chave){
    printf("Warning: não posso remover elementos de uma lista vazia, ou o elemento ser removido é menor do que o elemento inicial!\n");
  return false;
  }

  //c3 - elemento for o primeiro (filas)
    //se o elemento for o primeiro da lista
    if(numero == lista->inicio->chave){
      //auxiliar recebe inicio
      PtrNoLista aux = lista->inicio;
      //inicio aponta para o inicio proximo
      lista->inicio = lista->inicio->proximo;
      //libera a memoria
      free(aux);
      //decrementar a quantidade de elementos da Lista
      lista->qtdeElementos--;
      return true;
    }

    //c4 - se não for o primeiro elemento (intermediario/ultimo)
      //percorrer a lista e verificar se ele existe (percorre|aux), parar uma posição antes
      //encontrar elemento (remover, true)
      //não encontrar o elemento (não remove, false)

      PtrNoLista percorre;
      percorre = lista -> inicio;

    //percorre-> proximo->chave = numero
    //enquanto o proximo do percorre for diferente e nulo E
    //a chave do proximo percorre < numero
      while(percorre-> proximo != NULL && numero > percorre->proximo->chave){
        percorre = percorre->proximo;
      }

    //premissa: ponto de remoção de elemento (numero)
    if(percorre-> proximo == NULL || numero < percorre->proximo->chave ){
      printf("Warning: elemento a ser removido não existe na lista\n");
      return false;
    }

    printf("Percorre: %d\n",percorre->chave);
    printf("Percorre proximo: %d\n",percorre->proximo->chave);

    //Percorri a lista e encontrei por exclusão (y) -> Remover
    PtrNoLista auxiliar;
    //auxiliar apontar para o proximo do percorre
    auxiliar = percorre->proximo;

    //proximo do percorre recebe o proximo do aux
    percorre->proximo = auxiliar->proximo;
    //liberar a memoria
    free(auxiliar);
    //decrementar a quantidade de elementos
    lista->qtdeElementos--;
    return true;
}

//-----------------------------------------
// Homework (TODO)
//-----------------------------------------

// Pesquisar (easy)
// Destruir
// Proximo  (opcional)
// Anterior (opcional)
// Minimo   (opcional) -> primeiro elemento
// Maximo   (opcional) -> ultimo elemento

//-----------------------------------------
//-----------------------------------------

int main(int argc, const char * argv[]) {

  ListaOrdenada lista;

  iniciaListaOrdenada(&lista);

  if(estaVaziaListaOrdenada(&lista)) {
    printf("Está vazia mermão\n");
  } else {
    printf("Tem alguma coisa ai\n");
  }

  int tam;
  tam = tamanhoListaOrdenada(&lista);
  printf("Tamanho = %d\n", tam);

  imprimirListaOrdenada(&lista);

  insereListaOrdenada(&lista, 5);
  // 5
  imprimirListaOrdenada(&lista);

  insereListaOrdenada(&lista, 0);
  // 0, 5
  imprimirListaOrdenada(&lista);

  insereListaOrdenada(&lista, 2);
  insereListaOrdenada(&lista, 3);
  // 0, 2, 3, 5
  imprimirListaOrdenada(&lista);

  insereListaOrdenada(&lista, 50);
  // 0, 2, 3, 5, 50
  imprimirListaOrdenada(&lista);

  insereListaOrdenada(&lista, 2);
  // 0, 2, 2, 3, 5, 50
  imprimirListaOrdenada(&lista);

  if(estaVaziaListaOrdenada(&lista)) {
    printf("Está vazia mermão\n");
  } else {
    printf("Tem alguma coisa ai\n");
  }

  tam = tamanhoListaOrdenada(&lista);
  printf("Tamanho = %d\n", tam);

  insereListaOrdenada(&lista, 100);
  insereListaOrdenada(&lista, 200);
  // 0, 2, 2, 3, 5, 50, 100, 200
  imprimirListaOrdenada(&lista);

  // c1 (esta vazia)
  ListaOrdenada l2;
  iniciaListaOrdenada(&l2);
  removeListaOrdenada(&l2, 42);
  printf("L2 -> ");
  imprimirListaOrdenada(&l2);

  // c2 ( < primeiro lista)
  removeListaOrdenada(&lista, -10);
  imprimirListaOrdenada(&lista);
  // c3 ( primeiro elemento)
//  Lista = { 0 2 2 3 5 50 100 200 }
  removeListaOrdenada(&lista, 0);
  removeListaOrdenada(&lista, 2);
  //  Lista = {2 3 5 50 100 200 }
  imprimirListaOrdenada(&lista);

  // c4 (percorre e nao acha)
  //  Lista = {2 3 5 50 100 200 }
  // elemento intermediario (x)
  removeListaOrdenada(&lista, 35);
  imprimirListaOrdenada(&lista);

  // elemento maior do que o ultimo (x)
  removeListaOrdenada(&lista, 500);
  imprimirListaOrdenada(&lista);

  // c4 (percorre e acha)
  removeListaOrdenada(&lista, 200);
  //  Lista = {2 3 5 50 100}
  imprimirListaOrdenada(&lista);
  removeListaOrdenada(&lista, 50);
  //  Lista = {2 3 5 100}
  imprimirListaOrdenada(&lista);

  removeListaOrdenada(&lista, 5);
  //  Lista = {2 3 100}
  imprimirListaOrdenada(&lista);

  return EXIT_SUCCESS;
}
