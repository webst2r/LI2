#include "camadadedados.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO*)malloc(sizeof(ESTADO));
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

void ler_aux(ESTADO *e, FILE *fp) {
    COORDENADA c1, c2;
    char buffer[BUF_SIZE];
    int line = 0;
    int w = 0;
    e->num_jogadas = 0;
    while (w < 32) {
        e->jogadas[w].jogador1.coluna = 0;
        e->jogadas[w].jogador1.linha = 0;
        e->jogadas[w].jogador2.coluna = 0;
        e->jogadas[w].jogador2.linha = 0;
        w++;
    }
    int linha2, coluna2;
    for (linha2 = 0; linha2 < 8; linha2++) {
        for (coluna2 = 0; coluna2 < 8; coluna2++) {
            if (linha2 == 4 && coluna2 == 4)
                e->tab[linha2][coluna2] = BRANCA;
            else
                e->tab[linha2][coluna2] = VAZIO;
        }
    }
    e->tab[0][0] = UM;
    e->tab[7][7] = DOIS;
    while (fgets(buffer, BUF_SIZE, fp) != NULL) {
        if (line <= 7) {
            for (int j = 0; j <= 7; j++) {
                if (buffer[j] == '.') e->tab[7 - line][j] = VAZIO;
                else if (buffer[j] == '*') e->tab[7 - line][j] = BRANCA;
                else if (buffer[j] == '#') e->tab[7 - line][j] = PRETA;
            }
        } else {
            if (line >= 9) {
                if (buffer[4] >= 'a' && buffer[4] <= 'h' && buffer[5] >= '1' && buffer[5] <= '8') {
                    e->jogador_atual = 2;
                    c1.linha = buffer[5] - '1';
                    c1.coluna = buffer[4] - 'a';
                    e->jogadas[e->num_jogadas].jogador1 = c1;
                    e->ultima_jogada = c1;
                }
                if (buffer[7] >= 'a' && buffer[7] <= 'h' && buffer[8] >= '1' && buffer[8] <= '8') {
                    e->jogador_atual = 1;
                    c2.linha = buffer[8] - '1';
                    c2.coluna = buffer[7] - 'a';
                    e->jogadas[e->num_jogadas].jogador2 = c2;
                    e->ultima_jogada = c2;
                    e->num_jogadas++;
                }
            }
        }
        line++;
    }
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

void add_numerodecomandos(ESTADO *e) {
    e->numeroComandos++;
}

void printMovs_aux(ESTADO *e, FILE *fp) {
    // so serve quando i < 9
    for (int i = 0; i < obter_numero_de_jogadas(e) + 1; i++) {
        if (i < 9) {
            if (e->jogadas[i].jogador1.linha != 0 || e->jogadas[i].jogador1.coluna != 0) {
                fprintf(fp, "0%d: %c%d", i + 1, e->jogadas[i].jogador1.coluna + 'a', e->jogadas[i].jogador1.linha + 1); // FIXME - ERRO DE LEITURA EXTRA DE UM MOVIMENTO ENCONTRA-SE NESTE PRIMEIRO IF
            }
            if (e->jogadas[i].jogador2.linha != 0 || e->jogadas[i].jogador2.coluna != 0)
                fprintf(fp, " %c%d\n", e->jogadas[i].jogador2.coluna + 'a', e->jogadas[i].jogador2.linha + 1);

            if ((e->jogadas[i].jogador1.linha != 0 || e->jogadas[i].jogador1.coluna != 0)&&
                (e->jogadas[i].jogador2.coluna == 0 && e->jogadas[i].jogador2.linha == 0)) {
                fprintf(fp, "\n");
            }
        } else {
            if (e->jogadas[i].jogador1.linha != 0 || e->jogadas[i].jogador1.coluna != 0)
                fprintf(fp, "%d: %c%d", i + 1, e->jogadas[i].jogador1.coluna + 'a', e->jogadas[i].jogador1.linha + 1);

            if (e->jogadas[i].jogador2.linha != 0 || e->jogadas[i].jogador2.coluna != 0)
                fprintf(fp, " %c%d\n", e->jogadas[i].jogador2.coluna + 'a', e->jogadas[i].jogador2.linha + 1);
            else
                fprintf(fp, "\n");
        }
    }
}





/*
void add_numerodejogadas(ESTADO *e) {
    e->num_jogadas++;
}

void armazenar_jogada(ESTADO *e, COORDENADA c) {
    int i = 0;
    if(e->jogador_atual == 1) e->jogadas[i].jogador1 = c;
    else if(e->jogador_atual == 2) {
        e->jogadas[i].jogador2 = c;
        e->num_jogadas++;
    }
}
*/

