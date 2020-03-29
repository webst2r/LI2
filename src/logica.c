#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#include <math.h>
#include <time.h>
#define BUF_SIZE 1024

ERROS verifica_se_acabou (ESTADO *estado, COORDENADA c){
    int coluna, linha;
    ERROS erro;
    coluna = c.coluna;
    linha = c.linha;

    srand(time(NULL));

    if(obter_jogador_atual(estado) == 2 && coluna == 7 && linha == 0 || obter_jogador_atual(estado) == 1 && coluna == 0 && linha == 7) {
        int resposta = rand() % 4;
        switch(resposta) {
            case 0:
                printf("Parabéns, você é o Vencedor!");
                break;

            case 1:
                printf("Venceu!");
                break;

            case 2:
                printf("Ganhou!");
                break;

            case 3:
                printf("Vitória!");
                break;
        }
    } else erro = OK;
    return erro;
}

void add_numerodecomandos(ESTADO *e){
    e->numeroComandos++;
}

ERROS jogar(ESTADO *e, COORDENADA c) {
    ERROS erro;
    int coluna, colunaNova, linha, linhaNova;
    coluna=e->ultima_jogada.coluna;
    linha=e->ultima_jogada.linha;
    colunaNova=c.coluna;
    linhaNova=c.linha;
    add_numerodecomandos(e);

    printf("jogar %d %d\n", colunaNova, linhaNova);
    if(erro = casa_livre(e,c) == OK) {
        if(erro = check_movimentos(e,c) == OK) {
            e->tab[linhaNova][colunaNova] = BRANCA;
            e->tab[coluna][linha] = PRETA;

            verifica_se_acabou(e,c);

        } else erro = JOGADA_INVALIDA;
        add_numerodecomandos(e);
    } else erro = casa_livre(e,c);
    return erro;
}

ERROS check_movimentos(ESTADO *estado,COORDENADA c){
    int coluna1,coluna2,linha1,linha2;
    ERROS erro;
    coluna1=estado->ultima_jogada.coluna;
    linha1=estado-> ultima_jogada.linha;
    coluna2 = c.coluna;
    linha2=c.linha;

    if ((sqrt((coluna1-coluna2)^2-(linha1-linha2)^2)) == 1) {
        erro = OK;
    }
    else erro = JOGADA_INVALIDA;
    return erro;
}

//esta função devolveria 0 se a casa não existe (porque ultrapassa os limites do tabuleiro) ou se não está livre e 1 caso contrário
//então, ha_jogada_possivel invoca essa função 8 vezes
ERROS casa_livre(ESTADO *e, COORDENADA c) {
    ERROS erro;
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    if(coluna < 8 || linha < 8 ) {
        if (obter_estado_casa(e, c) == VAZIO || obter_estado_casa(e, c) == 1 || obter_estado_casa(e, c) == 2) {
            erro = OK;
        }
        else erro = JOGADA_INVALIDA; // devolve 0 se a casa não estiver vazia;
    } else erro = COORDENADA_INVALIDA; // devolve 0 se a casa nao existe (está fora do mapa);
    return erro;
}


// se a casa estiver livre, confirma se é casa vizinha (se está em distancia aceitavel para jogar).
ERROS jogada_valida(ESTADO *e, COORDENADA c) {
    ERROS erro;
    if(erro = casa_livre(e,c) == OK) // se a função casa_livre retornar OK significa que a casa está livre.
        check_movimentos(e,c);
    else erro = JOGADA_INVALIDA;
    return erro;
}
