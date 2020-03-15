#include "camadadedados.h"
#include "logica.h"
#include <stdio.h>


int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab[c.linha][c.coluna] = BRANCA;
    return 1;
}