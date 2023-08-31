#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// 1. Definir o(s) tipo(s)
// Pilha (din�mica)
typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{ // NoPilha
    int chave; // int chave
    PtrNoPilha proximo; //NoPilha* proximo
}NoPilha;

typedef struct{ //PilhaDinamica
  PtrNoPilha topo; // *NoPilha topo
  int qtde; // int qtde;
}PilhaDinamica;

// 2. Fun��es / opera��es
// inicializar a pilha
void iniciaPilhaDinamica(PilhaDinamica* pilha){
  //ponteiro aponta para nulo
  pilha->topo = NULL;
  //qtde de elemento � iniciada com zero
  pilha->qtde = 0;
}

// verificar se a pilha est� vazia
bool estaVaziaPilhaDinamica(PilhaDinamica* pilha){
  return(pilha->topo == NULL);
}

// retornar o tamanho da pilha (quantidade)
int tamanhoPilhaDinamica(PilhaDinamica* pilha){
  return(pilha->qtde);
}

// inserir elemento
void empilhaPilhaDinamica(PilhaDinamica *pilha, int x){

  // criar um novo No
    PtrNoPilha aux;
    aux = malloc(sizeof(NoPilha));

  //copiar valor inserido no novo No
    aux->chave = x;

  //proximo do novo No aponta para quem o topo apontava
    aux->proximo = pilha->topo;

  //topo aponto para novo No
  pilha->topo = aux;

  //incrementa quantidade + 1
  pilha->qtde++;
}

//printar a pilha
void imprimirPilhaDinamica(PilhaDinamica* pilha){
  printf("Pilha ={ ");

  PtrNoPilha percorre;
  for(percorre = pilha->topo; percorre != NULL; percorre = percorre->proximo){
     printf("%d ",percorre->chave);
  }

  printf(" }\n");
}

// remover elemento
int desempilhaPilhaDinamica(PilhaDinamica* pilha){
  int ret = -9999;
  if(!estaVaziaPilhaDinamica(pilha)){
    //criar um no auxiliar (aux)
    PtrNoPilha aux;
    //copiar valor que ser� retornado
    ret = pilha->topo->chave;
    //auxiliar apontar para o topo
    aux = pilha->topo;
    //topo apontar para o proximo do topo
    pilha->topo = pilha->topo->proximo;
    //desaloca memoria do auxiliar
    free(aux);
    //decrementa a quantidade
    pilha->qtde--;

  }else{
    printf("N�o � poss�vel remover de algo vazio\n");
  }

  //retorna um valor ao usu�rio
  return(ret);
}


// Homework
// pesquisar elemento(consulta topo)

// destruir a pilha

//fun��o main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais
  PilhaDinamica pd;

  iniciaPilhaDinamica(&pd);

  if(estaVaziaPilhaDinamica(&pd)){
    printf("Est� vazia \n");
  }else{
    printf("Tem algum elemento dentro\n");
  }

  empilhaPilhaDinamica(&pd,8);
  imprimirPilhaDinamica(&pd);
  empilhaPilhaDinamica(&pd,13);
  imprimirPilhaDinamica(&pd);
  empilhaPilhaDinamica(&pd,2);
  imprimirPilhaDinamica(&pd);

  //remover elemento
  int ret = desempilhaPilhaDinamica(&pd);
  imprimirPilhaDinamica(&pd);
  ret = desempilhaPilhaDinamica(&pd);
  imprimirPilhaDinamica(&pd);
  ret = desempilhaPilhaDinamica(&pd);
  imprimirPilhaDinamica(&pd);
  ret = desempilhaPilhaDinamica(&pd);
  imprimirPilhaDinamica(&pd);

  return 0;
}//main
