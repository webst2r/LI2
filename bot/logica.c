#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "listas.h"
#include "interface.h"
#include <math.h>
#include <time.h>
#define BUF_SIZE 1024


int ha_jogada_possivel (ESTADO *e, COORDENADA c) {
    COORDENADA ultima = c;
    int r = 0;
    int lin = ultima.linha, col = ultima.coluna;
    COORDENADA c1 = {lin + 1, col + 1},
            c2 = {lin,col + 1},
            c3 = {lin -1, col + 1},
            c4 = {lin + 1, col},
            c5 = {lin - 1, col},
            c6 = {lin + 1, col - 1},
            c7 = {lin, col - 1},
            c8 = {lin - 1, col - 1};
    COORDENADA vizinha[8] = {c1, c2, c3, c4, c5, c6, c7, c8};
    COORDENADA casa_livre;

    for(int i = 0; i < 8; i++) {
        casa_livre = vizinha[i];
        if (casa_livre.coluna >= 0 && casa_livre.coluna < 8 && casa_livre.linha >= 0 && casa_livre.linha < 8 && obter_estado_casa(e, casa_livre) == VAZIO)
            r = 1;
    }

    return r;
}


ERROS verifica_se_acabou (ESTADO *e, COORDENADA c) {
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    if (coluna == 7 && linha == 7) {
        maximiza_jogadas(e);
    } else if (coluna == 0 && linha == 0) {
        maximiza_jogadas(e);
    }
    else if(ha_jogada_possivel(e,e->ultima_jogada) == 0) {
        if (obter_jogador_atual(e) == 1) {
            printf("O Jogador 2 é o vencedor! Parabéns!\n");
        } else {
            printf("O Jogador 1 é o vencedor! Parabéns!\n");
        }
        maximiza_jogadas(e);
    }
    return OK;
}



ERROS jogar(ESTADO *e, COORDENADA c) {
    add_numerodecomandos(e);
    if(obter_numero_de_pos(e) != 50) { 
        atualiza_estado(e);
        e->numero_de_pos = 50;
    }

    if(jogada_valida(e,c) == OK) {
        printf("Jogar %d %d\n", c.coluna, c.linha);
        preta(e);
        e->tab[c.linha][c.coluna] = BRANCA;
        atualiza_jogadas(e,c);
        atualiza_num_jogadas(e);
        atualiza_jogador_atual(e);
        prompt(e);
        printf("\n");
        verifica_se_acabou(e,c);
        return OK;
    } else return JOGADA_INVALIDA;
}

ERROS check_movimentos(ESTADO *estado,COORDENADA c) {
    int coluna1, coluna2, linha1, linha2;
    coluna1 = estado->ultima_jogada.coluna;
    linha1 = estado->ultima_jogada.linha;
    coluna2 = c.coluna;
    linha2 = c.linha;

    if ((coluna2 == coluna1 + 1 || coluna2 == coluna1 - 1 || coluna2 == coluna1) && (linha2 == linha1 + 1 || linha2 == linha1 - 1 || linha2 == linha1))
        return OK;

    else return JOGADA_INVALIDA;
}

ERROS casa_livre(ESTADO *e, COORDENADA c) {
    ERROS erro;
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    if((coluna < 8) && (linha < 8)) {
        if (obter_estado_casa(e, c) == VAZIO || obter_estado_casa(e, c) == UM || obter_estado_casa(e, c) == DOIS) {
            erro = OK;
        }
        else erro = JOGADA_INVALIDA; 
    } else erro = COORDENADA_INVALIDA; 
    return erro;
}

ERROS jogada_valida(ESTADO *e, COORDENADA c) {
    if(c.linha < 0 || c.linha > 7) return JOGADA_INVALIDA;
    if(c.coluna < 0 || c.coluna > 7) return JOGADA_INVALIDA;
    if(casa_livre(e,c) == OK) 
        return check_movimentos(e,c);
    else return JOGADA_INVALIDA;
}


