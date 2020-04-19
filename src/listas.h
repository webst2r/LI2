#ifndef LI2FINAL_LISTAS_H
#define LI2FINAL_LISTAS_H

typedef struct nodo {
    void *valor; // cabeca
    struct nodo *prox; // cauda
} *LISTA;


// Cria uma lista vazia
LISTA criar_lista();

// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *v);

// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);

// Devolve a cauda da lista
LISTA proximo(LISTA L);

// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);

// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);

// Devolve o comprimento da lista.
int comprimento_da_lista(LISTA l);

#endif //LI2FINAL_LISTAS_H
