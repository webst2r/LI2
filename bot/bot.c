#include "camadadedados.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bot.h"
#include "listas.h"
#include "logica.h"

int verifica_se_acabou_bot(ESTADO *e, COORDENADA c) {
    int coluna, linha;
    int r = 0;
    coluna = c.coluna;
    linha = c.linha;

    if(obter_jogador_atual(e) == 2 && coluna == 7 && linha == 7) {
        r = 1;
    } else if(obter_jogador_atual(e) == 1 && coluna == 0 && linha == 0) {
        r = 1;
    }

    if (ha_jogada_possivel(e,c) == 0) {
        r = 1;
    }
    return r;
}

COORDENADA fim_de_jogo(ESTADO *e, LISTA l){
    preta(e);
    COORDENADA c;
    CASA antiga;
    c.linha = 100;
    c.coluna = 100;

    while(l != NULL){
        COORDENADA *teste = (COORDENADA *) l->valor;
        antiga = e->tab[teste -> linha][teste -> coluna];
        e->tab[teste -> linha][teste -> coluna] = BRANCA;

        if(verifica_se_acabou_bot(e,*teste) == 1){
            c = *teste;
        }
        e->tab[teste -> linha][teste -> coluna] = antiga;
        l = l->prox;
    }
    return c;
}

LISTA vizinhas(ESTADO *e, LISTA l) {

    COORDENADA ultima = e->ultima_jogada;
    int lin = ultima.linha, col = ultima.coluna;

    COORDENADA *c1 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c2 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c3 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c4 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c5 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c6 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c7 = (COORDENADA *) malloc(sizeof(COORDENADA));
    COORDENADA *c8 = (COORDENADA *) malloc(sizeof(COORDENADA));

    c1->linha = lin + 1;
    c1->coluna = col + 1;
    c2->linha = lin;
    c2->coluna = col + 1;
    c3->linha = lin - 1;
    c3->coluna = col + 1;
    c4->linha = lin + 1;
    c4->coluna = col;
    c5->linha = lin - 1;
    c5->coluna = col;
    c6->linha = lin + 1;
    c6->coluna = col - 1;
    c7->linha = lin;
    c7->coluna = col - 1;
    c8->linha = lin - 1;
    c8->coluna = col - 1;

    COORDENADA *vizinha[8] = {c1, c2, c3, c4, c5, c6, c7, c8};

    for (int i = 0; i < 8; i++) {
        if (jogada_valida(e, *vizinha[i]) == OK) {
            l = insere_cabeca(l, vizinha[i]);
        }
    }
    return l;
}

float distance (COORDENADA * c, int jogador) {
    COORDENADA fim;

    if(jogador == 1) {
        fim.coluna = 0;
        fim.linha = 0;
    } else {
        fim.coluna = 7;
        fim.linha = 7;
    }
    int x1 = fim.linha;
    int x2 = c -> linha;
    int y1 = fim.coluna;
    int y2 = c -> coluna;
    int x = x1 - x2;
    int y = y1 - y2;
    float distancia;
    distancia = sqrt(pow(x,2) + pow(y,2));

    return distancia;
}

COORDENADA *euclidiana (ESTADO *e) {
    LISTA l;
    l = criar_lista();
    l = vizinhas(e, l);
    COORDENADA *melhor;
    COORDENADA d = fim_de_jogo(e,l);
    melhor = malloc(sizeof(COORDENADA));

    if (d.linha != 100 && d.coluna != 100) {
        *melhor = d;
    } else {
        COORDENADA *melhor_jogada = malloc(sizeof(COORDENADA));
        COORDENADA *mj_temp = malloc(sizeof(COORDENADA));
        melhor_jogada = devolve_cabeca(l);

        l = proximo(l);
        int jogador = obter_jogador_atual(e);
        float distancia = distance(melhor_jogada, jogador);
        float dist_temporaria;

        while (lista_esta_vazia(l) != 1) {
            mj_temp = devolve_cabeca(l);
            dist_temporaria = distance(mj_temp, jogador);
            if (dist_temporaria < distancia) {
                melhor_jogada = mj_temp;
                distancia = dist_temporaria;
            }
            l = proximo(l);
        }
        melhor = melhor_jogada;
    }
    return melhor;
}

void bot2 (ESTADO *e){

    if(obter_numero_de_pos(e) != 100) {
        atualiza_estado(e);
        e->numero_de_pos = 100;
    }

    COORDENADA c = *euclidiana(e);
    jogar(e,c);
}
