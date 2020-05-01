#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#include "logica.h"
#include "bot.h"

int main(int argc, char *argv[]) {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(stdout, e);

    if(argc == 3) {
        
        ler(e, argv[1]);
        bot2(e);
        mostrar_tabuleiro(stdout, e);
        gravar(e, argv[2]);

    }
    return 0;
}
