#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024


ESTADO *inicializar_estado() {
    ESTADO e;
    e = (ESTADO){.tab = imprime_tabuleiro(arr[8])
                          .ultima_jogada = {4,3},
                          .jogadas = {},
                          .num_jogadas = 0,
                          .jogador_atual = 1};
    return &e;
}

void imprime_tabuleiro (CASA *arr) {
    for(int linha = 0; linha < 3; linha++) {
        for(int coluna = 0; coluna < 7; coluna++) {
            arr[coluna] = VAZIO;
        }
    } for(int linha = 3; linha < 4; linha++) {
         for(int coluna = 0; coluna < 4; coluna++) {
             arr[coluna] = VAZIO;
         } arr[4] = BRANCA;
         arr[5] = VAZIO;
         arr[6] = VAZIO;
         arr[7] = VAZIO;
    } for(int linha = 4; linha < 7; linha++) {
         for(int coluna = 0; coluna < 7; coluna++) {
             arr[coluna] = VAZIO;
        }
}

int obter_jogador_atual(ESTADO *estado) {
    int play;
    play = estado->jogadorAtual;
    return play;
}

int obter_numero_de_jogadas(ESTADO *estado) {
    int n_jogadas;
    jogadas = estado->numeroJogadas;
    return n_jogadas;
}

CASA obter_estado_casa(ESTADO *estado, COORDENADA c) {
     CASA estadocasa;
     estadocasa = estado->tab[c.linha][c.coluna];
     return estadocasa;
}