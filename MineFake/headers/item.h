#include <raylib.h>

#include "mapa.h"

#define TAM_NOME_ITEM 25
#define TAM_DESC 256
#define NUM_ITENS 11

#ifndef ITEM_H
#define ITEM_H

typedef struct {
    char nome[TAM_NOME_ITEM], descricao[TAM_DESC];
    int tipo, ID;
    Texture2D textura;
    /*
    Tipos:
    1- Infinito
    2- Uso instantâneo
    3- Consumível
    */
} Item;

void loadItens(Item item[NUM_ITENS], Texturas textura);
Item criaItem(char nome[TAM_NOME_ITEM], char descricao[TAM_DESC], int tipo, int ID, Texture2D textura);
Item getLevelItem(Mapa *mapa, int fase, Item itens[NUM_ITENS]);
Item getKey(Item itens[NUM_ITENS]);
Item getRandomItem(Mapa *mapa, int fase, Item item[NUM_ITENS]);
//void imprimeItem(Texturas textura, Item item, int *frameCounter, bool *animacaoBau);


#endif // ITEM_H
