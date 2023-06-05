#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de aleatoriedade na escolha de palavras
char *escolhePalavra(char nomeArquivo[], char escolha[]) {

  char linha[100][50];
  int contador = 0, i;
  FILE *arq;

  // Abre o arquivo
  if ((arq = fopen(nomeArquivo, "r")) == NULL)
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
  char palavra[100], resp, repeat;
  int opcao, strc, opcao2;
  FILE *arq;

  do{
  printf("\n--- Bem-vindo ao Jogo da Forca ---");
  printf("\n\n ------ MENU ------ \n\n [ 1 ] - Adjetivos \n [ 2 ] - Objetos \n [ 3 ] - Animais \n\n ------------------\n\n [ 4 ] - Configurar"); 
  printf("\n\nDigite uma das opções do menu: ");
  scanf("%d", &opcao);

  switch (opcao) {

  case 1:

    printf("\n--- INÍCIO DE JOGO ---\n\n ");

    char p[100], letra, escolha[100];

    FILE *arq_ler;

    arq_ler = fopen("banco_adjetivos.txt", "r");//abre o arquivo com as palavras

    if ((arq_ler) == NULL) {
      printf("Erro para abrir arquivo");
      exit(1);
    } else {
      escolhePalavra("banco_adjetivos.txt", escolha);// chama a funcção para escolha aleatoria de palavras
    }
    strcpy(p, escolhePalavra("banco_adjetivos.txt", escolha));//Copia o valor para a palavra a ser utilizada

    printf("\nA palavra tem %lu caracteres.\n", strlen(p));

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
         printf("\n PALAVRA: %s", p);
        break;
      }

      // verifica se tela == palavra, logo, jogo ganho.
      if (strcmp(tela, p) == 0) {
        printf("\nPalavra:  ");
        for (int i = 0; i < strlen(tela); i++) {
          printf("%c ", tela[i]);
        }
      printf("\n\n    *  *  *\n!!! VITÓRIA !!!\n    *  *  *\n");
        break;
      }
    }
  fclose(arq_ler);
  break;
    
  case 2:

    printf("\n--- INÍCIO DE JOGO ---\n\n ");

    char p2[100], letra2, escolha2[100];

    FILE *arq_ler2;

    arq_ler2 = fopen("banco_objetos.txt", "r");//abre o arquivo com as palavras

    if ((arq_ler2) == NULL) {
      printf("Erro para abrir arquivo");
      exit(1);
    } else {
      escolhePalavra("banco_objetos.txt", escolha2);// chama a funcção para escolha aleatoria de palavras
    }
    strcpy(p2, escolhePalavra("banco_objetos.txt", escolha2));//Copia o valor para a palavra a ser utilizada

    printf("A palavra tem %lu caracteres.\n", strlen(p2));

    char tela2[100];
    strcpy(tela2, p2);

    for (int i = 0; i < strlen(tela2); i++) {
      tela2[i] = '_';
    }

    int erros2 = 0;
    while (1) {

      // imprime a forca
      forca(erros2);

      // imprime os underlines para cada letra
      printf("\nAdvinhe:  ");
      for (int i = 0; i < strlen(tela2); i++) {
        printf("%c ", tela2[i]);
      }

      // recebe a letra
      printf("\n\nLetra: ");
      scanf(" %c", &letra2);

      // verifica se a letra esta na palavra

      int possivel_erro2 = 1; // 1 = sim, 0 = não
      for (int i = 0; i < strlen(tela2); i++) {

        if (letra2 == p2[i]) { // a letra ta certa.
          tela2[i] = letra2;
          possivel_erro2 = 0;
        }
      }

      if (possivel_erro2 == 1) {
        erros2++;
      }

      // verifica se o jogo acabou por erro
      if (erros2 == 6) { // perdeu
        forca(erros2);
         printf("\n PALAVRA: %s", p2);
        break;
      }

      // verifica se tela == palavra, logo, jogo ganho.
      if (strcmp(tela2, p2) == 0) {
        printf("\nPalavra:  ");
        for (int i = 0; i < strlen(tela2); i++) {
          printf("%c ", tela2[i]);
        }
        printf("\n\n    *  *  *\n!!! VITÓRIA !!!\n    *  *  *\n");
        break;
      }
    }
    fclose(arq_ler2);
    break;
    
    case 3:

    printf("\n--- INÍCIO DE JOGO ---\n\n ");

    char p3[100], letra3, escolha3[100];

    FILE *arq_ler3;

    arq_ler3 = fopen("banco_objetos.txt", "r");//abre o arquivo com as palavras

    if ((arq_ler3) == NULL) {
      printf("Erro para abrir arquivo");
      exit(1);
    } else {
      escolhePalavra("banco_animais.txt", escolha3);// chama a funcção para escolha aleatoria de palavras
    }
    strcpy(p3, escolhePalavra("banco_animais.txt", escolha3));//Copia o valor para a palavra a ser utilizada

    printf("A palavra tem %lu caracteres.\n", strlen(p3));

    char tela3[100];
    strcpy(tela3, p3);

    for (int i = 0; i < strlen(tela3); i++) {
      tela3[i] = '_';
    }

    int erros3 = 0;
    while (1) {

      // imprime a forca
      forca(erros3);

      // imprime os underlines para cada letra
      printf("\nAdvinhe:  ");
      for (int i = 0; i < strlen(tela3); i++) {
        printf("%c ", tela3[i]);
      }

      // recebe a letra
      printf("\n\nLetra: ");
      scanf(" %c", &letra3);

      // verifica se a letra esta na palavra

      int possivel_erro3 = 1; // 1 = sim, 0 = não
      for (int i = 0; i < strlen(tela3); i++) {

        if (letra3 == p3[i]) { // a letra ta certa.
          tela3[i] = letra3;
          possivel_erro3 = 0;
        }
      }

      if (possivel_erro3 == 1) {
        erros3++;
      }

      // verifica se o jogo acabou por erro
      if (erros3 == 6) { // perdeu
        forca(erros3);
        printf("\n PALAVRA: %s", p3);
        break;
      }

      // verifica se tela == palavra, logo, jogo ganho.
      if (strcmp(tela3, p3) == 0) {
        printf("\nPalavra:  ");
        for (int i = 0; i < strlen(tela3); i++) {
          printf("%c ", tela3[i]);
        }
      printf("\n\n    *  *  *\n!!! VITÓRIA !!!\n    *  *  *\n");
        break;
      }}
       fclose(arq_ler3);
    break;
    
    case 4:

      
    printf("\n\n--------------------------------\n Seja Bem-Vindo as Configurações\n-------------------------------- ");
  
  do{
    printf("\n\n ------ MENU ------ \n*opções de configuração*\n\n [ 1 ] - Adjetivos \n [ 2 ] - Objetos \n [ 3 ] - Animais"); 
    printf("\n -    -    -    - \n Digite uma das opções para adicionar palavras: ");
    scanf("%d", &opcao2);

    switch(opcao2){

      case 1:

      arq = fopen("banco_adjetivos.txt","a");// "a" concatena os dados no final do arquivo
        
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
      
       arq = fopen("banco_objetos.txt","a");// "a" concatena os dados no final do arquivo
        
      do {
      printf("\n--------------------------------\n\n[ Digite 'sair' para "
             "encerrar ]");

      printf("\nQual palavra deseja adicionar? ");
      scanf("%s", palavra); //recebe a palavra a ser gravada

      strc = strcmp(palavra, "sair"); //Compara a string e retorna um valor para o encerramento ou não.

      if (strc == 0) {
        //encerra a configuração
        printf("\n--------------------------------------\nObrigado poradicionar novas palavras!\n--------------------------------------\n\nConfiguração encerrada.");
      } else {

        fputs(palavra, arq); //escreve a palavra no arquivo
        fputs("\n", arq); // adiciona quebra de linha
      }

    } while (strc != 0);

    fclose(arq); // fecha o arquivo de escrita

    break;

    case 3:
       arq = fopen("banco_animais.txt","a");// "a" concatena os dados no final do arquivo
        
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

      default:

      printf("* Valor não encontrado *");
      printf("Deseja digitar novamente (s ou n)?");
      scanf(" %c", &resp);

    }
  }while(resp=='s');
      
   
  }//switch case 1

  int strc1;
    
  printf("\n-----------------------------------\nDeseja Jogar novamente (s ou n) ?");
  scanf(" %c", &repeat);

  printf("\n-----------------------------------");
  if (repeat =='n'){
    printf("\n-----------------------------------\nMUITO OBRIGADO POR TER JOGADO!\n-----------------------------------");
    break;
  }

  }while(repeat =='s');   

  
}
