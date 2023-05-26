#include <stdio.h>
#include <string.h>
#include <locale.h>

// Função da intercafe do boneco(0 = não tem nada na forca, 1 = tem a cabeça...)
void forca(int estado){
    if (estado == 0){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    } else if(estado==1){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    } else if(estado==2){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||     |");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    }else if(estado==3){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||    /|");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    }else if(estado==4){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||    /|\\");
        printf("\n||");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    }else if(estado==5){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||    /|\\");
        printf("\n||    /");
        printf("\n||");
        printf("\n||");
        printf("\n===");
    }else if(estado==6){
        printf("\n-=======");
        printf("\n||     |");
        printf("\n||     0");
        printf("\n||    /|\\");
        printf("\n||    / \\");
        printf("\n||");
        printf("\n||  PERDEU!");
        printf("\n===");
    }
}

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    char palavra[100];
    int opcao, strc;
    FILE *arq;

    printf("--- Bem-vindo ao Jogo da Forca ---");
    printf("\n\n ------ MENU ------ \n[ 1 ] - Configurar\n[ 2 ] - Jogar\n-------------------");
    printf("\n\nDigite uma das opções do menu: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      printf("\n\n--------------------------------");
      printf("\n Seja Bem-Vindo as Configurações ");

      arq = fopen("Banco_palavras.txt", "w");
      do {
      printf("\n--------------------------------\n\n[ Digite 'sair' para encerrar ]");

      printf("\nQual palavra deseja adicionar? ");
      scanf("%s", palavra);

      strc = strcmp(palavra, "sair");

      if (strc == 0) {
        printf(
            "\n--------------------------------------\nObrigado por adicionar novas "
            "palavras!\n--------------------------------------\n\nConfiguração encerrada.");
      } else {
        fprintf(arq, "%s\n", palavra);
      }

      } while (strc != 0);

      fclose(arq);

      break;

    case 2 :

      printf("\n--- Bem vindo ao Jogo ---\n ");

      char p[100], letra;

      // Pegando a palavra
      printf("\nInforme a palavra: ");
      scanf("%s", p); // não pega espaço
      printf("\nA palavra foi escolhida!\n");
      printf("A palavra tem %lu caracteres.\n", strlen(p));

      char tela[100];
      strcpy(tela, p);

      for(int i=0; i < strlen(tela); i++){
        tela[i] = '_';
      }

      int erros = 0;
      while(1){

        //imprime a forca
        forca(erros);

        // imprime os underlines para cada letra
        printf("\nAdvinhe:  ");
        for(int i=0; i < strlen(tela); i++){
            printf("%c ", tela[i]);
        }

        // recebe a letra
        printf("\n\nLetra: ");
        scanf(" %c", &letra);

        //verifica se a letra esta na palavra

        int possivel_erro = 1; // 1 = sim, 0 = não
        for(int i=0; i < strlen(tela); i++){

          if(letra == p[i]){ //a letra ta certa.
              tela[i] = letra;
              possivel_erro=0;
          }
        }

        if(possivel_erro == 1){
          erros++;
        }

        // verifica se o jogo acabou por erro
        if(erros == 6){ //perdeu
          forca(erros);
          break;
        }

        // verifica se tela == palavra, logo, jogo ganho.
        if(strcmp(tela, p)==0){
          printf("\nPalavra:  ");
          for(int i=0; i < strlen(tela); i++){
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
