#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "camadadedados.h"
#include "logica.h"
#define BUF_SIZE 1024
#include <string.h>

int interpretador(ESTADO *e)
{
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2)
    {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
        if (strcmp(linha, "Q\n") == 0)
            return 0;

    }
    return 1;
}
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

void gravar(ESTADO *e, char* nome_ficheiro) {
    FILE *fp;

    fp = fopen(nome_ficheiro, "w");

    if(fp == NULL)  // fopen() devolve NULL se a ultima operação foi mal sucedida
    {
        printf("Não é possivel criar o ficheiro.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp , "%d", e -> num_jogadas )
  //fazer fprintf (de cada linha?)






    fclose(fp); /* Fechar ficheiro para salvar a informação */

    printf("Ficheiro criado e salvado com sucesso. :) \n");


    return 0;
}


void ler(ESTADO *e, char nome_ficheiro){
    char buffer[BUF_SIZE];
    int l = 0;
    FILE *fp;
    while(fgets(buffer, BUF_SIZE, f) != NULL) {
        for(int c = 0; c < 8; c++) set_casa(estado, {l, c}, buffer[c]);
        l++;
    }

    fclose(fp);

}

/*
void print_erro (ESTADO *estado, char nome_ficheiro[BUF_SIZE]) {

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