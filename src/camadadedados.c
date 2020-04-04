#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO*)malloc(sizeof(ESTADO));
    CASA arr[8][8];
    *e = (ESTADO){.tab = {{UM, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, BRANCA, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
                          {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, DOIS}},
            .ultima_jogada = {4,4},
            .jogadas = {},
            .num_jogadas = 0,
            .jogador_atual = 1,
            .numeroComandos = 0};
    return e;
}
//Maneira alternativa de imprimir o tabuleiro inicial.
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

void atualiza_jogadas(ESTADO *e, COORDENADA c){
    if(obter_jogador_atual(e) == 1){
        e->jogadas[obter_numero_de_jogadas(e)].jogador1 = c;
    } else
        e->jogadas[obter_numero_de_jogadas(e)].jogador2 = c;
}



int atualiza_jogador_atual(ESTADO *e) {
    if(obter_jogador_atual(e) == 1) {
        return 2;
    } else return 1;
}

int obter_numero_comandos(ESTADO *e) {
    int num_com = 0;
    num_com = e->numeroComandos;
    return num_com;
}

void maximiza_jogadas(ESTADO *e){
     e->num_jogadas = 32;
}

int atualiza_num_jogadas(ESTADO *e) {
    int n = obter_numero_de_jogadas(e);
    if(obter_jogador_atual(e) == 2) {
        n++;
    }
    return n;
}

void add_numerodecomandos(ESTADO *e){
    e->numeroComandos++;
}

void armazenar_jogada(ESTADO *e, COORDENADA c) {
    int i = 0;
    if(e->jogador_atual == 1) e->jogadas[i].jogador1 = c;
    else if(e->jogador_atual == 2) {
        e->jogadas[i].jogador2 = c;
        e->num_jogadas++;
    }
}


