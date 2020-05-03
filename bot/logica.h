/**
@file logica.h
Definição da interface e das funções que a manipulam
*/
#ifndef BOT_LOGICA_H
#define BOT_LOGICA_H
#include "camadadedados.h"
#include "listas.h"
/**
\brief Função que permite fazer jogadas, tendo em conta um estado e uma coordenada.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS jogar(ESTADO *e, COORDENADA c);
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
\brief Verifica se o jogo termina no fim de uma jogada.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS verifica_se_acabou (ESTADO *e, COORDENADA c);

/**
\brief Verifica se existe pelo menos uma jogada possível após uma jogada.
@param e Apontador para o estado.
@returns Um número inteiro.
*/
int ha_jogada_possivel (ESTADO *e, COORDENADA c);



#endif // BOT_LOGICA_H
