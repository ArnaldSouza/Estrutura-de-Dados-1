//declaração de bibliotecas
#include <stdio.h>
#include <stdbool.h> // 1/0 :  -> true/false, bool
#include <locale.h>

//Pilha (estatica)
// Definir os tipos (ED)
//  array (vetor) -> elementos
//  topo (indexador)

#define MAXTAM 8
typedef struct{
  int array[MAXTAM];
  int topo;
}PilhaEstatica;
//Pilha estática

// 1 - Inicialização
void iniciaPilhaEstatica(PilhaEstatica *pilha) {
  pilha->topo = 0;
  //a primeira posição para inserção na pilha, é a posição 0 do vetor
}

//5 - esta vazia
bool estaVaziaPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo == 0);
}

//6 - esta cheia
bool estaCheiaPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo == MAXTAM);
}

//7 - quantidade de elementos na estrutura
int tamanhoPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo);
}

//2 - Inserção (push/empilha)
void empilhaPilhaEstatica(PilhaEstatica *pilha, int x){
    //Vazia ->? Pode
    //Cheia ->? Não

  //Se a pilha não estiver cheia:
  if(estaCheiaPilhaEstatica(pilha) == false){
    //atribuir o x no vetor na posição do topo
    pilha->array[pilha->topo] = x;
    //incrementa o topo (topo++)
    pilha->topo++;
  }else{//printf(warning: voce nao pode inserir)
    printf("Nao e possivel inserir valores na pilha\n");
  }
}

//3 - remoção (pop/desempilha)
int desempilhaPilhaEstatica(PilhaEstatica *pilha){
int aux = -999;
  //remover cheia? Pode
  //remover vazia? Não

    //Se a pilha não estiver vazia:
    if(estaVaziaPilhaEstatica(pilha) == false){
      aux = pilha->array[pilha->topo-1];
      //aux = salva ultimo valor valido
      //decrementar o topo
      pilha->topo--;
      //retornar o valor
    }else{
      printf("Warning: Não pode ser removido\n");
    }
    //Senão: não vai rolar
  return(aux);
}

//8 - Imprime a estrutura (print)
void imprimePilhaEstatica(PilhaEstatica *pilha){
  //pilha->vetor, pilha->topo
  printf("Pilha = {");

  int i;
  for(i = 0; i < pilha->topo; i++){
    printf("%d ",pilha->array[i]);
  }

  printf("}\n");
}

//4 - pesquisa/consulta (top/topo)
int pesquisaPilhaEstatica(PilhaEstatica *pilha){
  int x;
  x = pilha->array[pilha->topo-1];
  return x;
}

//função main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  PilhaEstatica p; //declaração de variaveis
  iniciaPilhaEstatica(&p);
  printf("Rodou\n");

  if(estaVaziaPilhaEstatica(&p)){
    printf("Esta vazia\n");
  }else{
    printf("Tem alguma coisa ai dentro\n");
  }

  if(estaCheiaPilhaEstatica(&p)){
    printf("Esta cheia\n");
  }else{
    printf("Pilha nao esta cheia\n");
  }

  int tmp = tamanhoPilhaEstatica(&p);
  printf("Tamanho = %d\n",tmp);

  imprimePilhaEstatica(&p);

  //8 elementos
  empilhaPilhaEstatica(&p, 7);
  imprimePilhaEstatica(&p);
  //pilha = {7}

  empilhaPilhaEstatica(&p, 23);
  imprimePilhaEstatica(&p);
  //pilha = {7,23}

  empilhaPilhaEstatica(&p, 10);
  imprimePilhaEstatica(&p);
  //pilha = {7,23,10}

  empilhaPilhaEstatica(&p, 47);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47}

  empilhaPilhaEstatica(&p, 19);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47,19}

  empilhaPilhaEstatica(&p, 14);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47,19,14}

  empilhaPilhaEstatica(&p, 41);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47,19,14,41}

  empilhaPilhaEstatica(&p, 4);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47,19,14,41,4}

  empilhaPilhaEstatica(&p, 69);
  imprimePilhaEstatica(&p);
  //pilha = {27,23,10,47,19,14,41,4}

  printf("Topo: %i \n",pesquisaPilhaEstatica(&p));

  tmp = tamanhoPilhaEstatica(&p);
  printf("\nTamanho = %d\n",tmp);

  int valor;
  for(int i = 0; i < 9; i++){
    valor = desempilhaPilhaEstatica(&p);
    imprimePilhaEstatica(&p);
  }

  return 0;
}//main
