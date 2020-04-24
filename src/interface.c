#include <stdio.h>
#include "interface.h"
#include "camadadedados.h"
#include "logica.h"
#define BUF_SIZE 1024
#include <string.h>

void printMovs(ESTADO *e, FILE *pFile);

void prompt (ESTADO *e) {
    int nc = obter_numero_comandos(e);
    int ja = obter_jogador_atual (e);
    int nj = obter_numero_de_jogadas(e);
    printf ("# %i PL%i (%i)> ",nc ,ja ,nj);
}

void print_erro(ERROS erro) {
    if (erro == JOGADA_INVALIDA) {
        printf("A jogada é inválida.\n");
    } else {
        if (erro == COORDENADA_INVALIDA) {
            printf("A coordenada é inválida.\n");
        } else {
            if (erro == ERRO_LER_TAB) {
                printf("Ocorreu um erro ao ler o tabuleiro.\n");
            } else {
                if (erro == ERRO_ABRIR_FICHEIRO) {
                    printf("Ocorreu um erro ao abrir o ficheiro.\n");
                } else printf("Ocorreu um erro ao gravar o ficheiro.\n");
            }
        }
    }
}

ERROS gravar(ESTADO *e, char *nome_ficheiro) {
    FILE *fp = fopen(nome_ficheiro, "w");

    if(fp == NULL){
        printf("Não é possivel criar o ficheiro.\n");
        return ERRO_GRAVAR_TAB;
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
    fclose(fp); // Fechar ficheiro para salvar a informação
    printf("Ficheiro criado e salvado com sucesso.  \n");
    return 0;
}

void printMovs(ESTADO *e, FILE *fp) {
    printMovs_aux(e,fp);
}

ERROS ler(ESTADO *e, char *nome_ficheiro) {
    FILE *fp;
    fp = fopen(nome_ficheiro, "r");
    if (fp == NULL) {
        perror("Ao ler");
        return ERRO_ABRIR_FICHEIRO;
        }
    ler_aux(e, fp);
    //mostrar_tabuleiro(stdout, e);
    //printMovs(e, stdout);
    fclose(fp);
     return OK;
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


void atualiza_estado(ESTADO *e) {
    int w = e->numero_de_pos;
    e->num_jogadas = w;
    e->jogador_atual = 1;

    if(w == 0) {
        e->ultima_jogada.coluna = 4;
        e->ultima_jogada.linha = 4;
    } else
    e->ultima_jogada = e->jogadas[w-1].jogador2;

    while (w < 32) {
        e->jogadas[w].jogador1.coluna = 0;
        e->jogadas[w].jogador1.linha = 0;
        e->jogadas[w].jogador2.coluna = 0;
        e->jogadas[w].jogador2.linha = 0;
        w++;
    }
    atualiza_tabuleiro(e);
}

void atualiza_tabuleiro(ESTADO *e) {
    int linha2, coluna2;
    int pos = e->numero_de_pos;
    for (linha2 = 0; linha2 < 8; linha2++) {
        for (coluna2 = 0; coluna2 < 8; coluna2++) {
            if (linha2 == 4 && coluna2 == 4) {
                if (pos == 0) {
                    e->tab[linha2][coluna2] = BRANCA;
                } else {
                    e->tab[linha2][coluna2] = PRETA;
                }
            }
            else
                e->tab[linha2][coluna2] = VAZIO;
        }
    }
    e->tab[0][0] = UM;
    e->tab[7][7] = DOIS;

    for(int i = 0; i < pos; i++) {
        COORDENADA c1, c2;

        c1 =e->jogadas[i].jogador1;
        c2 = e->jogadas[i].jogador2;

        if ((pos - 1) != i) {
            e->tab[c1.linha][c1.coluna] = PRETA;
            e->tab[c2.linha][c2.coluna] = PRETA;
        } else {
            e->tab[c1.linha][c1.coluna] = PRETA;
            e->tab[c2.linha][c2.coluna] = BRANCA;
        }
    }
}


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];
    int numero_de_pos;
    //char jogada[BUF_SIZE];

    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        int colunavencedor, linhavencedor;
        colunavencedor = coord.coluna;
        linhavencedor = coord.linha;
        ERROS erro;
        if ((erro = jogar(e, coord)) == OK) {
            mostrar_tabuleiro(stdout, e);
            if (obter_numero_de_jogadas(e) == 32 && colunavencedor == 7 && linhavencedor == 7) {
                printf("O Jogador 2 é o vencedor! Parabéns!\n");
            }
            if (obter_numero_de_jogadas(e) == 32 && colunavencedor == 0 && linhavencedor == 0) {
                printf("O Jogador 1 é o vencedor! Parabéns!\n");
            }
        } else
            print_erro(erro);
        return 1;
    }

    if (strcmp(linha, "Q\n") == 0)
        maximiza_jogadas(e);

    if (strcmp(linha, "jog\n") == 0) {
        bot(e);
        mostrar_tabuleiro(stdout, e);
    }
    if (sscanf(linha, "pos %d", &numero_de_pos) == 1) {
        e->numero_de_pos = numero_de_pos;
        atualiza_tabuleiro(e);
        mostrar_tabuleiro(stdout, e);
    }
    if (sscanf(linha, "gr %s", nome_ficheiro) == 1) {
        gravar(e, nome_ficheiro);
    }

    if (sscanf(linha, "ler %s", nome_ficheiro) == 1) {
        ERROS erro;
        if ((erro = ler(e, nome_ficheiro)) == OK) {
            mostrar_tabuleiro(stdout, e);
            printMovs(e, stdout);
        } else print_erro(erro);
    }

    if (strcmp(linha, "movs\n") == 0) {
        printMovs(e, stdout);
    }

    return 1;
}
