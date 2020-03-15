#include "camadadedados.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#define BUF_SIZE 1024


int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab[c.linha][c.coluna] = BRANCA;
return 1;
}

