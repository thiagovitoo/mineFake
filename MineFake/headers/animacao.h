#include <stdbool.h>

#include "mapa.h"

#define TAMANHO_BLOCOS 64

#ifndef ANIMACAO_H
#define ANIMACAO_H

void movVertical(Mapa *mapa, bool *animacaoVertical, int direcao, int *frameCounter, int *dMov);
void movHorizontal(Mapa *mapa, bool *animacaoHorizontal, int direcao, int *frameCounter, int *dMov);
void gravidade(Mapa *mapa, bool *caindo, int h, int *frameCounter, int *dMov, int *tMov, int *alt, Sound som[NUM_SONS]);
void getItem();

#endif // ANIMACAO_H
