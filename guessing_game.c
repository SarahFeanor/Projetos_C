
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
    
    printf("  VAMOS COMEÇAR?\n");
    printf("\n");
  
    
    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    
    int nivel;
    printf("  Qual nível de dificuldade?\n");
    printf("\n");
    printf("  (1) Fácil (2) Médio (3) Difícil\n\n");
    printf("  Escolha: ");
    scanf("  %d", &nivel);

    int numerodetentativas;
    
    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;

        default:
            numerodetentativas = 6;
            break;
            
    }
    
    for(int i = 1; i <= numerodetentativas; i++) {

        printf("_________________________________________\n");
        printf("\n");
        printf("  Tentativa %d\n", tentativas);
        printf("  Qual é o seu chute? ");
        scanf("  %d", &chute);

        if(chute < 0) {
            printf("  Você não pode chutar números negativos!\n");
            continue;
        }
        
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }

        else if(maior) {
            printf("  Seu chute foi MAIOR que o número secreto\n");
        }

        else {
            printf("  Seu chute foi MENOR que o número secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;

    }
    
        printf("  Fim de jogo!\n");
    
        if(acertou) {
            printf("  ************************************\n");
            printf("  * BEM VINDO AO JOGO DE ADIVINHAÇÃO *\n");
            printf("  ************************************\n");
            printf("\n");
            printf("  Você acertou em %d tentativas!\n", tentativas);
            printf("  Total de pontos: %.1f\n", pontos);
            
        } else {
            printf("  Você perdeu! Tente de novo!\n");
    }

    
}
    

