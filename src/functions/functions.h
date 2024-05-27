#include <stdio.h>

//função para preenchimento da matriz e inicialização
void fillMatriz(char matriz[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matriz[i][j] = '?';
        }
    }
}

//função que verifica se a matriz ja esta preenchida por algum jogador
int verifyIsFilled(int l, int j, char matriz[3][3]){
    if(matriz[l - 1][j - 1] == 'X' || matriz[l - 1][j - 1] == 'O'){
        return 1;
    }
    return 0;
}

//função para realizar a jogada dos jogadores
void play(int l, int j, char matriz[3][3], int player){
    if(player == 0){
        matriz[l - 1][j - 1] = 'X';
    }else if(player == 1){
        matriz[l - 1][j - 1] = 'O';
    }
}

//função que troca o jogador
void changePlayer(int *player){
    switch (*player){
    case 0:
        *player = 1;
        break;
    case 1:
        *player = 0;
    default:
        break;
    }
}

//função que verifica se a um ganhador
int verifyWinner(char matriz[3][3]){
    for (int i = 0; i < 3; i++) {
    // Verifica a linha i
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != '?') {
            printf("Vencedor na linha %d: %c\n", i, matriz[i][0]);
            return 1;
        }
    
    //verificar colunas
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != '?') {
            printf("Vencedor na coluna %d: %c\n", i, matriz[0][i]);
            return 1;
        }
    
    //verificar diagonais
        if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != '?') {
            printf("Vencedor na diagonal principal: %c\n", matriz[0][0]);
            return 1;
        }

        if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != '?') {
            printf("Vencedor na diagonal secundária: %c\n", matriz[0][2]);
            return 1;
        }
    }
    return 0;
}

//função que reseta a matriz quando necessário
void reset(char matriz[3][3], int *counter){
    fillMatriz(matriz);
    *counter = 0;
}