#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#define BUF_SIZE 1024

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}


void mostrar_tabuleiro(ESTADO estado) {
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++) {
            if (k == 7 && i == 0)
                printf("2");
            else if (i == 7 && k == 0)
                printf("1");
            else {
                switch (estado->tab[k][i])
                {
                    case PRETA:
                        printf("#");
                        break;
                    case VAZIO:
                        printf(".");
                        break;
                    case BRANCA:
                        printf("*");
                        break;
                }
            }
        }
        putchar("\n Efetua a tua jogada");
    }
}

//printf(obter_casa(state, i, k) == VAZIO) ? "." : (obter_casa(state, i, k) == BRANCA) ? "*" : "#" );