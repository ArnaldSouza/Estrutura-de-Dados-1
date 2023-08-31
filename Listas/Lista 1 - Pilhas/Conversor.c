//Nomes: Arnald Souza e Luis Henrique Ferracciu Pagotto Mendes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define N 100

//------------------------ Pilha est�tica ------------------------//

typedef struct{
  int chaveEstatica;
} ItemEstatico;

typedef struct{
  ItemEstatico vetor[N];
  int topo_estatico;
}PilhaEstatica;

void iniciaEstatica(PilhaEstatica *pilha_estatica){
  pilha_estatica->topo_estatico = 0;
}//fun��o iniciaEstatica

int EstaticaVazia(PilhaEstatica *pilha_estatica){
  return (pilha_estatica->topo_estatico == 0);
}//fun��o EstaticaVazia

int EstaticaCheia(PilhaEstatica *pilha_estatica){
  return (pilha_estatica->topo_estatico == N);
}//fun��o EstaticaCheia

void EmpilhaEstatica(PilhaEstatica *pilha_estatica, ItemEstatico item){
  if(EstaticaCheia(pilha_estatica) == 0){
    pilha_estatica->vetor[pilha_estatica->topo_estatico] = item;
    pilha_estatica->topo_estatico++;
  }else{
    printf("A pilha est� cheia\n");
  }//if else
}//fun��o EmpilhaDinamica

void DesempilhaEstatica(PilhaEstatica *pilha_estatica, ItemEstatico *item){
  if(EstaticaVazia(pilha_estatica) == 0){
    *item = pilha_estatica->vetor[pilha_estatica->topo_estatico - 1];
    pilha_estatica->topo_estatico--;
  }else{
    printf("A pilha est� vazia\n");
  }//if else
}//fun��o DesempilhaEstatica

int tamanhoEstatico(PilhaEstatica *pilha_estatica){
  return (pilha_estatica->topo_estatico);
}//fun��o tamanhoEstatico

ItemEstatico retornarTopoEstatico(PilhaEstatica *pilha_estatica){
  return (pilha_estatica->vetor[pilha_estatica->topo_estatico - 1]);
}//fun��o retornarTopoEstatico

void imprimirEstatica(PilhaEstatica *pilha_estatica){
    for(int i = 0; i < pilha_estatica->topo_estatico; i++){
      printf("%d\n", pilha_estatica->vetor[i].chaveEstatica);
    }//for
    printf("\n");
}//fun��o imprimirEstatica

//------------------------ Pilha din�mica ------------------------//

typedef struct {
  int chaveDinamica;
} ItemDinamico;

typedef struct NoDinamico *Ponteiro;

typedef struct NoDinamico{
  ItemDinamico elemento;
  Ponteiro proximo_elemento;
}NoPilhaDinamica;

typedef struct {
  Ponteiro topo_dinamico;
  int tamanho_dinamico;
}PilhaDinamica;

void iniciaDinamica (PilhaDinamica *pilha_dinamica){
  pilha_dinamica->topo_dinamico = NULL;
  pilha_dinamica->topo_dinamico = 0;
  pilha_dinamica->tamanho_dinamico = 0;
}//fun��o iniciaDinamica

int DinamicaVazia (PilhaDinamica *pilha_dinamica){
  return (pilha_dinamica->tamanho_dinamico == 0);
}//fun��o DinamicaVazia

void EmpilhaDinamica (PilhaDinamica *pilha_dinamica, ItemDinamico elemento){
  Ponteiro ponteiro_auxiliar;
  ponteiro_auxiliar = (Ponteiro) malloc (sizeof (NoPilhaDinamica));
  ponteiro_auxiliar->elemento = elemento;
  ponteiro_auxiliar->proximo_elemento = pilha_dinamica->topo_dinamico;
  pilha_dinamica->topo_dinamico = ponteiro_auxiliar;
  pilha_dinamica->tamanho_dinamico++;
}//fun��o EmpilhaDinamica

void DesempilhaDinamica (ItemDinamico *elemento, PilhaDinamica *pilha_dinamica){
  if(DinamicaVazia(pilha_dinamica)){
    printf("A pilha est� vazia!\n");
  }else{
    *elemento = pilha_dinamica->topo_dinamico->elemento;
    Ponteiro ponteiro_auxiliar;
    ponteiro_auxiliar = pilha_dinamica->topo_dinamico;
    pilha_dinamica->topo_dinamico = pilha_dinamica->topo_dinamico->proximo_elemento;
    free(ponteiro_auxiliar);
    pilha_dinamica->tamanho_dinamico--;
  }//else
}//fun��o DesempilhaDinamica

int TamanhoDinamico (PilhaDinamica *pilha_dinamica){
  return (pilha_dinamica->tamanho_dinamico);
}//fun��o TamanhoDinamico

ItemDinamico TopoPilhaDinamica (ItemDinamico *elemento, PilhaDinamica *pilha_dinamica){
  *elemento = pilha_dinamica->topo_dinamico->elemento;
  return *elemento;
}//fun��o TopoPilhaDinamica

void ExibePilhaDinamica (PilhaDinamica *pilha_dinamica){
  Ponteiro ponteiro_auxiliar;
  printf("A pilha est� na atual situa��o: ");
  for(ponteiro_auxiliar = pilha_dinamica->topo_dinamico; ponteiro_auxiliar != NULL; ponteiro_auxiliar = ponteiro_auxiliar->proximo_elemento)
    printf ("%d ", ponteiro_auxiliar->elemento.chaveDinamica);
}//fun��o ExibePilhaDinamica

