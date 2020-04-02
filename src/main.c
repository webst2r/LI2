#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "camadadedados.h"
#include "interface.h"
#include "logica.h"

void prompt (ESTADO *e) {
    int nc = e->numeroComandos ;
    int ja = obter_jogador_atual (e);
    int nj = obter_numero_de_jogadas(e);
    printf ("# %i PL%i (%i)>",nc, ja , nj );
}

int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    printf("abcdefgh\n");
    while(e->num_jogadas < 32) {
        prompt(e);
        interpretador(e);
    }
    return 0;
}