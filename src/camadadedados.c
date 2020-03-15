#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
#define ARRAY_SIZE 8

ESTADO *inicializar_estado() {
    ESTADO e;
    CASA arr;
    e = (ESTADO){.tab = {imprime_tabuleiro(arr[ARRAY_SIZE])},
                 .ultima_jogada = {4,3},
                 .jogadas = {},
                 .num_jogadas = 0,
                 .jogador_atual = 1};
    return &e;
}

int imprime_tabuleiro (CASA *arr) {
    CASA arr1[8];
    CASA arr2[8];
    CASA arr3[8];
    CASA arr4[8];
    CASA arr5[8];
    CASA arr6[8];
    CASA arr7[8];
    CASA arr8[8];
    for(int coluna = 0; coluna < 8; coluna++) {
        arr1[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 8; coluna++) {
        arr2[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 8; coluna++) {
        arr3[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 4; coluna++) {
        arr4[coluna] = VAZIO;
    } arr4[4] = BRANCA;
    arr4[5] = VAZIO;
    arr4[6] = VAZIO;
    arr4[7] = VAZIO;
    for(int coluna = 0; coluna < 8; coluna++) {
        arr5[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 8; coluna++) {
        arr6[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 8; coluna++) {
        arr7[coluna] = VAZIO;
    } for(int coluna = 0; coluna < 8; coluna++) {
        arr8[coluna] = VAZIO;
    }
    arr[0] = *arr1;
    arr[1] = *arr2;
    arr[2] = *arr3;
    arr[3] = *arr4;
    arr[4] = *arr5;
    arr[5] = *arr6;
    arr[6] = *arr7;
    arr[7] = *arr8;
}
/* ANTIGA DEFINIÇÃO DA imprime_tabuleiro
    for(int linha = 0; linha < 3; linha++) {
        for(int coluna = 0; coluna < 8; coluna++) {
            arr[coluna] = VAZIO;
        }
    } for(int linha = 3; linha < 4; linha++) {
         for(int coluna = 0; coluna < 4; coluna++) {
             arr[coluna] = VAZIO;
         } arr[4] = BRANCA;
         arr[5] = VAZIO;
         arr[6] = VAZIO;
         arr[7] = VAZIO;
    } for(int linha = 4; linha < 8; linha++) {
         for(int coluna = 0; coluna < 8; coluna++) {
             arr[coluna] = VAZIO;
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