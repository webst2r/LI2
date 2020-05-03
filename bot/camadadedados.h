/**
@file camadadedados.h
Definição do estado e das funções que o manipulam
*/
#ifndef BOT_CAMADADEDADOS_H
#define BOT_CAMADADEDADOS_H

#include <bits/types/FILE.h>

/**
\brief Tipo de dados para as Coordenadas.
*/
typedef struct {
    /** A linha */
    int linha;
    /** A coluna */
    int coluna;
} COORDENADA;

/**
\brief Tipo de dados para a Jogada
*/
typedef struct {
    /** Coordenada do Jogador1 */
    COORDENADA jogador1;
    /** Coordenada do Jogador2 */
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
    /** Casa da Vitória para o Jogador1 */
    UM = '1',
    /** Casa da Vitória para o Jogador2 */
    DOIS = '2',
    /** Casa Vazia */
    VAZIO = '.',
    /** Casa Branca */
    BRANCA = '*',
    /** Casa Preta */
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
    /**  numero de posição */
    int numero_de_pos;
} ESTADO;
/**
\brief Tipo de dados para os erros
*/
typedef enum {
    /** OK */
    OK,
    /** A coordenada é inválida */
    COORDENADA_INVALIDA,
    /** A jogada é inválida */
    JOGADA_INVALIDA,
    /** Erro ao ler o tabuleiro */
    ERRO_LER_TAB,
    /** Erro ao abrir o ficheiro */
    ERRO_ABRIR_FICHEIRO,
    /** Erro ao gravar o tabuleiro */
    ERRO_GRAVAR_TAB,
} ERROS;


/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
 */
ESTADO *inicializar_estado();
/**
\brief Altera as casas para PRETO.
@param e Apontador para o estado.
@returns Um erro.
*/
void preta(ESTADO *e);
/**
\brief Atualiza o tabuleiro.
@param e Apontador para o estado.
*/
void atualiza_tabuleiro(ESTADO *e);
/**
\brief Atualiza o estado.
@param e Apontador para o estado.
*/
void atualiza_estado(ESTADO *e);
/**
\brief Obtém o número de posição.
@param e Apontador para o estado.
@returns O número de posição.
*/
int obter_numero_de_pos(ESTADO *e);
/**
\brief Obtém o jogador atual.
@param e Apontador para o estado.
@returns O número do jogador atual.
*/
int obter_jogador_atual(ESTADO *e);
/**
\brief Obtém o numero de jogadas.
@param e Apontador para o estado.
@returns O número de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *e);
/**
\brief Obtém o estado de determinada casa.
@param e Apontador para o estado.
@param c A coordenado.
@returns O estado da casa,
 */
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/**
\brief Aumenta o número de comandos.
@param e Apontador para o estado.
*/
void add_numerodecomandos(ESTADO *e);
/**
\brief Atualiza o número de jogadas.
@param e Apontador para o estado.
*/
void atualiza_num_jogadas(ESTADO *e);
/**
\brief Atualiza o jogador atual.
@param e Apontador para o estado.
*/
void atualiza_jogador_atual(ESTADO *e);
/**
\brief Atualiza o array de jogadas.
@param e Apontador para o estado.
@param c A coordenada.
*/
void atualiza_jogadas(ESTADO *e, COORDENADA c);
/**
\brief Obtém o número de comandos feitos até ao momento.
@param e Apontador para o estado.
@returns O número de comandos.
*/
int obter_numero_comandos(ESTADO *e);
/**
\brief Mete o número de jogados ao máximo.
@param e Apontador para o estado.
*/
void maximiza_jogadas(ESTADO *e);
/**
\brief Auxilia a ler a alterar o tabuleiro e a alterar o estado.
@param e Apontador para o estado.
@param fp Apontador para o ficheiro.
*/
void ler_aux(ESTADO *e, FILE *fp);
/**
\brief Auxilia a ler a alterar o tabuleiro e a alterar o estado.
@param e Apontador para o estado.
@param fp Apontador para o ficheiro.
*/
void printMovs_aux(ESTADO *e, FILE *fp);

#endif // BOT_CAMADADEDADOS_H
