//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

// define os valores que umac arta pode assumir
typedef struct {
  char valor;
  char naipe;
  bool carta_jogada;
}Carta;

// valores que o baralho assume: 13 valores de 4 naipes diferentes
typedef struct{
  Carta baralho_completo[13][4];
}Baralho;

//--------------------- Variáveis Globais ----------------------------------
// valores possíveis de naipe
char naipes[4] = {'O','E','C','P'}; // ouro,espada,copas, paus
//
char valores[13] = {'A','2','3','4','5','6','7','8','9','0','Q','J','K'};
//--------------------------------------------------------------------------

void criarBaralho(Baralho *b){
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4;j++){
    b->baralho_completo[i][j].valor = valores[i];
    b->baralho_completo[i][j].naipe = naipes[j];
    b->baralho_completo[i][j].carta_jogada = false;
    }
  }
}

// retornar o numero de cartas que estão disponiveis para jogar
int consultaCartas(Baralho *baralho){
  int cont = 0;

  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      if(baralho->baralho_completo[i][j].carta_jogada){
        cont++;
      }//if
    }//for int
  }//for ext

  return (52 - cont);
}

Carta* carteado(Baralho *b){
  int cont = 0, i , j;
  //srand(time(NULL));
  time_t t;
  srand((unsigned) time(&t));

  Carta *carta = malloc (3 * sizeof(Carta));

  while(cont != 3){
    i = rand() % 12;
    j = rand() % 3;

    if(!b->baralho_completo[i][j].carta_jogada){
      b->baralho_completo[i][j].carta_jogada = true;
      carta[cont] = b->baralho_completo[i][j];
      cont++;
    }
  }
  return carta;
}

//função main
int main(){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  Baralho b;//declaração de variaveis

  criarBaralho(&b);

  printf("%i\n\n",consultaCartas(&b));

  for(int i = 0; i <3; i++){
    Carta *ptr = carteado(&b);
    printf("Valor: %c Naipe: %c \n",ptr[i].valor,ptr[i].naipe);
  }

  printf("%i\n\n",consultaCartas(&b));
  return 0;
}//main
