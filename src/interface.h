/**
@file interface.h
Definição da interface e das funções que a manipulam
*/

#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H
#include "camadadedados.h"

/**
\brief Interpretador de jogadas
*/


int interpretador(ESTADO *e);

/**
\brief Função que mostra o tabuleiro
*/

void mostrar_tabuleiro (ESTADO *e);


#endif // SRC_INTERFACE_H
