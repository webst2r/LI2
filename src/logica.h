/**
@file logica.h
Definição da interface e das funções que a manipulam
*/

#ifndef SRC_LOGICA_H
#define SRC_LOGICA_H
#include "camadadedados.h"

/**
\brief Função que permite fazer jogadas, tendo em conta um estado e uma coordenada.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS jogar(ESTADO *e, COORDENADA c, int *numero_de_pos);

/**
\brief Função que verifica se o jogador se pode movimentar para determinada casa com base na distãncia a que o jogador se encontra dela.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS check_movimentos(ESTADO *estado,COORDENADA c);

/**
\brief Função que averigua se uma casa está livre.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS casa_livre(ESTADO *e, COORDENADA c);

/**
\brief Função que averigua se uma jogada é valida.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS jogada_valida(ESTADO *e, COORDENADA c);
/**
\brief Altera as casas para PRETO.
@param e Apontador para o estado.
@returns Um erro.
*/
void func(ESTADO *e);
/**
\brief Verifica se o jogo termina no fim de uma jogada.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS verifica_se_acabou (ESTADO *estado, COORDENADA c);

#endif // SRC_LOGICA_H