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

    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++) {
            if (k == 7 && i == 0)
                fprintf(fp,"2");
            else if (i == 7 && k == 0)
                fprintf(fp,"1");
            else {
                switch (e->tab[k][i])
                {
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
        }
        fprintf(fp, "\n");
    }
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
                fprintf(fp, "0%d: %c%d", i + 1, e->jogadas[i].jogador1.coluna + 'a',
                        e->jogadas[i].jogador1.linha + '1');
            }
            if (e->jogadas[i].jogador2.linha != 0 || e->jogadas[i].jogador2.coluna != 0)
                fprintf(fp, " %c%d\n", e->jogadas[i].jogador2.coluna + 'a', e->jogadas[i].jogador2.linha + '1');

            if (e->jogadas[i].jogador1.linha != 0 && e->jogadas[i].jogador1.coluna != 0 &&
                e->jogadas[i].jogador2.coluna == 0 && e->jogadas[i].jogador2.linha == 0) {
                fprintf(fp, "\n");
            }
        } else {
            if (e->jogadas[i].jogador1.linha != 0 || e->jogadas[i].jogador1.coluna != 0)
                fprintf(fp, "%d: %c%d", i + 1, e->jogadas[i].jogador1.coluna + 'a', e->jogadas[i].jogador1.linha + '1');

            if (e->jogadas[i].jogador2.linha != 0 || e->jogadas[i].jogador2.coluna != 0)
                fprintf(fp, " %c%d\n", e->jogadas[i].jogador2.coluna + 'a', e->jogadas[i].jogador2.linha + '1');
            else
                fprintf(fp, "\n");
        }
    }
}

ERROS ler(ESTADO *e, char* nome_ficheiro) {  // FIXME - IMPLEMENTAR ERRO DE LEITURA
    ERROS erro;
    char buffer[BUF_SIZE];
    int l = 0;
    char linha[BUF_SIZE];
    FILE *fp;

    while (fgets(buffer, BUF_SIZE, fp) != NULL) {
        for (int c = 0; c < 8; c++) set_casa(e, (COORDENADA) {l, c}, buffer[c]);
        l++;
        int num_jog;
        COORDENADA c1, c2;
        char jog1[BUF_SIZE];
        char jog2[BUF_SIZE];
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if (num_tokens == 3) {
            c1.coluna = jog1[0] - 'a';
            c1.linha = jog1[1] - '1';
            c2.coluna = jog2[0] - 'a';
            c2.linha = jog2[1] - '1';
            armazenar_jogada(e, c1, c2);
        } else {
            c1.coluna = jog1[0] - 'a';
            c1.linha = jog1[1] - '1';
            c2.coluna = -1;
            c2.linha = -1;
            armazenar_jogada(e, c1, c2);
        }

        fclose(fp);
    }
}

void set_casa(ESTADO *e, COORDENADA c, CASA valor) {       // COLOCA O VALOR NA CASA COM COORDENADA por miudos COORDENADA -> VALOR
    CASA estadocasa;
    e->tab[c.linha][c.coluna] = valor;
}

void mostrar_tabuleiro(ESTADO *e) {
    int k, i;
    //int n = 0;
    for (i = 8; i > 0; i--) {
        for (k = 0; k < 8; k++) {
            switch (e->tab[i-1][k]) {
                case PRETA:
                    putchar(PRETA);
                    break;
                case VAZIO:
                    putchar(VAZIO);
                    break;
                case BRANCA:
                    putchar(BRANCA);
                    break;
                case UM:
                    putchar(UM);
                    break;
                case DOIS:
                    putchar(DOIS);
                    break;
            }
        }
        printf(" %d", i);
        printf("\n");
    }

}

//int arr[] = {8,7,6,5,4,3,2,1};

/* for(k = 8; k < 9; k++) {
     printf(" %d", arr[n]);
 }
 n += 1; */


void mostrar_tabuleiro2 (char* nome_ficheiro, ESTADO *e) {
    ler(e, nome_ficheiro);
    mostrar_tabuleiro(e);
    printf("abcdefgh\n");
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
            mostrar_tabuleiro2(nome_ficheiro, e);
        else
            print_erro(erro);
        return 1;
    }

    if (strcmp(linha, "Q\n") == 0)
        e->num_jogadas = 32;

    if(sscanf(linha, "gr %s", nome_ficheiro) == 1) {
        gravar(e,nome_ficheiro);

        if(sscanf(linha, "ler %s", nome_ficheiro) == 1) {
            ERROS erro;
            if((erro = ler(e,nome_ficheiro)) == OK)
                mostrar_tabuleiro2(nome_ficheiro, e);
            else
                print_erro(erro);
        }
        return 1;
    }
}