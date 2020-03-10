#ifndef SRC_CAMADADEDADOS_H
#define SRC_CAMADADEDADOS_H
ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
int obter_estado_casa(ESTADO *e, COORDENADA c);

#endif //SRC_CAMADADEDADOS_H