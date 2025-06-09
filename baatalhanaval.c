#include <stdio.h>

#define TAM 10 //tabuleiro
#define TAM_NAVIO 3 //navio

int main (){
    
    int tabuleiro[TAM][TAM] = {0}; //tabuleiro

    int navioH[TAM_NAVIO] = {3, 3, 3}; // navio 1
    int navioV[TAM_NAVIO] = {3, 3, 3}; // navio 2

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 7; //posição inicial

    int valido = 1; // validação

    if (colunaH + TAM_NAVIO > TAM)
        valido = 0; //verificar navio horizontal
    
    if (linhaV + TAM_NAVIO > TAM)    
       valido = 0; //verificar navio vertical

    for (int i = 0; i < TAM_NAVIO && valido; i++) {
        if (tabuleiro [linhaH][colunaH + i] != 0 || tabuleiro[linhaV + i][colunaV] != 0) {
            valido = 0;
        }
    }  
    
    if (!valido) {
        printf("Erro: Posição inválida ou sobreposição de navios.\n");
        return 1;
    }
        
    for (int i = 0; i < TAM_NAVIO; i++){
        tabuleiro[linhaH][colunaH + i] = navioH[i];
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }    
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio): \n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d", tabuleiro[i][j]);
        }
    
    printf("\n");

    }



    return 0;
}