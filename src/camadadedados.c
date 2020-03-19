#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    ESTADO e;
    CASA arr[8][8];
    e = (ESTADO){.tab = {{VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, BRANCA, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                         {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO}},
                 .ultima_jogada = {4,3},
                 .jogadas = {},
                 .num_jogadas = 0,
                 .jogador_atual = 1};
    return &e;
}
/*
int imprime_tabuleiro(CASA arr[8][8]) {
    for (int linha = 0; linha < 3; linha++) {
        for(int coluna = 0; coluna < 8; coluna++) {
            arr[linha][coluna] = VAZIO;
        }
    } imprime_linha_3(arr);
    for(int linha = 4; linha < 8; linha++) {
        for(int coluna = 0; coluna < 8; coluna++) {
            arr[linha][coluna] = VAZIO;
        }
    }
}


int imprime_linha_3(CASA arr[8][8]) {
    int coluna;
    for (coluna = 0; coluna < 4; coluna++) {
        arr[3][coluna] = VAZIO;
    } arr[3][4] = BRANCA;
    for (coluna = 5; coluna < 8; coluna++) {
        arr[3][coluna] = VAZIO;
    }
}
*/
int obter_jogador_atual(ESTADO *estado) {
    int play;
    play = estado->jogador_atual;
    return play;
}

int obter_numero_de_jogadas(ESTADO *estado) {
    int n_jogadas;
    n_jogadas = estado->num_jogadas;
    return n_jogadas;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c) {
     CASA estadocasa;
     estadocasa = estado->tab[c.linha][c.coluna];
     return estadocasa;
}