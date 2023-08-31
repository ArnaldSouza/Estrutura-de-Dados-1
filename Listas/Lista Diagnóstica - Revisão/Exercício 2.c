//declara��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/* Fa�a um programa que receba do usu�rio um arquivo texto. Crie outro arquivo texto de sa�da contendo o texto do arquivo
de entrada original, por�m substituindo todas as vogais por "*". Al�m disso, mostre na tela quantas linhas esse arquivo
possui. Dentro do programa fa�a o controle de erros, isto �, insira comandos que mostre se os arquivos foram abertos com
sucesso, caso contr�rio, imprima uma mensagem de erro encerrando o programa. */

//fun��o main
int main(int argc, const char * argv[]){

  setlocale(LC_ALL, ""); //para usar caracteres especiais

  //declara��o de variaveis
  FILE *entrada, *saida;
  char c, str[200];
  int cont = 0, contlinha = 1;

  entrada = fopen("mangueira.txt","rt"); //abre o arquivo no modo leitura
  if(entrada == NULL){
    printf("Arquivo n�o encontrado! \n"); //caso n�o ache o arquivo
    system("pause"); //fecha o programa
    exit(1);
  }

  while((c = fgetc(entrada)) != EOF){ //enquanto o char n�o chegar ao fim do arquivo ele aramzena os caracteres na variavel c
    c = toupper(c); //coloca todos os caracteres do arquivo em letra maiuscula
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){ //quando o caracter c for igual a uma vogal
      c = '*'; //ele ser� substituido por asterisco
    }
    if(c == '\n' ){ //se o caracter encontrar o final da linha
      contlinha++; //acrescenta 1 no contador de linhas
    }
    str[cont] = c; //armazena cada caractere em uma posi��o na string str
    cont++; //incrementa 1 na variavel cont para pegar o proximo caractere
  }

  fclose(entrada); //fecha o arquivo de entrada
  printf("%s\n",str); //imprime o arquivo na tela do usuario

  saida = fopen("mangueira2.txt","w"); //abre o arquivo saida no modo de escrtia
  if(saida == NULL){ //caso n�o for possivel criar o arquivo
    printf("Arquivo n�o pode ser escrito! \n"); //exibe a mensagem de erro
    system("pause"); // e fecha o prgrama
    exit(1);
  }

  fputs(str,saida);//coloca a string str no arquivo saida
  fprintf(saida, "\nO numero de linhas do arquivo �: %i",contlinha); // imprime o numero de linhas dentro do arquivo

  printf("O numero de linha do arquivo �: %i\n",contlinha); //imprime na tela o numero de linhas
  fclose(saida); //fecha o arquivo saida

  return 0;
}//main
