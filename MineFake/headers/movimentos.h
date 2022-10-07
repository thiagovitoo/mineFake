#include <stdbool.h>
#include <raylib.h>

#include "mapa.h"
#include "animacao.h"
#include "item.h"

#define TAMANHO_BLOCOS 64
#define NUM_ITENS
#define MIN 1
#define MAX 100
#define NUM_ITENS 7
#define NUM_SONS 20

#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

void jogCima(Mapa *mapa, bool *animacaoVertical, int *dMov, int *frameCounter);
void jogBaixo(Mapa *mapa, bool *animacaoVertical, int *dMov, int *frameCounter);
void jogEsquerda(Mapa *mapa, bool *animacaoHorizontal, int *dMov, int *frameCounter);
void jogDireita(Mapa *mapa, bool *animacaoHorizontal, int *dMov, int *frameCounter);
void abrePorta(Mapa *mapa);
Item abreBau(Mapa *mapa, Item item[NUM_ITENS], Sound[NUM_SONS], bool *animcaoBau);
int altura(Mapa mapa);

#endif // MOVIMENTOS_H
