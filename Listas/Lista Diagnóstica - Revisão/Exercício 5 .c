//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

/* Defina um tipo abstratro de dados que irá representar bandas de música. Essa estrutura deve ter o nome da
banda, que tipo de musica ela toca, o número de integrantes, em que posição do raking ela está dentre suas
5 bandas favoritas
  A - Crie uma função para preencher as 5 estruturas de banda criadas;
  B - Após criar e preencher, exibas todas as informações de bandas/estruturas. Não se esqueça de usar ->
para preencher os membros das structs.
  C - Crie uma função que peça um numero de 1 até 5. EM seguida o programa deve exibir informações da banda cuja
posição no seu ranking é a que foi solicitada pelo usuário.
 */

#define TAM 5 //define o tamanho(TAM) como 5

//define a estruura banda com 4 informações
typedef struct{
  char nome[25];
  char tipo[25];
  int n_integrantes;
  int ranking;
}Banda;

//função preencherBandas
void preencherBandas(Banda *bandas){

  for(int i = 0; i < TAM; i++){
    printf("Digite o nome da %iª banda: ",i+1); //pede o nome da banda
    fgets(bandas[i].nome,25,stdin); //armazena o nome da banda
    bandas[i].nome[strcspn(bandas[i].nome, "\n")] = '\0'; //substitui o \n por \0
    fflush(stdin); //limpa o buffer

    printf("Qual estilo de música que ela toca? "); //pede o tipo de musica
    fgets(bandas[i].tipo,25,stdin); //armazena o tipo de musica
    bandas[i].tipo[strcspn(bandas[i].tipo, "\n")] = '\0'; //substitui o \n por \0
    fflush(stdin); //limpa o buffer

    printf("Qual o número de integrantes? "); //pede o numero de integrantes
    scanf("%i",&bandas[i].n_integrantes); //armazena o numero de integrantes
    setbuf(stdin, NULL); //limpa o buffer

    printf("Qual a posição no seu raking das 5 melhores? "); //pede a posição no ranking
    scanf("%i",&bandas[i].ranking); //armazena a posição no raking
    setbuf(stdin, NULL); //limpa o buffer
    printf("\n");
  }
  system("cls"); //limpa a tela
}

//função rankingBandas
void rankingBandas(Banda *bandas){
  int aux_pos; //variavel para ajudar a encontrar a posição
  printf("Digite a posição que deseja: "); //pede a posição que o usuario deseja saber
  scanf("%i",&aux_pos); //aramzena essa posição

  for (int i = 0; i < TAM; i++) {
    if(aux_pos == bandas[i].ranking){ //compara as posições para achar uma igual a fornecida pelo usuario
      //mostra as informações da banda pedida pelo usuário
      printf("Banda: %s\n",bandas[i].nome);
      printf("Tipo de música: %s \n",bandas[i].tipo);
      printf("N° de integrantes: %i \n",bandas[i].n_integrantes);
    }
  }
}

//função main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  Banda bandas[TAM];//declaração de variaveis

  preencherBandas(&bandas[0]);

  for (int i = 0; i < TAM; i++) {
    //imprime as informações das bandas
    printf("Banda: %s\n",bandas[i].nome);
    printf("Tipo de música: %s \n",bandas[i].tipo);
    printf("N° de integrantes: %i \n",bandas[i].n_integrantes);
    printf("Posição no ranking: %i º \n",bandas[i].ranking);
    printf("\n");
  }
  system("pause"); //pausa o sistema
  system("cls"); //limpa a tela

  rankingBandas(&bandas[0]); //chama a função rankingBandas e passa a ela a variavel bandas

  return 0;
}//main
