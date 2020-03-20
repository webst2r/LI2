#include "camadadedados.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#define BUF_SIZE 1024


int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    if(casa_livre(e,c)) {
        if(check_movimentos(e,c)) {
            e->tab[c.linha][c.coluna] = BRANCA;
            return 1;
        } else return 0;
    } else return 0;
}


int check_movimentos(ESTADO *estado,COORDENADA c){
    int coluna1,coluna2,linha1,linha2;
    coluna1=estado->ultima_jogada.coluna;
    linha1=estado-> ultima_jogada.linha;
    coluna2 = c.coluna;
    linha2=c.linha;

    if ((sqrt((coluna1-coluna2)^2-(linha1-linha2)^2)) == 1) return 1;
    else return 0;
}

//esta função devolveria 0 se a casa não existe (porque ultrapassa os limites do tabuleiro) ou se não está livre e 1 caso contrário
//então, ha_jogada_possivel invoca essa função 8 vezes
int casa_livre(ESTADO *e, COORDENADA c) {
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    if(coluna < 8 || linha < 8 ) {
        if (obter_estado_casa(e, c) == VAZIO || obter_estado_casa(e, c) == 1 || obter_estado_casa(e, c) == 2)
        return 1;
        else return 0; // devolve 0 se a casa não estiver vazia;
    } else return 0; // devolve 0 se a casa nao existe (está fora do mapa);
}


// se a casa estiver livre, confirma se é casa vizinha (se está em distancia aceitavel para jogar).
int jogada_valida(ESTADO *e, COORDENADA c) {
    if(casa_livre(e,c) == 1) // se a função casa_livre retornar 1 significa que a casa está livre.
        check_movimentos(e,c);
    else return 0;
}


