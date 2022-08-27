#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <raylib.h>
#include <locale.h>
#include <time.h>

#include "maps/mapa1.c"
#include "functions/texture.c"
#include "functions/movimentos.c"
#include "functions/animation.c"

#define MAPA_L 30
#define MAPA_C 120
#define TAMANHO_BLOCOS 64
#define ALTURA 720
#define LARGURA 1280
#define NUM_TEXTURAS 21
//PRA FAZER A ANIMAÇÃO HORIZONTAL/VERTICAL VAI PRECISAR FAZER ALGUMA VARIÁVEL EXTRA DE MOVIMENTAÇÃO Q IMPEÇA OUTRAS COISAS DE ACONTECEREM
void carregaMapa(int mapa[MAPA_L][MAPA_C], int *linhas, int *colunas, int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft);
void imprimeMapa(int mapa[MAPA_L][MAPA_C], int linhas, int colunas, Texture2D textura[NUM_TEXTURAS]);
void busca_porta(int mapa[MAPA_L][MAPA_C], int linhas, int colunas, char porta, int *x_porta, int *y_porta);

int main() {
    int mapa[MAPA_L][MAPA_C] = { 0 }, porta, bau, linhas, colunas, xJog, yJog, i;
    bool close = false, facingLeft, animGravidade = false, caindo = false, animacao = false;
    Texture2D textura[NUM_TEXTURAS];
    int frameCounter = 0, dQueda = 0, tQueda = 0, h = 0;

    setlocale(LC_ALL, "Portuguese");
    InitWindow(LARGURA, ALTURA, "raylib [core] example - basic window");

    carregaTexturas(textura);

    SetTargetFPS(60);

    carregaMapa(mapa, &linhas, &colunas, &porta, &bau, &xJog, &yJog, &facingLeft);
    while (!close && !WindowShouldClose()) {
        if (h > 0) {
            gravidade(mapa, &xJog, &yJog, &animGravidade, h, &frameCounter, &dQueda, &tQueda, &bau, &porta);
        }

        if (!animGravidade) {
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
                if (bau != 0) {
                    abreBau(mapa, &bau, &xJog, &yJog, &animacao);
                }

                if (porta != 0) {
                    abrePorta(mapa, &porta, &xJog, &yJog, linhas, colunas, &animacao);
                }

                if (mapa[yJog / TAMANHO_BLOCOS][xJog / TAMANHO_BLOCOS] == 15) {
                    jogCima(mapa, &porta, &bau, &xJog, &yJog, &animacao);
                }
            }
            if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                if (mapa[yJog /TAMANHO_BLOCOS + 1][xJog / TAMANHO_BLOCOS] == 15) {
                    jogBaixo(mapa, &porta, &bau, &xJog, &yJog, &animacao);
                }
            }
            if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                //printf ("\n%d\n\n", mapa[yJog / TAMANHO_BLOCOS][xJog / TAMANHO_BLOCOS - 1]);
                jogEsquerda(mapa, &porta, &bau, &xJog, &yJog, &facingLeft, &animacao);
                //printf("%d\n%d\n\n", yJog, xJog);
            }
            if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                jogDireita(mapa, &porta, &bau, &xJog, &yJog, &facingLeft, &animacao);
            }
            if (IsKeyPressed(KEY_SPACE)) {
                //printf("\n%d\n\n", altura(mapa, &xJog, &yJog));
                //close = true;
            }
            h = altura(mapa, &xJog, &yJog);
        }


        BeginDrawing();
            ClearBackground(WHITE);
            imprimeMapa(mapa, linhas, colunas, textura);
            imprimeJogador(xJog, yJog, textura, facingLeft);
        EndDrawing();


    }
    CloseWindow();
    return 0;
}

void carregaMapa(int mapa[MAPA_L][MAPA_C], int *linhas, int *colunas, int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft) {
    blocosMapaI(mapa, linhas, colunas, porta, bau, xJog, yJog, facingLeft);
}

void imprimeMapa(int mapa[MAPA_L][MAPA_C], int linhas, int colunas, Texture2D textura[NUM_TEXTURAS]) {
    int i = 0, j = 0, posX, posY;

    posX = 0;
    posY = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (mapa[i][j] != 00) {
                DrawTexture(textura[mapa[i][j]], posX +  j * TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura[mapa[i][j]].width)/2, posY + i * TAMANHO_BLOCOS, WHITE);
            }
        }
    }
}

void imprimeJogador(int xJog, int yJog, Texture2D textura[NUM_TEXTURAS], bool facingLeft) {
    if (facingLeft) {
        DrawTexture(textura[19], xJog, yJog, WHITE);
    } else {
        DrawTexture(textura[18], xJog, yJog, WHITE);
    }
}
