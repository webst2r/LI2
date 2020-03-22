/**
@file camadadedados.h
Definição do estado e das funções que o manipulam
*/
#ifndef SRC_CAMADADEDADOS_H
#define SRC_CAMADADEDADOS_H
/**
\brief Tipos de casas

typedef enum {VAZIO, BRANCA, PRETA} CASA;
*/
/**
\brief Tipo de dados para as Coordenadas
*/
typedef struct {
    int coluna;
    int linha;
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
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
 */
ESTADO *inicializar_estado();
/**
\brief Obtém o jogador atual.
*/
int obter_jogador_atual(ESTADO *estado);
/**
\brief Obtém o numero de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *estado);
/**
\brief Obtém o estado de determinada casa.
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

void add_numerodecomandos(ESTADO *e);

#endif // SRC_CAMADADEDADOS_H
