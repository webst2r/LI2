/**
@file logica.h
Definição da interface e das funções que a manipulam
*/
#ifndef PROJETO_LOGICA_H
#define PROJETO_LOGICA_H
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
\brief Função que verifica se o jogador se pode movimentar para determinada casa com base na distância a que o jogador se encontra dela.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
ERROS check_movimentos(ESTADO *e,COORDENADA c);
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
\brief Verifica se o jogo termina no fim de uma jogada para decidir se a jogada é favoravel.
@param e Apontador para o estado.
@param c  A coordenada.
@returns Um erro.
*/
int verifica_se_acabou_bot(ESTADO *e, COORDENADA c);
/**
\brief Verifica se existe pelo menos uma jogada possível após uma jogada.
@param e Apontador para o estado.
@param c A coordenada.
@returns Um número.
*/
int ha_jogada_possivel (ESTADO *e, COORDENADA c);
/**
\brief Insere numa lista, as coordenadas vizinhas e válidas para serem jogadas.
@param e Apontador para o estado.
@param l Uma lista.
@returns Uma lista.
*/
LISTA vizinhas(ESTADO *e, LISTA l);
/**
\brief Faz uma jogada sozinho aleatoriamente.
@param e Apontador para o estado.
*/
void bot(ESTADO *e);
/**
\brief Faz uma jogada sozinho, tendo em conta se é possível jogar para uma casa que termine o jogo favoravelmente ou jogando na casa com menor distância euclidiana à casa final.
@param e Apontador para o estado.
*/
void bot2(ESTADO *e);
/**
\brief Calcula a distância euclidiana, em float, de uma casa à casa final.
@param c A coordenada.
@param jogador O nº do jogador.
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

#endif // PROJETO_LOGICA_H
