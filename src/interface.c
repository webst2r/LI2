#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#define DEBUG
#define BUF_SIZE 1024

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];


    e->num_comando++;
    printf("# %02d PL%d (%d)> ", e->num_comando, e->jogador_atual,e->num_jogadas);
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        if ((erro = jogar(e, coord)) == OK)
            mostrar_tabuleiro(stdout, e);
        else
            print_erro(erro);
    }
    if (strcmp(linha, "Q\n") == 0)
        return 0;

    if(sscanf(linha, "gr %s", nome_ficheiro) == 1) {
        gravar(e,nome_ficheiro);
    }

    if(sscanf(linha, "ler %s", filename) == 1) {
        ERROS erro;
        if((erro = ler(e,nome_ficheiro)) == OK)
            mostrar_tabuleiro(stdout, e);
        else
    }
    return 1;
}
*/


void mostrar_tabuleiro(ESTADO *e) {
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++) {
            if (k == 7 && i == 0)
                printf("2");
            else if (i == 7 && k == 0)
                printf("1");
            else {
                switch (e->tab[k][i])
                {
                    case PRETA:
                        putchar(PRETA);
                        break;
                    case VAZIO:
                        putchar(VAZIO);
                        break;
                    case BRANCA:
                        putchar(BRANCA);
                        break;
                }
            }
        }
        printf("\n Efetua a tua jogada");
    }
}

//printf(obter_casa(state, i, k) == VAZIO) ? "." : (obter_casa(state, i, k) == BRANCA) ? "*" : "#" );

