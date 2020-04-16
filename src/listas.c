#include "listas.h"

// Cria uma lista vazia
LISTA criar_lista() {
    LISTA l1;
    l1 = NULL;
    return l1;
}

// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *v) {
    LISTA r;

    r = malloc(sizeof(struct nodo));
    r->valor = v;
    r->prox = L;

    return r;
}


// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L) { /
    LISTA cabeca;

    cabeca = malloc (sizeof(struct nodo));
    cabeca = L->valor;
}




// Devolve a cauda da lista
LISTA proximo(LISTA L){     // recebe um valor x e uma lista l e vai retornar o x como cabeca e a lista l como cauda
    LISTA cauda;

    cauda = malloc (sizeof(struct nodo));
    cauda = L->prox;

    return cauda;
}


// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L){
    LISTA r;


    L->prox->valor = r->valor; // a cabeça da cauda da lista L passa a ser a cabeça da nova lista R.
    r->prox = L->prox->prox; // o resto será a cauda da lista r.
// talvez falta libertar o espaço ocupado.
    return r;
}


// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L){
    LISTA cabeca = L->valor;

    if(cabeca = NULL) return 1;
    else 0;
}









