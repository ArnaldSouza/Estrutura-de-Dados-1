//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

/* Fa�a um programa que leia um valor N e crie dinamicamente um vetor com essa quantidade de elementos. Em seguida,
passe esse vetor para uma fun��o que vai ler os elementos desse vetor. Depois, no programa principal, imprima os
valores do vetor preenchido. Al�m disso, antes de finalizar o programa, lembre-se de liberar a �rea de mem�ria
alocada para armazenar os valores do vetor. */

//fun��o lerVetor
void lerVetor(int *vet, int *i){
  for(int j = 0; j < *i; j++){ //recebe os parametros para preencher o vetor
    printf("Insira o elemento %i do vetor: ",j+1); //pede o elemento x do vetor
    scanf("%i",&vet[j]); //armazena esse elemento
  }
}


//fun��o main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  int n, *vet;//declara��o de variaveis

  printf("Insira o tamanho do vetor: "); //pede o tamanho do vetor
  scanf("%i",&n); //armazena o tamanho do vetor

  vet = (int*) malloc(n * sizeof(int)); //aloca dinamicamente o vetor

  lerVetor(vet,&n); //chama a fun��o e passa os parametros vetor e tamanho

  printf("Vetor: [ "); //imprime o vetor
  for(int i = 0; i < n; i++){
    printf("%i ",vet[i]);
  }
  printf("]\n");

  free(vet); //libera o vetor
  return 0;
}//main
