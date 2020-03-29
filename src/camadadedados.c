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

void str_to_coord (char jogador[256]) {
    int arr[];
    coluna(jogador[0], arr);
    linha(jogador[1]), arr;
}


void coluna(char jogador[256], int arr[]) {

    coluna_jogador = jogador[0];

    switch (coluna_jogador) {
        case a:
            arr[0] = 0;
            break;
        case b:
            arr[0] = 1;
            break;
        case c:
            arr[0] = 2;
            break;
        case d:
            arr[0] = 3;
            break;
        case e:
            arr[0] = 4;
            break;
        case f:
            arr[0] = 5;
            break;
        case g:
            arr[0] = 6;
            break;
        case h:
            arr[0] = 7;
            break;
    }
}

void linha(char jogador[256], int arr[]){
    linha_jogador = jogador[1];

    switch(linha_jogador){
        case 1:
            arr[1] = 0;
            break;
        case 2:
            arr[1] = 1;
            break;
        case 3:
            arr[1] = 2;
            break;
        case 4:
            arr[1] = 3;
            break;
        case 5:
            arr[1] = 4;
            break;
        case 6:
            arr[1] = 5;
            break;
        case 7:
            arr[1] = 6;
            break;
        case 8:
            arr[1] = 7;
            break;
    }
}

