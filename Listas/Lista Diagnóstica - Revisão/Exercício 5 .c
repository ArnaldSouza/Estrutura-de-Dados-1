//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

/* Defina um tipo abstratro de dados que ir� representar bandas de m�sica. Essa estrutura deve ter o nome da
banda, que tipo de musica ela toca, o n�mero de integrantes, em que posi��o do raking ela est� dentre suas
5 bandas favoritas
  A - Crie uma fun��o para preencher as 5 estruturas de banda criadas;
  B - Ap�s criar e preencher, exibas todas as informa��es de bandas/estruturas. N�o se esque�a de usar ->
para preencher os membros das structs.
  C - Crie uma fun��o que pe�a um numero de 1 at� 5. EM seguida o programa deve exibir informa��es da banda cuja
posi��o no seu ranking � a que foi solicitada pelo usu�rio.
 */

#define TAM 5 //define o tamanho(TAM) como 5

//define a estruura banda com 4 informa��es
typedef struct{
  char nome[25];
  char tipo[25];
  int n_integrantes;
  int ranking;
}Banda;

//fun��o preencherBandas
void preencherBandas(Banda *bandas){

  for(int i = 0; i < TAM; i++){
    printf("Digite o nome da %i� banda: ",i+1); //pede o nome da banda
    fgets(bandas[i].nome,25,stdin); //armazena o nome da banda
    bandas[i].nome[strcspn(bandas[i].nome, "\n")] = '\0'; //substitui o \n por \0
    fflush(stdin); //limpa o buffer

    printf("Qual estilo de m�sica que ela toca? "); //pede o tipo de musica
    fgets(bandas[i].tipo,25,stdin); //armazena o tipo de musica
    bandas[i].tipo[strcspn(bandas[i].tipo, "\n")] = '\0'; //substitui o \n por \0
    fflush(stdin); //limpa o buffer

    printf("Qual o n�mero de integrantes? "); //pede o numero de integrantes
    scanf("%i",&bandas[i].n_integrantes); //armazena o numero de integrantes
    setbuf(stdin, NULL); //limpa o buffer

    printf("Qual a posi��o no seu raking das 5 melhores? "); //pede a posi��o no ranking
    scanf("%i",&bandas[i].ranking); //armazena a posi��o no raking
    setbuf(stdin, NULL); //limpa o buffer
    printf("\n");
  }
  system("cls"); //limpa a tela
}

//fun��o rankingBandas
void rankingBandas(Banda *bandas){
  int aux_pos; //variavel para ajudar a encontrar a posi��o
  printf("Digite a posi��o que deseja: "); //pede a posi��o que o usuario deseja saber
  scanf("%i",&aux_pos); //aramzena essa posi��o

  for (int i = 0; i < TAM; i++) {
    if(aux_pos == bandas[i].ranking){ //compara as posi��es para achar uma igual a fornecida pelo usuario
      //mostra as informa��es da banda pedida pelo usu�rio
      printf("Banda: %s\n",bandas[i].nome);
      printf("Tipo de m�sica: %s \n",bandas[i].tipo);
      printf("N� de integrantes: %i \n",bandas[i].n_integrantes);
    }
  }
}

//fun��o main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  Banda bandas[TAM];//declara��o de variaveis

  preencherBandas(&bandas[0]);

  for (int i = 0; i < TAM; i++) {
    //imprime as informa��es das bandas
    printf("Banda: %s\n",bandas[i].nome);
    printf("Tipo de m�sica: %s \n",bandas[i].tipo);
    printf("N� de integrantes: %i \n",bandas[i].n_integrantes);
    printf("Posi��o no ranking: %i � \n",bandas[i].ranking);
    printf("\n");
  }
  system("pause"); //pausa o sistema
  system("cls"); //limpa a tela

  rankingBandas(&bandas[0]); //chama a fun��o rankingBandas e passa a ela a variavel bandas

  return 0;
}//main
