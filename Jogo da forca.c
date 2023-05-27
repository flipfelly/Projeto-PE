#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *escolhePalavra(char nomeArquivo[], char escolha[]) {

  char linha[100][50];
  int contador = 0, i;
  FILE *arq;

  // Abre o arquivo
  if ((arq = fopen("Banco_palavras.txt", "r")) == NULL)
    puts("Erro na abertura do arquivo!\n\n");
  else {
    do {
      // Lê linha do arquivo
      fgets(escolha, 50, arq);

      // Retira as quebras esxtras de linhas
      for (i = 0; i < strlen(escolha); i++)
        if (escolha[i] == '\n')
          escolha[i] = '\0';

      // Testa se string não está vazia e armazena no vetor
      if (strcmp(escolha, "")) {
        strcpy(linha[contador], escolha);
        contador++;
      }
    } while (!feof(arq));
  }

  // Sorteia uma palavra pelo indice
  srand(time(NULL));
  i = rand() % contador;

  strcpy(escolha, linha[i]);
  return escolha;
}

// Função da intercafe do boneco(0 = não tem nada na forca, 1 = tem a cabeça...)
void forca(int estado) {
  if (estado == 0) {
    printf("\n-======="
           "\n||     |"
           "\n||"
           "\n||"
           "\n||"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 1) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||"
           "\n||"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 2) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||     |"
           "\n||"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 3) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||    /|"
           "\n||"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 4) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||    /|\\"
           "\n||"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 5) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||    /|\\"
           "\n||    /"
           "\n||"
           "\n||"
           "\n===");
  } else if (estado == 6) {
    printf("\n-======="
           "\n||     |"
           "\n||     0"
           "\n||    /|\\"
           "\n||    / \\"
           "\n||"
           "\n||  PERDEU!"
           "\n===");
  }
}

int main(void) {

  setlocale(LC_ALL, "Portuguese");
  char palavra[100];
  int opcao, strc;
  FILE *arq;
  printf("--- Bem-vindo ao Jogo da Forca ---");
  printf("\n\n ------ MENU ------ \n[ 1 ] - Configurar\n[ 2 ] - "
         "Jogar\n-------------------");
  printf("\n\nDigite uma das opções do menu: ");
  scanf("%d", &opcao);

  switch (opcao) {

  case 1:
    printf("\n\n--------------------------------");
    printf("\n Seja Bem-Vindo as Configurações ");

    arq = fopen("Banco_palavras.txt", "a");
    do {
      printf("\n--------------------------------\n\n[ Digite 'sair' para "
             "encerrar ]");

      printf("\nQual palavra deseja adicionar? ");
      scanf("%s", palavra); //recebe a palavra a ser gravada

      strc = strcmp(palavra, "sair"); //Compara a string e retorna um valor para o encerramento ou não.

      if (strc == 0) {
        //encerra a configuração
        printf("\n--------------------------------------\nObrigado por "
               "adicionar novas "
               "palavras!\n--------------------------------------"
               "\n\nConfiguração encerrada.");
      } else {

        fputs(palavra, arq); //escreve a palavra no arquivo
        fputs("\n", arq); // adiciona quebra de linha
      }

    } while (strc != 0);

    fclose(arq); // fecha o arquivo de escrita

    break;

  case 2:

    printf("\n--- Bem vindo ao Jogo ---\n ");

    char p[100], letra, escolha[100];

    FILE *arq_ler;

    arq_ler = fopen("Banco_palavras.txt", "r");//abre o arquivo com as palavras

    if ((arq_ler) == NULL) {
      printf("Erro para abrir arquivo");
      exit(1);
    } else {
      escolhePalavra("Banco_palavras.txt", escolha);// chama a funcção para escolha aleatoria de palavras
    }
    strcpy(p, escolhePalavra("Banco_palavras.txt", escolha));//Copia o valor para a palavra a ser utilizada

    printf("A palavra tem %lu caracteres.\n", strlen(p));

    char tela[100];
    strcpy(tela, p);

    for (int i = 0; i < strlen(tela); i++) {
      tela[i] = '_';
    }

    int erros = 0;
    while (1) {

      // imprime a forca
      forca(erros);

      // imprime os underlines para cada letra
      printf("\nAdvinhe:  ");
      for (int i = 0; i < strlen(tela); i++) {
        printf("%c ", tela[i]);
      }

      // recebe a letra
      printf("\n\nLetra: ");
      scanf(" %c", &letra);

      // verifica se a letra esta na palavra

      int possivel_erro = 1; // 1 = sim, 0 = não
      for (int i = 0; i < strlen(tela); i++) {

        if (letra == p[i]) { // a letra ta certa.
          tela[i] = letra;
          possivel_erro = 0;
        }
      }

      if (possivel_erro == 1) {
        erros++;
      }

      // verifica se o jogo acabou por erro
      if (erros == 6) { // perdeu
        forca(erros);
        break;
      }

      // verifica se tela == palavra, logo, jogo ganho.
      if (strcmp(tela, p) == 0) {
        printf("\nPalavra:  ");
        for (int i = 0; i < strlen(tela); i++) {
          printf("%c ", tela[i]);
        }
        printf("\nVocê Ganhou!\n\n");
        break;
      }
    }

    break;

  default:
    printf("Valor não encontrado!");
  }
}
