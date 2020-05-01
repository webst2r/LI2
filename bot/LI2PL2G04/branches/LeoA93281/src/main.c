#include <stdio.h>
#include "camadadedados.h"
#include "interface.h"
void prompt (ESTADO *e) {
    int nc = e -> numeroComandos ;
    int ja = obter_jogador_atual (e);
    int nj = obter_numero_de_jogadas(e);
    printf ("# %i PL%i (%i)>",nc, ja , nj );
}

int main() {
    ESTADO *e = inicializar_estado();
    prompt(e);
    interpretador(e);
    return 0;
}

