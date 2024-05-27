#include <stdio.h>

//função que exibe o jogo de forma legível ao usuário
void showGame(char matriz[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j == 1)
                 printf("| %c |",matriz[i][j]);
            else
            printf(" %c ",matriz[i][j]);
        }
        printf("\n");
        if (i == 2)
            break;
        printf("---|---|---\n");
    }
}