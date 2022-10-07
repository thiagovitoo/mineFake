#include <raylib.h>
#include <stdbool.h>

#include "coordenada.h"
#include "jogador.h"
#include "textura.h"

#define MAPA_L 30
#define MAPA_C 120
#define NUM_TEXTURAS 20
#define TAM_MOLDURA 12
#define TAMANHO_FONTE 40
#define NUM_SONS 20

#define MAPA1 "maps/mapa1.txt"
#define MAPA2 "maps/mapa2.txt"
#define MAPA3 "maps/mapa3.txt"

#ifndef MAPA_H
#define MAPA_H

typedef struct {
    char mapa[MAPA_L][MAPA_C];
    Localizacao dimensao;
    int fase, baus, bausAbertos;
    char porta;
    Jogador jogador;
} Mapa;

void loadGameMap(int fase, Mapa *mapa);
Jogador jogInit(Mapa mapa, Texturas textura);
void desenhaMolduraMapa();
void desenhaFundo(Texturas textura);
void imprimeMapa(Mapa mapa, Texturas textura);
void imprimeJog(Mapa mapa, Texturas textura, int frameCounter, bool animacaoHorizontal);
void printJogInfo(Mapa mapa, Texturas textura);

#endif // MAPA_H
