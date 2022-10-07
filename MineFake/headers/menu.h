#define OPCOES 4
#define TAMANHO_FONTE 40
#define TAM_TEXTO 20
#define DISTANCIA_ENTRE_OPCOES 100
#define DISTANCIA_ENTRE_RANKINGS 75

#include <raylib.h>
#include <stdio.h>

#include "mapa.h"
#include "save.h"
#include "rank.h"

#define ALTURA 768
#define LARGURA 1080
#define OPCOES 4
#define TAM_TEXTO 20
#define DISTANCIA_ENTRE_OPCOES 100
#define TAMANHO_BLOCOS 64
#define TEXTO_ENCERRAMENTO 21

#ifndef MENU_H
#define MENU_H

void selecionaMenu(int selected, Mapa *mapa, Texturas textura, bool *close, bool *ranking);
void desenhaMenu(int selected);
void desenhaEncerramento(bool win, Sound som[NUM_SONS]);
void imprimeRanking(Rank ranking);
//bota as funções do menu aqui

#endif // MENU_H
