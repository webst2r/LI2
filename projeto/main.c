#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadedados.h"
#include "interface.h"
#include "logica.h"

int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(stdout,e);
    while(obter_numero_de_jogadas(e) < 32) {
        prompt(e);
        interpretador(e);
    }
    return 0;
}
