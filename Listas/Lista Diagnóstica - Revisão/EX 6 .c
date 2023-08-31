#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

//define os valroes que a carta pode assumir
typedef struct{
  char valor;
  char naipe;
  bool cartaFoiJogada;
}Carta;

//valores que o baralho assume: 13 valores de 4 naipes diferentes
typedef struct{
  Carta baralho_absoluto[13][4];
}Baralho;

//---------------------- Variáveis Globais -----------------------
// valores possiveis de naipe
char naipes[4] = {'O','E','C','P'}; // ouro, espada, copa, paus
char valores[13] = {'A','2','3','4','5','6','7','8','9','0','Q','J','K'};
//---------------------- Variáveis Globais -----------------------

void criarBaralho(Baralho *b){
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
        b->baralho_absoluto[i][j].valor = valores[i];
        b->baralho_absoluto[i][j].naipe = naipes[i];
        b->baralho_absoluto[i][j].cartaFoiJogada = false;
    }
  }
}

//retorna o numerod e cartas que estão disponiveis para jogar
int consultaCartas(Baralho *b){
  int cont = 0;

  for(int i = 0; i < 13;i++){
    for(int j = 0; j < 4; j++){
      if(!b->baralho_absoluto[i][j].cartaFoiJogada){
        cont++;
      }//if
    }//for int
  }//for ext

  return cont;
}

Carta* carteado(Baralho *b){
  int conta = 0, i, j;
  time_t t;
  srand((unsigned) time(&t));

  Carta *carta = malloc (3 * sizeof(Carta));

  while(conta != 3){
      i = rand() % 12;
      j = rand() % 3;

      if (!b->baralho_absoluto[i][j].cartaFoiJogada) {
        b->baralho_absoluto[i][j].cartaFoiJogada = true;
        carta[conta] = b->baralho_absoluto[i][j];
        conta++;
      }
  }
  return carta;
}

int main(){
  setlocale(LC_ALL, ""); //para usar caracteres especiais

  Baralho b;

  criarBaralho(&b);

  printf("Cartas Disponíveis: %i\n\n",consultaCartas(&b));

  for(int i = 0; i < 3; i++){
    Carta *ptr = carteado(&b);
    printf("Valor: %c, Naipe: %c \n", ptr[i].valor, ptr[i].naipe);
  }
  printf("\n");
  printf("Cartas Disponíveis: %i\n\n",consultaCartas(&b));

  return 0;

}
