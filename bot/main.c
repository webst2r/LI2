#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#include "logica.h"
/*
int main(char *ficheiro_lido,  char *ficheiro_gravado) {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(stdout,e);

    ler(e, ficheiro_lido);
    bot2(e);
    gravar(e, ficheiro_gravado);

    return 0;
}
*/
int main(int argc, char *argv[]) {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(stdout,e);

    if(argc == 3) {
        char *jog01 = atoi(argv[1]);
        char *jog02 = atoi(argv[2]);

        jog01 = ler(e, ficheiro_lido);
        bot2(e);
        jog02 = gravar(e,ficheiro_gravado);

    }
}
return 0;
}
