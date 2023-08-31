#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

typedef struct{
  int codPaciente;
  char informacoes[200];
}Paciente;

typedef struct NoLista *PonteiroNoLista;

typedef struct NoLista{
  Paciente elemento;
  PonteiroNoLista proximo;
  PonteiroNoLista anterior;
}NoLista;

typedef struct{
  PonteiroNoLista primeiro;
  PonteiroNoLista ultimo;
  int tamanho;
}Lista;

void IniciaLista(Lista *lista){
  lista->primeiro = NULL;
  lista->tamanho = 0;
} //fun��o IniciaLista

bool VerificaListaVazia(Lista *lista){
  return (lista->tamanho == 0);
} //fun��o VerificaListaVazia

bool InserirItemLista(Lista *lista, Paciente *x){
  PonteiroNoLista novo;
  novo = (PonteiroNoLista) malloc (sizeof(NoLista));
  novo->elemento.codPaciente = x->codPaciente; //inserindo o codigo do paciente na vari�vel novo

  strcpy(novo->elemento.informacoes, x->informacoes);//inserindo as informa��es atreladas ao paciente
  //verificando a posi��o do paciente
  if(VerificaListaVazia(lista) == true) {
    novo->proximo = NULL;
    novo->anterior = NULL;
    lista->primeiro = novo;
    lista->ultimo = novo;
  }else if (x->codPaciente < lista->primeiro->elemento.codPaciente){
    lista->primeiro->proximo = novo;
    novo->proximo = lista->primeiro;
    novo->anterior = NULL;
    lista->primeiro = novo;
  }else if(x->codPaciente > lista->ultimo->elemento.codPaciente){
    lista->ultimo->proximo = novo;
    novo->anterior = lista->ultimo;
    novo->proximo = NULL;
    lista->ultimo = novo;
  }else{
    PonteiroNoLista auxiliar;
    for(auxiliar = lista->primeiro; auxiliar->proximo != NULL && x->codPaciente > auxiliar->proximo->elemento.codPaciente; auxiliar = auxiliar->proximo)
    novo->proximo = auxiliar->proximo;
    novo->proximo = auxiliar;
    auxiliar->proximo = novo;
  }
  lista->tamanho++;
  return true;
}//fn��o InserirItemLista

void ProcurarLista(Lista *lista, int codigo_pesquisado, FILE *arq_saida){
  PonteiroNoLista ponteiro_auxiliar = lista->primeiro;
  //fazendo a leitura dos dados do arquivo
  while(ponteiro_auxiliar != NULL && codigo_pesquisado > ponteiro_auxiliar->elemento.codPaciente){
    ponteiro_auxiliar = ponteiro_auxiliar->proximo;
  }//while
  //verificando se � um c�digo existente ou n�o e realizando sua devida a��o
  if(ponteiro_auxiliar == NULL || ponteiro_auxiliar->elemento.codPaciente > codigo_pesquisado){
    fprintf(arq_saida, "Codigo nao encontrado");
  }else{
    //inserindo o caracter {, o c�digo do paciente e os dados referentes ao c�digo
    fputc('{', arq_saida);
    fprintf(arq_saida, "%d", ponteiro_auxiliar->elemento.codPaciente);
    fputs(ponteiro_auxiliar->elemento.informacoes, arq_saida);
  }//else
}//fun��o ProcurarLista

void ImprimirLista(Lista *lista, FILE *arq_saida){

  if(VerificaListaVazia (lista) == true){
    printf("A lista est� vazia!\n");
  }else{
    PonteiroNoLista auxiliar;
    for(auxiliar = lista->primeiro; auxiliar != NULL; auxiliar = auxiliar->proximo){
    fputc('{', arq_saida);
    fprintf(arq_saida, "%d", auxiliar->elemento.codPaciente);
    fputs(auxiliar->elemento.informacoes, arq_saida);
    }//for
    printf("\n");
  }//else
}//fun��o ImprimirLista

void ImprimirListaInvertida(Lista *lista, FILE *arq_saida){

  if(VerificaListaVazia (lista) == true){
    printf("A lista est� vazia!\n");
  }else{
    PonteiroNoLista auxiliar;
    for(auxiliar = lista->ultimo; auxiliar != NULL; auxiliar = auxiliar->anterior){
      fputc('{', arq_saida);
      fprintf(arq_saida, "%d", auxiliar->elemento.codPaciente);
      fputs(auxiliar->elemento.informacoes, arq_saida);
    }//for
    printf("\n");
  }//else
}//fun��o ImprimirListaInvertida

int TamanhoLista (Lista *lista){
  return lista->tamanho;
}//fun��o TamanhoLista

void DestruirLista (Lista *lista){
  PonteiroNoLista auxiliar;
  while((lista->primeiro) != NULL){
    auxiliar = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(auxiliar);
  }//while
}//fun��o DestruirLista

int main(int argc, char *argv[]){

  setlocale(LC_ALL, "");

  FILE *arq_entrada;
  FILE *arq_saida;

  arq_entrada = fopen(argv[1], "r");
  arq_saida = fopen(argv[2], "w");

  //verificando a quantidade de paramentros inseridas
  if(argc != 3){
    printf("Quantidade de par�metros inv�lida!!\n");
  }//if
  if(arq_entrada == NULL){
    perror("");
  }else if(arq_saida == NULL){
    perror("");
  }//else

  Lista lista_paciente;
  char verifica_arquivo[400];
  int verifica_operacao;
  Paciente paciente;
  int codigo_paciente_pesquisado;

  /*verifica��o dos dados do arquivo com base no "{", se ainda existir esse caracter ele l� os valores em seguida e segue
  at� n�o ter mais*/
  while(fgetc(arq_entrada) == '{'){
    //lendo o c�digo
    fscanf(arq_entrada, "%d", &paciente.codPaciente);
    //recebendo as informa��es
    fgets(paciente.informacoes, 200, arq_entrada);
    //inserindo o paciente na lista
    InserirItemLista(&lista_paciente, &paciente);
    //lendo a opera��o desejada
    fscanf(arq_entrada, "%d", &verifica_operacao);

    if(verifica_operacao == 1 && verifica_operacao == 2 && verifica_operacao == 3){
      fprintf(arq_saida, "Op��o de Opera��o inv�ida!");
      exit(1);
    }//else
    if(verifica_operacao == 1){
      printf("\nLista Ordenada Crescente Escolhida!");
      ImprimirLista(&lista_paciente, arq_saida);
      DestruirLista(&lista_paciente);
      exit(1);
    }else if(verifica_operacao == 2){
      printf("\nLista Ordenada Decrescente Escolhida!");
      ImprimirListaInvertida(&lista_paciente, arq_saida);
      DestruirLista(&lista_paciente);
      exit(1);
    }else if(verifica_operacao == 3){
      printf("\nOpera��o de Consulta Escolhida!\n");
      fscanf (arq_entrada, "%i", &codigo_paciente_pesquisado);
      ProcurarLista(&lista_paciente, codigo_paciente_pesquisado, arq_saida);
      DestruirLista(&lista_paciente);
      exit(1);
    }//else
  }//while

  fclose(arq_entrada);
  fclose(arq_saida);

  DestruirLista(&lista_paciente);

  return 0;
}//main
