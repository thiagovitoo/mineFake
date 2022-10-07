#include "jogador.h"

#define TAM_NOME 13
#define TAM_RANK 5

#ifndef RANK_H
#define RANK_H

typedef struct {
    char nome[TAM_NOME];
    int pontos;
} JogBasico;

typedef struct {
    JogBasico jogador[TAM_RANK];
    int numJogs;
} Rank;

JogBasico criaJogBasico(char nome[TAM_NOME], int pontos);
void rankingInit(Rank *ranking);
void insJogRank(Rank *ranking, Jogador jogador);

#endif // RANK_H

