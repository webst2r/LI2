/**
@file interface.h
Definição da interface e das funções que a manipulam
*/

#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H
#include "camadadedados.h"

/**
\brief Interpretador de jogadas
@param e Apontador para o estado.
@returns Um inteiro.
*/
int interpretador(ESTADO *e);
/**
\brief
@param e Apontador para o estado.
*/
void prompt (ESTADO *e);

/**
\brief Função que mostra o tabuleiro
@param fp Apontador para o ficheiro.
@param e Apontador para o estado.
*/
void mostrar_tabuleiro(FILE *fp,ESTADO *e);


/**
\brief Função que imprime a razão pela qual ocorreram erros
@param erro O erro recebido.
*/
void print_erro(ERROS erro);

/**
\brief Função que grava um tabuleiro num ficheiro.
@param e Apontador para o estado.
@param nome_ficheiro Nome do ficheiro que pretendemos gravar.
@returns Um erro.
*/
ERROS gravar(ESTADO *e, char *nome_ficheiro);

/**
\brief Função que lê o tabuleiro gravado num ficheiro.
@param e Apontador para o estado.
@param nome_ficheiro Nome do ficheiro que pretendemos ler.
@returns Um erro.
*/
ERROS ler(ESTADO *e, char *nome_ficheiro);

/**
\brief Imprime os movimentos efetuados.
@param e Apontador para o estado.
@param fp Apontador para o ficheiro.
*/
void printMovs(ESTADO *e, FILE *fp);


void atualiza_tabuleiro(ESTADO *e);


void atualiza_estado(ESTADO *e);

#endif // SRC_INTERFACE_H