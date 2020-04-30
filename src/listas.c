#include <stddef.h>
#include <stdlib.h>
#include "listas.h"

LISTA criar_lista() {
    return NULL;
}

LISTA insere_cabeca(LISTA l, void *v) {
    LISTA r;

    r = malloc(sizeof(NODO));
    r->valor = v;
    r->prox = l;

    return r;
}

void *devolve_cabeca(LISTA l) {
    return l->valor;
}

LISTA proximo(LISTA L){ 
    return L->prox;
}

LISTA remove_cabeca(LISTA L){
    LISTA r = NULL;
    LISTA cabeca = L->valor;
    if(cabeca == NULL)
        return NULL;

    L->prox->valor = r->valor;
    r->prox = L->prox->prox;
    return r;
}

int lista_esta_vazia(LISTA L){ 
    return L == NULL;
}

int comprimento_da_lista (LISTA l) {
    int c = 0;

    while(l != NULL) {
        c++;
        l = l -> prox;
    }
    return c;
}
