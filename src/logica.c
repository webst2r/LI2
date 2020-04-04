#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#include <math.h>
#include <time.h>
#define BUF_SIZE 1024

void func(ESTADO *e);

ERROS verifica_se_acabou (ESTADO *e, COORDENADA c){
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    // srand(time(NULL));

    if(coluna == 7 && linha == 7) {
        printf("Parabéns, o jogador 2 é o vencedor!\n");
        maximiza_jogadas(e);
    } else if (coluna == 0 && linha == 0) {
        printf("Parabéns, o jogador 1 é o vencedor\n");
        maximiza_jogadas(e);
        /*
        int resposta = rand() % 4;
        switch(resposta) {

            case 0:
                estado->num_jogadas = 32;
                printf("Parabéns, você é o Vencedor!");
                break;

            case 1:
                estado->num_jogadas = 32;
                printf("Venceu!");
                break;

            case 2:
                estado->num_jogadas = 32;
                printf("Ganhou!");
                break;

            case 3:
                estado->num_jogadas = 32;
                printf("Vitória!");
                break;
        }
*/
    }
    return OK;
}

ERROS jogar(ESTADO *e, COORDENADA c) {
   // int coluna, colunaNova, linha, linhaNova;
    add_numerodecomandos(e);

    if(jogada_valida(e,c) == OK) {

        printf("Jogar %d %d\n", c.coluna, c.linha);
        func(e);
        e->tab[c.linha][c.coluna] = BRANCA;
        atualiza_jogadas(e,c);
                                    //e->tab[linha][coluna] = PRETA;
        e->num_jogadas = atualiza_num_jogadas(e);
        e->jogador_atual = atualiza_jogador_atual(e);
        e->ultima_jogada = c;
        verifica_se_acabou(e, c);
        return OK;
    } else return JOGADA_INVALIDA;
}

void func(ESTADO *e) {
    int linha, coluna;
    for (linha = 7; linha >= 0; linha --) {
        for (coluna = 0; coluna <=7 ; coluna ++) {
            if (e -> tab [linha] [coluna] == BRANCA) e -> tab [linha] [coluna] = PRETA;
        }
    }
}


ERROS check_movimentos(ESTADO *estado,COORDENADA c) {
    int coluna1, coluna2, linha1, linha2;
    coluna1 = estado->ultima_jogada.coluna;
    linha1 = estado->ultima_jogada.linha;
    coluna2 = c.coluna;
    linha2 = c.linha;


    if ((coluna2 == coluna1 + 1 || coluna2 == coluna1 - 1 || coluna2 == coluna1) && (linha2 == linha1 + 1 || linha2 == linha1 - 1 || linha2 == linha1))
        return OK;

    else return JOGADA_INVALIDA;
}
//esta função devolveria 0 se a casa não existe (porque ultrapassa os limites do tabuleiro) ou se não está livre e 1 caso contrário
//então, ha_jogada_possivel invoca essa função 8 vezes
ERROS casa_livre(ESTADO *e, COORDENADA c) {
    ERROS erro;
    int coluna, linha;
    coluna = c.coluna;
    linha = c.linha;

    if((coluna < 8) && (linha < 8)) {
        if (obter_estado_casa(e, c) == VAZIO || obter_estado_casa(e, c) == UM || obter_estado_casa(e, c) == DOIS) {
            erro = OK;
        }
        else erro = JOGADA_INVALIDA; // devolve 0 se a casa não estiver vazia;
    } else erro = COORDENADA_INVALIDA; // devolve 0 se a casa nao existe (está fora do mapa);
    return erro;
}

// se a casa estiver livre, confirma se é casa vizinha (se está em distancia aceitavel para jogar).
ERROS jogada_valida(ESTADO *e, COORDENADA c) {
    if(casa_livre(e,c) == OK) // se a função casa_livre retornar OK significa que a casa está livre.
        return check_movimentos(e,c);
    else return JOGADA_INVALIDA;

}
