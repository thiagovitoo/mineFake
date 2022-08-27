/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 9 / EXERCÍCIO 1

    ALUNO: FERNANDO KASPARY FINK
    MATRÍCULA: 00342166

*/

#include "raylib.h"
#include "stdio.h"
#include "locale.h"

#define ALTURA 720
#define LARGURA 1440
#define OPCOES 4
#define TAMANHO_FONTE 40
#define TAM_TEXTO 20
#define DISTANCIA_ENTRE_OPCOES 100

void DesenhaMenu(int selected) {
    char str[TAM_TEXTO + 2];
    char texto[OPCOES][TAM_TEXTO] = {"NOVO JOGO", "CARREGAR JOGO", "RANKING PONTOS", "SAIR"};
    int i;

    for (i = 0; i < 4; i ++) {
        if (selected == i) {
            sprintf(str, "[%s]", texto[i]);
            DrawText(str, (LARGURA - MeasureText(str, TAMANHO_FONTE))/2, 220 + DISTANCIA_ENTRE_OPCOES * i, TAMANHO_FONTE, RED);
        } else {
            DrawText(texto[i], (LARGURA - MeasureText(texto[i], TAMANHO_FONTE))/2, 220 + DISTANCIA_ENTRE_OPCOES * i, TAMANHO_FONTE, GREEN);
        }
    }
}

bool ExibirMensagem(int selected) {
    switch(selected) {
        case 0:
            printf("Carregando novo jogo\n");
            return false;
            break;
        case 1:
            printf("Carregando tela Saves\n");
            return false;
            break;
        case 2:
            printf("Carregando tela Ranking Pontos\n");
            return false;
            break;
        case 3:
            printf("Encerrando aplicação\n");
            return true;
    }
}

int main(void) {

    InitWindow(LARGURA, ALTURA, "raylib [core] example - basic window");
    SetTargetFPS(60);
    setlocale(LC_ALL, "Portuguese");

    int selected = 0;
    bool close = false;

    while (!close) {
        if (IsKeyPressed(KEY_UP)) {
            if (selected > 0) {
                selected--;
            } else {
                selected = 3;
            }
        }
        if (IsKeyPressed(KEY_DOWN)) {
            if (selected < 3) {
                selected++;
            } else {
                selected = 0;
            }
        }

        if (IsKeyPressed(KEY_ENTER)) {
            close = ExibirMensagem(selected);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DesenhaMenu(selected);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
