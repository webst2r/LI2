/**
@file camadadedados.h
Definição do estado e das funções que o manipulam
*/
#ifndef SRC_CAMADADEDADOS_H
#define SRC_CAMADADEDADOS_H

#include <bits/types/FILE.h>

/**
\brief Tipo de dados para as Coordenadas
*/
typedef struct {
    int linha;
    int coluna;
} COORDENADA;

/**
\brief Tipo de dados para a Jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** A coordenada da ultima jogada */
    COORDENADA ultima_jogada;
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /**  numero de comandos */
    int numeroComandos;
} ESTADO;
/**
\brief Tipo de dados para os erros
*/
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
    ERRO_GRAVAR_TAB,
} ERROS;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
 */
ESTADO *inicializar_estado();
/**
\brief Obtém o jogador atual.
@param Apontador para o estado.
@returns O número do jogador atual.
*/
int obter_jogador_atual(ESTADO *estado);
/**
\brief Obtém o numero de jogadas.
@param Apontador para o estado.
@returns O número de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *estado);
/**
\brief Obtém o estado de determinada casa.
@param Apontador para o estado.
@param A coordenado.
@returns O estado da casa,
 */
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/**
\brief Imprime o tabuleiro para jogar.
*/
int imprime_tabuleiro (CASA arr[8][8]);
/**
\brief Imprime a linha 3.
*/
int imprime_linha_3 (CASA arr[8][8]);
/**
\brief Aumenta o número de comandos.
@param Apontador para o estado.
*/
void add_numerodecomandos(ESTADO *e);

/**
\brief Armazena jogadas.
@param Apontador para o estado.
@param A coordenada.
*/
void armazenar_jogada(ESTADO *e, COORDENADA c);
/**
\brief Atualiza o número de jogadas.
@param Apontador para o estado.
@returns O número de jogadas atualizado.
*/
int atualiza_num_jogadas(ESTADO *e);
/**
\brief Atualiza o jogador atual.
@param Apontador para o estado.
@returns O número do jogador atual.
*/
int atualiza_jogador_atual(ESTADO *e);
/**
\brief Atualiza o array de jogadas.
@param Apontador para o estado.
@param A coordenada.
*/
void atualiza_jogadas(ESTADO *e, COORDENADA c);
/**
\brief Obtém o número de comandos feitos até ao momento.
@param Apontador para o estado.
@returns O número de comandos.
*/
int obter_numero_comandos(ESTADO *e);
/**
\brief Mete o número de jogados ao máximo.
@param Apontador para o estado.
*/
void maximiza_jogadas(ESTADO *e);
/**
\brief Auxilia a ler a alterar o tabuleiro e a alterar o estado.
@param Apontador para o estado.
@param fp Apontador para o ficheiro.
*/
void ler_aux(ESTADO *e, FILE *fp);
/**
\brief Auxilia a ler a alterar o tabuleiro e a alterar o estado.
@param Apontador para o estado.
@param fp Apontador para o ficheiro.
*/
void printMovs_aux(ESTADO *e, FILE *fp);

#endif // SRC_CAMADADEDADOS_H