#include <stdio.h>
#include "./functions/functions.h"
#include "./screen/screen.h"
#include "./models/player.h"


int main(void){
    char matriz[3][3];
    int counter = 0, timeFromP = 0, end = 0,  nPlayers;
    
    fillMatriz(matriz);
    printf("|-------------------------------------------|\n");
    printf("| Olá bem vindo ao jogo da velha jogador!!! |\n");
    printf("|-------------------------------------------|\n\n");  
    printf(" Quantos jogadores irão participar:\n 1 or 2 ?\n");
    scanf("%d", &nPlayers);
    struct player players[nPlayers];

    for(int i = 0; i < nPlayers; i++){
        printf("Digite o nome do jogador %d:\n", i+1);
        scanf("%s", players[i].name);
        players[i].points = 0;
    }

    do{
        int l, j;
        char continuar;

        showGame(matriz);
        printf("\nVez de %s.\nDigite 2 numeros de 1 a 3 referente a linha e coluna que deseja preencher:\n", 
        players[timeFromP].name);
        scanf("%d %d", &l, &j);
        if(!verifyIsFilled(l, j, matriz)){
            play(l, j, matriz, timeFromP);
            if(verifyWinner(matriz)){
                showGame(matriz);
                players[timeFromP].points++;
                printf("Parabéns %s, você venceu!!!\nPontos - %d\n", 
                players[timeFromP].name,
                players[timeFromP].points
                );
                printf("Continuar ? [s] [n]");
                scanf(" %c", &continuar);
                if(continuar == 'n'){
                    end = 1;
                } else reset(matriz, &counter);
            }
            changePlayer(&timeFromP);
            counter++;
        }else printf("\nNão é possivel local preenchido\n");
        
        
        if(counter == 9){
            printf("Empate\n");
            printf("Continuar ? [s] [n]: ");
            scanf(" %c", &continuar);
            if(continuar == 'n'){
                end = 1;
            }
            else reset(matriz, &counter);
        }
    }while(!end);

    printf("Fim de jogo\n");

    return 0;
}