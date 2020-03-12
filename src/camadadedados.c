
#include "camadadedados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;


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


