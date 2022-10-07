#define TAM_NOME 13
#define LARGURA 1080
#define TAMANHO_FONTE 40

#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

#include "coordenada.h"
#include "textura.h"

#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    char nome[TAM_NOME];
    Localizacao posicao, posicaoInicial;
    int vidas, pontos, skin, pocoes, macas;
    bool temChave, facingLeft, temItemFase, temArmadura, temEspada;
} Jogador;

void leDadosJogador(Jogador *jog, Texturas textura);

#endif // JOGADOR_H
