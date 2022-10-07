#include "mapa.h"
#include "textura.h"
#include "rank.h"

#define FILE_PATH_MAPA "maps/save.dat"
#define FILE_PATH_RANKING "maps/ranking.dat"

#ifndef SAVE_H
#define SAVE_H

void saveGame(Mapa mapa);
void loadGame(Mapa *mapa, Texturas textura);
void saveRanking(Rank ranking);
void loadRanking(Rank *ranking);
void deletaJogo();

#endif // SAVE_H