bool VerificaInteiro(float numero_recebido){
  int auxiliar;
  auxiliar = numero_recebido;
  return (auxiliar != numero_recebido);
}//fun��o VerificaInteiro

int main(int argc, char *argv[]){

  setlocale (LC_ALL, "");

  FILE *arq_entrada;
  FILE *arq_saida;

  char verificaTipoPilha;
  int verifica_valores;
  float verifica_valores_auxiliar;

  arq_entrada = fopen(argv[1], "r");
  arq_saida = fopen(argv[2], "w");

  if(arq_entrada == NULL){
    perror("");
  }else if(arq_saida == NULL){
    perror("");
  }else{
    //lendo o arquivo de entrada e verificando se � do tipo est�tico ou din�mico
      fscanf(arq_entrada, "%c", &verificaTipoPilha);

      if(verificaTipoPilha != 'd' && verificaTipoPilha != 'e'){
        printf("Tipo de Arquivo Inv�lido!\n");
        fputs("Tipo de Arquivo Inv�lido!", arq_saida);
      }//if
      if(verificaTipoPilha == 'd'){
        printf("Pilha Din�mica escolhida!!\n");

        PilhaDinamica dinamica;
        ItemDinamico item_dinamico;

        iniciaDinamica(&dinamica);
        //iniciando a leitura do arquivo de entrada
        for(int i = 0; !feof(arq_entrada); i++) {
          //lendo o arquivo com vari�vel inteiro e float
          fscanf(arq_entrada, "%i", &verifica_valores);
          fscanf(arq_entrada, "%f", &verifica_valores_auxiliar);
          //comparando para verificar exist�ncia de n�meros reais
          if(verifica_valores != verifica_valores_auxiliar){
            fprintf(arq_saida, "Valor Inv�lido Encontrado!!");
          }//if

          item_dinamico.chaveDinamica = verifica_valores;

          EmpilhaDinamica(&dinamica, item_dinamico);
        }//for

        ExibePilhaDinamica(&dinamica);
        //lendo os dados da pilha din�mica e convertendo-os para bin�rio
        for(int i = TamanhoDinamico(&dinamica); i > 0; i--){
          int tamanho_array = 0;
          int binario[tamanho_array];

          verifica_valores = dinamica.topo_dinamico->elemento.chaveDinamica;

          while(verifica_valores >= 0){
            //verificando os valores e convertendo em bin�rio
            if(verifica_valores < 2){
              tamanho_array++;
              binario[tamanho_array - 1] = verifica_valores % 2;
              verifica_valores = 0;
              verifica_valores--;
            }else if(verifica_valores % 2 == 0){
              tamanho_array++;
              binario[tamanho_array - 1] = verifica_valores % 2;
              verifica_valores = verifica_valores / 2;
            }else{
              tamanho_array++;
              binario[tamanho_array - 1] = verifica_valores % 2;
              verifica_valores = (verifica_valores - 1) / 2;
            }//else
          }//while
          //iniciando a impress�o dos dados convertidos no arquivo de sa�da
          for(int j = (tamanho_array - 1); j >= 0; j--){
            fprintf(arq_saida, "%i", binario[j]);
          }//for
          fputs("\n", arq_saida);
          DesempilhaDinamica(&item_dinamico, &dinamica);
        }//for
        ExibePilhaDinamica(&dinamica);
      }//if

    if(verificaTipoPilha == 'e'){
      printf("Pilha Est�tica Escolhida \n");

      PilhaEstatica estatica;
      ItemEstatico item_estatico;

      iniciaEstatica(&estatica);
      //iniciando a leitura dos valores da pilha est�tica
      for(int i = 0; !feof(arq_entrada); i++){
        //lendo os arquivos com vari�vel inteiro e float
        fscanf(arq_entrada,"%i", &verifica_valores);
        fscanf(arq_entrada, "%f", &verifica_valores_auxiliar);
        //comparando para verificar exist�ncia de n�meros reais
        if(verifica_valores != verifica_valores_auxiliar){
          fprintf(arq_saida, "Valor Inv�lido Encontrado!!");
        }//if

        item_estatico.chaveEstatica = verifica_valores;

        EmpilhaEstatica(&estatica, item_estatico);
      }//for

      imprimirEstatica(&estatica);
      //lendo os dados da pilha e convertendo para bin�rio
      for(int i = estatica.topo_estatico; i > 0; i--){
        int tamanho_array = 0;
        int binario[tamanho_array];

        verifica_valores = estatica.vetor[i-1].chaveEstatica;

        while(verifica_valores >= 0){
          //estrutura de repeti��o para verificar todos os valores do arquivo e convert�-los
          if(verifica_valores < 2){
            tamanho_array++;
            binario[tamanho_array - 1] = verifica_valores % 2;
            verifica_valores = 0;
            verifica_valores--;
          }else if(verifica_valores % 2 == 0){
            tamanho_array++;
            binario[tamanho_array - 1] = verifica_valores % 2;
            verifica_valores = verifica_valores / 2;
          }else{
            tamanho_array++;
            binario[tamanho_array - 1] = verifica_valores % 2;
            verifica_valores = (verifica_valores - 1) / 2;
          }//else
        }//while
        //salvando os dados no arquivo de sa�da
        for(int j = (tamanho_array - 1); j >= 0; j--){
          fprintf(arq_saida, "%i", binario[j]);
        }//for
        fputs("\n", arq_saida);
        DesempilhaEstatica(&estatica, &item_estatico);
      }//for
      imprimirEstatica(&estatica);
    }//if
  }//else
  //fechando os arquivo de entrada e sa�da
  fclose(arq_entrada);
  fclose(arq_saida);

  return 0;
}//main
