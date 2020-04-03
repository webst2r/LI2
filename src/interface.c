#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "camadadedados.h"
#include "logica.h"
#define BUF_SIZE 1024

void printMovs(ESTADO *e, FILE *pFile);

#include <string.h>



void print_erro(ERROS erro) {
    if (erro == JOGADA_INVALIDA) {
        printf("A jogada é inválida.\n");
    } else {
        if (erro == COORDENADA_INVALIDA) {
            printf("A coordenada é inválida.\n");
        } else {
            if (erro == ERRO_LER_TAB) {
                printf("Ocorreu um erro ao ler o tabuleiro.\n");
            } else printf("Ocorreu um erro ao abrir o ficheiro.\n");
        }
    }
}

ERROS gravar(ESTADO *e, char *nome_ficheiro) { // FIXME - IMPLEMENTAR ERRO
    FILE *fp = fopen(nome_ficheiro, "w");

    if(fp == NULL){
        printf("Não é possivel criar o ficheiro.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 7; i >= 0; i--){

        for (int k = 0; k < 8; k++) {
                switch (e->tab[i][k])
                {
                    case DOIS:
                        fprintf(fp,"2");
                        break;
                    case UM:
                        fprintf(fp,"1");
                        break;
                    case PRETA:
                        fprintf(fp,"#");
                        break;
                    case VAZIO:
                        fprintf(fp, ".");
                        break;
                    case BRANCA:
                        fprintf(fp, "*");
                        break;
                }
            }

        fprintf(fp, "\n");   }

    fprintf(fp,"\n");
    printMovs(e,fp);
    fclose(fp); /* Fechar ficheiro para salvar a informação */
    printf("Ficheiro criado e salvado com sucesso.  \n");
    return 0;
}

void printMovs(ESTADO *e, FILE *fp) {
    // so serve quando i < 9
    for (int i = 0; i < obter_numero_de_jogadas(e) + 1; i++) {
        if (i < 9) {
            if (e->jogadas[i].jogador1.linha != 0 || e->jogadas[i].jogador1.coluna != 0) {
                fprintf(fp, "0%d: %c%d", i + 1, e->jogadas[i].jogador1.coluna + 'a', e->jogadas[i].jogador1.linha + 1);
            }
            if (e->jogadas[i].jogador2.linha != 0 || e->jogadas[i].jogador2.coluna != 0)
                fprintf(fp, " %c%d\n", e->jogadas[i].jogador2.coluna + 'a', e->jogadas[i].jogador2.linha + 1);


            if (e->jogadas[i].jogador1.linha != 0 && e->jogadas[i].jogador1.coluna != 0 &&
                e->jogadas[i].jogador2.coluna == 0 && e->jogadas[i].jogador2.linha == 0) {
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

ERROS ler(ESTADO *e, char *nome_ficheiro) {
    ERROS erro;
    COORDENADA c1, c2;
    char buffer[BUF_SIZE];
    int line = 0;
    int w = 0;
    char linha[BUF_SIZE];

    FILE *fp;
    fp = fopen(nome_ficheiro, "r");
    if (fp == NULL) {
        perror("Ao ler");
        return ERRO_ABRIR_FICHEIRO;
    }

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
        mostrar_tabuleiro(stdout, e);
        printMovs(e, stdout);
        fclose(fp);
        return OK;
    }


void set_casa(ESTADO *e, COORDENADA c, CASA valor) {       // COLOCA O VALOR NA CASA COM COORDENADA por miudos COORDENADA -> VALOR
    e->tab[c.linha][c.coluna] = valor;
}

void mostrar_tabuleiro(FILE *fp, ESTADO *e) {
    int k, i;
    //int n = 0;
    for (i = 8; i > 0; i--) {
        for (k = 0; k < 8; k++) {
            switch (e->tab[i-1][k]) {
                case PRETA:
                    fprintf(fp,"#");
                    break;
                case VAZIO:
                    fprintf(fp,".");
                    break;
                case BRANCA:
                    fprintf(fp,"*");
                    break;
                case UM:
                    fprintf(fp,"1");
                    break;
                case DOIS:
                    fprintf(fp,"2");
                    break;
            }
        }
        fprintf(fp," %d", i);
        fprintf(fp,"\n");
    }
    fprintf(fp,"abcdefgh\n");
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];


    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        ERROS erro;
        if ((erro = jogar(e, coord)) == OK)
            mostrar_tabuleiro(stdout, e);
        else
            print_erro(erro);
        return 1;
    }

    if (strcmp(linha, "Q\n") == 0)
        e->num_jogadas = 32;

    if (sscanf(linha, "gr %s", nome_ficheiro) == 1) { // invocar na gravar o a -- stdout
        gravar(e, nome_ficheiro);
    }

        if (sscanf(linha, "ler %s", nome_ficheiro) == 1) {
            ERROS erro;
            //if ((erro = ler(e, nome_ficheiro)) == OK)
            ler(e,nome_ficheiro);

          // else
          //     print_erro(erro);
        }

    if(strcmp(linha, "movs\n") == 0) {
        printMovs(e, stdout);
    }

    return 1;
}