#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO*)malloc(sizeof(ESTADO));
    CASA arr[8][8];
    *e = (ESTADO){.tab = {{VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
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
            .jogador_atual = 1,
            .numeroComandos = 0};
    return e;
}
//Maneira alternativa de imprimir o tabuleiro inicial.

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

int obter_jogador_atual(ESTADO *estado) {
    int player;
    player = estado->jogador_atual;
    return player;
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

void armazenar_jogada(ESTADO *e, COORDENADA c) {

    if(e->jogador_atual == 1) e->jogadas[i].jogador1 = c;
    else if(e->jogador_atual == 2) {
        e->jogadas[i].jogador2 = c;
        e->num_jogadas++;
    }
}




