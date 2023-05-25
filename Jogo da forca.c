#include <stdio.h>

int main(void) {

  char palavra[100];
  int opcao, strc;
  FILE *arq;

  printf("--- Seja bem-vindo ao jogo da forca ---");
  printf("\n\n---MENU---\n1- Configurar\n2- Jogar\n----------");
  printf("\n\nDigite uma das opções do menu:");
  scanf("%d", &opcao);

  switch (opcao) {
  case 1:
    printf("\n\n---------------------------");
    printf("\n Seja bem-vindo as configurações ");

    arq = fopen("Banco_palavras.txt", "w");
    do {
      printf("\n---------------------------");

      printf("\n\nQual palavra deseja adicionar?");
      scanf("%s", palavra);

      strc = strcmp(palavra, "sair");

      if (strc == 0) {
        printf(
            "\n---------------------------\nObrigado por adicionar novas "
            "palavras!\n---------------------------\nConfiguração encerrada");
      } else {
        fprintf(arq, "%s\n", palavra);
      }

    } while (strc != 0);
    break;

  case 2:
    printf("--- Bem vindo ao Jogo ---");
    break;
  }

  fclose(arq);
}
