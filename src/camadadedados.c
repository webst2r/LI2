#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024


ESTADO *inicializar_estado() {
    ESTADO *e1 = (ESTADO *) malloc(sizeof(ESTADO));
    e1->jogador_atual = 1;
    e1->num_jogadas = 0;
    COORDENADA *c1 = (COORDENADA *) malloc(sizeof(COORDENADA));
    c1->coluna = NULL;
    c1->linha = NULL;
    e -> ultima_jogada = c1;
    COORDENADA *c2 = (COORDENADA *) malloc(sizeof(COORDENADA));
    c2 ->coluna = NULL;
    c2 ->linha = NULL;
    e -> ultima_jogada = c2;
    JOGADA *j = (JOGADAS *) malloc(32*sizeof(JOGADA));
    j->jogador1=c1;
    j->jogador2=c2;
    e -> jogadas = j;
    CASA *h = (enum *) malloc(64*sizeof(enum));
    e -> enum = h;
    return e;
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
