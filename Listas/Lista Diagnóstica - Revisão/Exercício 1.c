//declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
  Um ponterio pdoe ser usado para dizer a uma função onde ela deve depositar o resulatdo de seus cálculos. Escreva uma
função que converta uma quantidade de minuots na notação horas/minutos. A função recebe como parametro:
  -- um numero inteiro (totalMinutos); e
  -- os endereços de duas variaveis inteiras, horas e minutos;
  A funcao deve entao atribuir valores as variaveis passadas por referencia, de modo que os valores atribuidos respeitem
as seguintes condições:
      -- minutos < 60;
      -- 60 * horas + minutos = totalMinutos
  Escreva também a função principal (main) que use a função desenvolvida;
*/

//funcao converterHora
void converterHora(int total_minutos, int* hora, int* min){
  while(total_minutos >= 60){ //enquanto o total de minutos for maior ou igual a 60
    *hora = *hora + 1; //sera adicionado 1 ao ponterio hora
    total_minutos = total_minutos - 60; //e tirará 60 minutos do toal de minutos
  }
  *min = total_minutos; //a variavel min  passara a valer o total de minutos que restaram
}// converterHora

//função main
int main(){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  int min_total, hora = 0, min;//declaração de variaveis

  printf("Digite a quantidade total de minutos: "); //pede ao usuario a quantidade total de minutos
  scanf("%i",&min_total);//armazena a quantidade digita pelo usuario

  converterHora(min_total, &hora, &min); //chama a funcao converteHora e passa para ela os valores

  printf("A conversão para HH:MM é: %02dh:%02dm\n",hora,min); //exibe a quantidade de minuots convertidos em horas e minuots

  return 0;
}//main
