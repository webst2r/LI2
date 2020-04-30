/**
@file listas.h
Definição das listas ligadas.
*/

#ifndef LI2FINAL_LISTAS_H
#define LI2FINAL_LISTAS_H
/**
\brief Tipo de dados para as Listas.
*/
typedef struct nodo {
    void *valor;
    struct nodo *prox;
} NODO, *LISTA;
/**
\brief Cria uma lista vazia.
@returns Uma lista.
*/
LISTA criar_lista();
/**
\brief Insere um valor na cabeça da lista.
@returns Uma lista.
*/
LISTA insere_cabeca(LISTA L, void *v);
/**
\brief Devolve a cabeça da lista.
@returns Uma lista.
*/
void *devolve_cabeca(LISTA L);
/**
\brief Devolve a cauda da lista.
@returns Uma lista.
*/
LISTA proximo(LISTA L);
/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
@returns Uma lista.
*/
LISTA remove_cabeca(LISTA L);
/**
\brief Devolve verdareiro se a lista é vazia.
@returns Um inteiro.
*/
int lista_esta_vazia(LISTA L);
/**
\brief Devolve o comprimento da lista.
@returns Um inteiro.
*/
int comprimento_da_lista(LISTA l);

#endif //LI2FINAL_LISTAS_H
