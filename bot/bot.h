/**
@file bot.h
Definição do bot e das funções que o manipulam.
*/

#ifndef SRC_BOT_H
#define SRC_BOT_H

#include "listas.h"

/**
\brief Verifica se o jogo termina no fim de uma jogada para decidir se a jogada é favoravel.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um inteiro.
*/
int verifica_se_acabou_bot(ESTADO *e, COORDENADA c);
/**
\brief Faz uma jogada sozinho, tendo em conta se é possível jogar para uma casa que termine o jogo favoravelmente ou jogando na casa com menor distância euclidiana à casa final.
@param e Apontador para o estado.
*/
void bot2(ESTADO *e);
/**
\brief Cálcula a distância euclidiana de uma casa à casa final.
@param c Apontador para a coordenada.
@param l Uma lista.
@returns A distância.
*/
float distance (COORDENADA * c, int jogador);
/**
\brief Verifica se é possível acabar o jogo favoravelmente.
@param e Apontador para o estado.
@param l Uma lista.
@returns Uma coordenada.
*/
COORDENADA fim_de_jogo(ESTADO *e, LISTA l);

/**
\brief Calcula a coordenada com a menor distância à casa final.
@param e Apontador para o estado.
@returns Uma coordenada.
*/
COORDENADA *euclidiana (ESTADO *e);


#endif //SRC_BOT_H
