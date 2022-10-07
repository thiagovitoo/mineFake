#include <stdio.h>
#include "../headers/rank.h"

JogBasico criaJogBasico(char nome[TAM_NOME], int pontos) {
    JogBasico jog;
    strcpy (jog.nome, nome);
    jog.pontos = pontos;
    return jog;
}

void rankingInit(Rank *ranking) {
    int i;
    ranking->numJogs = 0;
    for(i = 0; i < TAM_RANK; i ++) {
        ranking->jogador[i] = criaJogBasico(" ", -1);
    }
}

void insJogRank(Rank *ranking, Jogador jogador) {
    int i, pos = 0;
    if (ranking->numJogs < 5) {
        ranking->numJogs += 1;
    }
    for (i = ranking->numJogs - 1; i >= 0; i --) {
        if (ranking->jogador[i].pontos < jogador.pontos) {
            if (i < 4) {
                ranking->jogador[i + 1] = ranking->jogador[i];
            }
            ranking->jogador[i] = criaJogBasico(jogador.nome, jogador.pontos);
            pos = i + 1;
        }
    }
    if (pos > 0) {
        printf("O JOGADOR SE CLASSIFICOU EM %dº LUGAR DO RANKING!\n", pos);
    }
}
