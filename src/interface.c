#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "camadadedados.h"
#include "logica.h"
#define BUF_SIZE 1024
#include <string.h>

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];


    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', '8' - *lin}; // troquei o *lin - '1' para '8' - *lin
        ERROS erro;
        if ((erro = jogar(e, coord)) == OK)
            mostrar_tabuleiro2(nome_ficheiro, e); // FIXME - ADAPTAR MOSTRAR_TABULEIRO PARA RECEBER UM FICHEIRO
        else
            print_erro(erro);
        return 1;
    }
    if (strcmp(linha, "Q\n") == 0)
        return 0;
    if(sscanf(linha, "gr %s", nome_ficheiro) == 1) {
        gravar(e,nome_ficheiro);

    if(sscanf(linha, "ler %s", nome_ficheiro) == 1) {
        ERROS erro;
        if((erro = ler(e,nome_ficheiro)) == OK)
            mostrar_tabuleiro2(nome_ficheiro, e);
        else
            print_erro(erro);
        }
        printf("Não encontrou o comando %s", linha);

        return 1;
    }
}

void print_erro(ERROS erro) {
    if (erro == JOGADA_INVALIDA) {
        printf("A sua jogada é inválida.\n");
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
/*
void print_erro (ESTADO *estado, char nome_ficheiro[BUF_SIZE]) {
}
*/



/*
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        ERROS erro;
        if ((erro = jogar(e, coord)) == OK)
            mostrar_tabuleiro(stdout, e);
        else
            printf(erro);
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
            print_erro(erro);
    }
    PRINT_DEBUG("Comando %s não encontrado.", linha);
    return 1;
}
*/

ERROS gravar(ESTADO *e, char* nome_ficheiro) { // FIXME - IMPLEMENTAR ERRO
    FILE *fp;

    fp = fopen(nome_ficheiro, "w");

    if(fp == NULL)  // fopen() devolve NULL se a ultima operação foi mal sucedida
    {
        printf("Não é possivel criar o ficheiro.\n");
        exit(EXIT_FAILURE);
    }
    // fprintf(fp , "%d", e -> num_jogadas )
    //fazer fprintf (de cada linha?)
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++) {
            if (k == 7 && i == 0)
                fprintf(stdout,"2");
            else if (i == 7 && k == 0)
                fprintf(stdout,"1");
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
    }


    fclose(fp); /* Fechar ficheiro para salvar a informação */

    printf("Ficheiro criado e salvado com sucesso. :) \n");

    return 0;
}


ERROS ler(ESTADO *e, char* nome_ficheiro){  // FIXME - IMPLEMENTAR ERRO DE LEITURA
    ERROS erro;
    char buffer[BUF_SIZE];
    int l = 0;
    char linha[BUF_SIZE];
    FILE *fp;


    while(fgets(buffer, BUF_SIZE, fp) != NULL) {
        for(int c = 0; c < 8; c++) set_casa(e, (COORDENADA) {l, c}, buffer[c]);
        l++;
        int num_jog;
        char jog1[BUF_SIZE];
        char jog2[BUF_SIZE];
        int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
        if(num_tokens == 3) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = str_to_coord(jog2);
            armazenar_jogada(e, (JOGADA) {c1, c2});
        } else {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = {-1, -1};
            armazenar_jogada(e, (JOGADA) {c1, c2});
        }
    }
    fclose(fp);
}




void set_casa(ESTADO *e, COORDENADA c, CASA valor) {       // COLOCA O VALOR NA CASA COM COORDENADA por miudos COORDENADA -> VALOR
    CASA estadocasa;
    e->tab[c.linha][c.coluna] = valor;
}

void mostrar_tabuleiro(ESTADO *e) {
            int k;
            int n = 0;
            for (int i = 0; i < 8; i++) {
                for (k = 0; k < 9; k++) {
                    if (k == 7 && i == 0)
                        printf("2");
                    else if (i == 7 && k == 0)
                        printf("1");
                    else {
                        switch (e->tab[k][i]) {
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
                int arr[] = {8,7,6,5,4,3,2,1};

                for(k = 8; k < 9; k++) {
                    printf(" %d", arr[n]);
                }
                n += 1;
                printf("\n");

            }
        }



void mostrar_tabuleiro2 (char* nome_ficheiro, ESTADO *e) {
    ler(e, nome_ficheiro);
    mostrar_tabuleiro(e);
    printf("abcdefgh\n");
}


//printf(obter_casa(state, i, k) == VAZIO) ? "." : (obter_casa(state, i, k) == BRANCA) ? "*" : "#" );






