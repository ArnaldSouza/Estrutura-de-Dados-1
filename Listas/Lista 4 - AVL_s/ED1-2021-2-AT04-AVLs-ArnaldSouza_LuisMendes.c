#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int chave;
}ItemAVL;

typedef struct NoArvore *PonteiroAVL;

typedef struct NoArvore {
  ItemAVL item;
  PonteiroAVL esquerda;
  PonteiroAVL direita;
  int profundidade;
}NoArvore;

void IniciaAVL (PonteiroAVL *NoAVL) {
  (*NoAVL) = NULL;
}

bool VerificaAVLVazia (PonteiroAVL *NoAVL) {
  return (*NoAVL) == NULL;
}

int ProfundidadeAVL (PonteiroAVL *NoAVL) {
  if ((*NoAVL) == NULL){
    return 0;
  }else {
    int profundidade_esquerda = ProfundidadeAVL (&(*NoAVL)->esquerda);
    int profundidade_direita = ProfundidadeAVL (&(*NoAVL)->direita);

    if (profundidade_esquerda > profundidade_direita){
      return profundidade_esquerda + 1;
    }else{
      return profundidade_direita + 1;
    }
  }
}

void AtualizaProfundidadeAVL (PonteiroAVL *NoAVL) {
  if(VerificaAVLVazia(NoAVL) == true){
    return;
  }else{
    (*NoAVL)->profundidade = ProfundidadeAVL (NoAVL);
    AtualizaProfundidadeAVL (&(*NoAVL)->esquerda);
    AtualizaProfundidadeAVL (&(*NoAVL)->direita);
  }
}

void RotacaoSimplesDireita (PonteiroAVL *NoAVL) {
  PonteiroAVL aux = (*NoAVL)->esquerda;

  (*NoAVL)->esquerda = aux->direita;
  aux->direita = (*NoAVL);

  AtualizaProfundidadeAVL (&aux);
  AtualizaProfundidadeAVL (NoAVL);
  (*NoAVL) = aux;
}

void RotacaoSimplesEsquerda (PonteiroAVL *NoAVL) {
  PonteiroAVL aux = (*NoAVL)->direita;

  (*NoAVL)->direita = aux->esquerda;
  aux->esquerda = (*NoAVL);

  AtualizaProfundidadeAVL (&aux);
  AtualizaProfundidadeAVL (NoAVL);
  (*NoAVL) = aux;
}

void RotacaoDuplaDireita (PonteiroAVL *NoAVL) {
  PonteiroAVL aux = (*NoAVL)->esquerda;
  PonteiroAVL aux2 = aux->direita;

  aux->direita = aux2->esquerda;
  aux2->esquerda = aux;
  (*NoAVL)->esquerda = aux2->direita;
  aux2->direita = (*NoAVL);

  AtualizaProfundidadeAVL (&aux);
  AtualizaProfundidadeAVL (&aux2);
  AtualizaProfundidadeAVL (NoAVL);
  (*NoAVL) = aux2;
}

void RotacaoDuplaEsquerda (PonteiroAVL *NoAVL) {
  PonteiroAVL aux = (*NoAVL)->direita;
  PonteiroAVL aux2 = aux->esquerda;

  (*NoAVL)->direita = aux2->esquerda;
  aux->esquerda = aux2->direita;
  aux2->direita = aux;
  aux2->esquerda = (*NoAVL);

  AtualizaProfundidadeAVL  (&aux);
  AtualizaProfundidadeAVL (&aux2);
  AtualizaProfundidadeAVL (NoAVL);
  (*NoAVL) = aux2;
}

void AplicarRotacao (PonteiroAVL *NoAVL) {
  int bar = ProfundidadeAVL (&(*NoAVL)->direita) - ProfundidadeAVL (&(*NoAVL)->esquerda);
  if (abs (bar) > 1) {
    if (bar < 0) {
      if (ProfundidadeAVL (&(*NoAVL)->esquerda->esquerda) >= ProfundidadeAVL (&(*NoAVL)->esquerda->direita)){
        RotacaoSimplesDireita (NoAVL);
      }else{
        RotacaoDuplaDireita (NoAVL);
      }
    }else if (ProfundidadeAVL (&(*NoAVL)->direita->esquerda) > ProfundidadeAVL (&(*NoAVL)->direita->direita)){
      RotacaoDuplaEsquerda (NoAVL);
    }else{
      RotacaoSimplesEsquerda (NoAVL);
    }
  }
}

bool InsereAVL (PonteiroAVL *NoAVL, ItemAVL item) {
  bool aux;
  if ((*NoAVL) == NULL){
    (*NoAVL) = (PonteiroAVL) malloc (sizeof (NoArvore));
    (*NoAVL)->direita = (*NoAVL)->esquerda = NULL;
    (*NoAVL)->item = item;
    (*NoAVL)->profundidade = 0;
    return true;
  }else if ((*NoAVL)->item.chave == item.chave){
    return false;
  }else if ((*NoAVL)->item.chave > item.chave){
    aux = InsereAVL (&(*NoAVL)->esquerda, item);
  }else{
    aux = InsereAVL (&(*NoAVL)->direita, item);
  }
  if (aux) {
    AplicarRotacao (NoAVL);
    AtualizaProfundidadeAVL (NoAVL);
    return true;
  }else{
    return false;
  }
}

