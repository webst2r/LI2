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

void mostrar_tabuleiro(char* nome_ficheiro, ESTADO *e);

/**
\brief Função que imprime a razão pela qual ocorreram erros
*/
void print_erro(ERROS erro);

/**
\brief Função que grava um tabuleiro num ficheiro.
*/
ERROS gravar(ESTADO *e, char* nome_ficheiro);

/**
\brief Função que lê o tabuleiro gravado num ficheiro.
*/
ERROS ler(ESTADO *e, char* nome_ficheiro);

/**
\brief Função que coloca o novo valor numa casa.
*/
CASA set_casa(ESTADO *e, COORDENADA c, CASA valor);


#endif // SRC_INTERFACE_H
