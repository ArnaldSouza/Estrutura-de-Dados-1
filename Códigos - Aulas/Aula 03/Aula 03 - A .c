//declaração de bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO 5
// tamanho fila definido (Tamanho)

// estrutura de fila estática
// duas extremidades manipulaveis
// inicio de fila (primeiro elemento)
// fim de fila (ultimo elemento)
typedef struct{

  int inicio; // inicio (int), variavel indexadora / controla o inicio da fila
  int fim; // fim (int), variavel indexadora / controla o fim da fila
  int array[TAMANHO]; //  Q = array[Tamanho] / array de 5 posições
  int qtdeElementos; // contador = qtde de elemento dentro do array

}FilaEstatica;

// inicialização
void iniciaFilaEstatica(FilaEstatica *fila){
    fila->qtdeElementos = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

// estrutura esta vazia
bool estaVazia(FilaEstatica *fila){
  //contador == 0
  return(fila->qtdeElementos == 0);
}

// estrutura esta cheia
bool estaCheia(FilaEstatica *fila){
  // contador == TAMANHO
  return(fila->qtdeElementos == TAMANHO);
}

//indice = TAMANHO-1
//indice == 0
//indice++

int incrementaIndice(int i) {
  int newValue = (i+1) % TAMANHO;
  return newValue;
}

// inserções são feitas no final da fila
void enfileirarEstatica(FilaEstatica *fila, int x){
  // Só posso inserir um elemento se a fila não estiver cheia
  if(!estaCheia(fila)){
    fila->fim = incrementaIndice(fila->fim); // incrementa o fim
    fila->array[fila->fim] = x; // atribui o elemento na posição indicada pelo fim (array)
    fila->qtdeElementos++; // incremetna a quantidade de qtdeElementos
  } else{
    printf("Warning: não pôde inserir pois fila está cheia\n"); // senão warning
  }
}

// remoções são feitas no inicio da fila
int desenfileirarFilaEstatica(FilaEstatica *fila){
  int ret = -999;
  //Só psso remover elemento se a fila não estiver Vazia
  if(!estaVazia(fila)){
  //salvar dado que precisa ser retornado
  ret = fila->array[fila->inicio];
  //incrementa a posição do inicio
  fila->inicio = incrementaIndice(fila->inicio);
  //decrementa a quantidade de elementos
  fila->qtdeElementos--;
  // retorna o valor para o usuario
  }else{
  printf("Warning: Não posso remover elementos de uma fila vazia\n");
  }
  return(ret);
}

// tamanho da estrutura
int tamanhoFilaEstatica(FilaEstatica *fila){
  return(fila->qtdeElementos);
}

void imprimeFilaEstatica(FilaEstatica *fila){
  printf("Fila = { ");
  //for de 0 a TAMANHO -1
  int n = tamanhoFilaEstatica(fila);

  int i;
  for(i = 0; i < n; i++){
    int indice = (fila->inicio + i) % TAMANHO;
    printf("%d ",fila->array[indice]);
  }

  printf("}\n");
}
/*
// consultar o primeiro elemento
void primeiroElemento(FilaEstatica *fila){

}

// consultar o ultimo elemento
void ultimoElemento(FilaEstatica *fila){

}
*/
//função main
int main(int argc, const char * argv[]){

  FilaEstatica f;
  iniciaFilaEstatica(&f);

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  if(estaVazia(&f)){
    printf("Esta Vazia \n");
  }

  if(!estaCheia(&f)){
    printf("Não esta cheia\n");
  }

  enfileirarEstatica(&f,5);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,7);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,20);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,-99);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,0);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,10);


  int removido;
  removido = desenfileirarFilaEstatica(&f);
  imprimeFilaEstatica(&f);
  removido = desenfileirarFilaEstatica(&f);
  imprimeFilaEstatica(&f);
  removido = desenfileirarFilaEstatica(&f);

  enfileirarEstatica(&f,16);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,23);
  imprimeFilaEstatica(&f);
  enfileirarEstatica(&f,42);
  imprimeFilaEstatica(&f);

  printf("Tamanho = %d\n",tamanhoFilaEstatica(&f));

  printf("Sucesso\n");

  return 0;
}//main