PonteiroAVL PegaMax (PonteiroAVL *NoAVL) {
  if ((*NoAVL)->direita != NULL){
    return PegaMax (&(*NoAVL)->direita);
  }
  return (*NoAVL);
}

bool RemoveAVL (PonteiroAVL *NoAVL, int chave) {
  bool aux2;
  if ((*NoAVL) == NULL){
    return false;

  }else if ((*NoAVL)->item.chave == chave){
    PonteiroAVL aux = (*NoAVL);

    if ((*NoAVL)->direita == NULL && (*NoAVL)->esquerda == NULL){
      (*NoAVL) = NULL;
    }else if ((*NoAVL)->esquerda == NULL){
      (*NoAVL) = (*NoAVL)->direita;
    }else if ((*NoAVL)->direita == NULL){
      (*NoAVL) = (*NoAVL)->esquerda;
    }else{
        (*NoAVL) = PegaMax (&(*NoAVL)->esquerda);
        (*NoAVL)->direita = aux->direita;
    }
    free(aux);
    return true;
  }else if ((*NoAVL)->item.chave > chave){
    aux2 = RemoveAVL (&(*NoAVL)->esquerda, chave);
  }else{
    aux2 = RemoveAVL (&(*NoAVL)->direita, chave);
  }
  if (aux2){
    AplicarRotacao (NoAVL);
    AtualizaProfundidadeAVL (NoAVL);
    return true;
  }else{
    return false;
  }
}

void DestroiAVL (PonteiroAVL *NoAVL) {
    if((*NoAVL) != NULL){
        DestroiAVL (&(*NoAVL)->esquerda);
        DestroiAVL (&(*NoAVL)->direita);
        RemoveAVL (&(*NoAVL), (*NoAVL)->item.chave);
    }
}

void ImprimeNivel (PonteiroAVL *NoAVL, int nivel, FILE *arq) {
  if ((*NoAVL) == NULL){
    return;
  }else if (nivel == 1){
    int equilibra = 0;
    equilibra = ProfundidadeAVL (&(*NoAVL)->direita) - ProfundidadeAVL (&(*NoAVL)->esquerda);
    fprintf(arq, "%i (%i), ", (*NoAVL)->item.chave, equilibra);
  }else{
    ImprimeNivel (&(*NoAVL)->esquerda, nivel - 1, arq);
    ImprimeNivel (&(*NoAVL)->direita, nivel - 1, arq);
  }
}

void NivelImpresso (PonteiroAVL *NoAVL, FILE *arq) {
  for (int i = 1; i <= ProfundidadeAVL (&(*NoAVL)); i++) {
    ImprimeNivel (&(*NoAVL), i, arq);
    fprintf (arq, "\n");
  }
}

int main (int argc, char *argv[]) {
  PonteiroAVL ponteiro;
  ItemAVL elemento;
  IniciaAVL (&ponteiro);

  FILE *entrada = fopen (argv[1], "r");
  FILE *saida = fopen (argv[2], "w");

  if(argc != 3){
    printf("Numero de argumentos invalidos\n");
  }

  if (entrada == NULL || saida == NULL){
    perror ("\nErro ao abrir um dos arquivos!!: \n");
  }else{
    char linha[101], *passe, *temporario = NULL;
    fgets(linha, sizeof(linha), entrada);
    linha[strcspn (linha, "\n")] = '\0';
    passe = strtok (linha, ",");
    elemento.chave = strtol (passe, &temporario, 10);
    InsereAVL (&ponteiro, elemento);

    while (passe != NULL) {
      passe = strtok (NULL, ",");
      if (passe != NULL) {
        elemento.chave = strtol (passe, &temporario, 10);
        InsereAVL (&ponteiro, elemento);
      }
    }
    fprintf (saida, "[*]antes\n");
    NivelImpresso (&ponteiro, saida);

    fgets(linha, sizeof(linha), entrada);
    linha[strcspn (linha, "\n")] = '\0';
    passe = strtok (linha, ",");
    elemento.chave = strtol (passe, &temporario, 10);
    RemoveAVL (&ponteiro, elemento.chave);

    while (passe != NULL) {
      passe = strtok (NULL, ",");
      if (passe != NULL) {
        elemento.chave = strtol (passe, &temporario, 10);
        RemoveAVL (&ponteiro, elemento.chave);
      }
    }
    fprintf (saida, "\n[*]depois\n");
    NivelImpresso (&ponteiro, saida);

    DestroiAVL (&ponteiro);
  }
  fclose (entrada);
  fclose (saida);
  return 0;
}
