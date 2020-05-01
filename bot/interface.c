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
            COORDENADA coord; coord.linha = i; coord.coluna = k;
            switch (obter_estado_casa(e, coord))
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
    fclose(fp); 
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
    fclose(fp);
    return OK;
}

void mostrar_tabuleiro(FILE *fp, ESTADO *e) {
    int coluna, linha;
    for (linha = 8; linha > 0; linha--) {
        for (coluna = 0; coluna < 8; coluna++) {
            switch (e->tab[linha-1][coluna]) {
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
        fprintf(fp," %d", linha);
        fprintf(fp,"\n");
    }
    fprintf(fp,"abcdefgh\n");
}
