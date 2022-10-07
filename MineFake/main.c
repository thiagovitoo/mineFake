#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <raylib.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>

#include "headers/coordenada.h"
#include "headers/jogador.h"
#include "headers/mapa.h"
#include "headers/menu.h"
#include "headers/animacao.h"
#include "headers/movimentos.h"
#include "headers/textura.h"
#include "headers/item.h"

#define MAPA_L 30
#define MAPA_C 120
#define TAMANHO_BLOCOS 64
#define ALTURA 768
#define LARGURA 1080
#define NUM_TEXTURAS 20
#define TAM_FONTE_TELA_ENCERRAMENTO
#define NUM_SONS 20

//CRIAR STRUCT TEXTURA COM OS DIFERENTES TIPOS (BLOCO,JOGADOR, ISSO, AQUILO)

int main()
{
    Mapa mapa;
    Texturas textura;
    Music music;
    Sound som[NUM_SONS];
    Item item[NUM_ITENS];
    Item itemAtual;
    Rank ranking;
    bool close = false, caindo = false, animacaoHorizontal = false, animacaoVertical = false, pause = false, fechaMenu = false, jogoNovo = false;
    bool levelUp = false, win = false, morte = false, exit = false, rank = false, animacaoBau = false;
    int frameCounter = 0, dMov = 0, tMov = 0, h = 0, direcao, i, selected = 0;

    setlocale(LC_ALL, "Portuguese");
    InitWindow(LARGURA, ALTURA, "raylib [core] example - basic window");

    InitAudioDevice();

    loadTextures(&textura);
    loadSounds(som);
    loadItens(item, textura);
    rankingInit(&ranking);
    loadRanking(&ranking);
    music = LoadMusicStream("assets/sounds/gloriousMorning.mp3");

    SetTargetFPS(60);
    //loadGameMap(1, &mapa);
    PlayMusicStream(music);

    while (!fechaMenu) {
        if (!rank) {
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
                PlaySound(som[4]);
                selecionaMenu(selected, &mapa, textura, &fechaMenu, &rank);
            }
        } else {
            if (IsKeyPressed(KEY_ENTER)) {
                PlaySound(som[4]);
                rank = false;
            }
        }

        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            if (rank) {
                imprimeRanking(ranking);
            } else {
                desenhaMenu(selected);
            }
        EndDrawing();
    }
    if (selected == 3) {
        close = true;
        exit = true;
    }

    while (!win && !morte && !exit && !WindowShouldClose()) {
        while (!close && !WindowShouldClose()) {
            UpdateMusicStream(music);
            if (h > 0) {
                gravidade(&mapa, &caindo, h, &frameCounter, &dMov, &tMov, &h, som);
            } else if (animacaoHorizontal) {
                movHorizontal(&mapa, &animacaoHorizontal, direcao, &frameCounter, &dMov);
            } else if (animacaoVertical) {
                movVertical(&mapa, &animacaoVertical, direcao, &frameCounter, &dMov);
            } else if (!animacaoBau) {
                h = altura(mapa);
                if (h == 0) {
                    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                        if (mapa.mapa[mapa.jogador.posicao.linha / TAMANHO_BLOCOS][mapa.jogador.posicao.coluna / TAMANHO_BLOCOS] == 'H') {
                            direcao = -1;
                            jogCima(&mapa, &animacaoVertical, &dMov, &frameCounter);
                        } else if (IsKeyPressed(KEY_UP)) {
                            if (mapa.mapa[mapa.jogador.posicao.linha / TAMANHO_BLOCOS][mapa.jogador.posicao.coluna / TAMANHO_BLOCOS] == 'C') {
                                itemAtual = abreBau(&mapa, item, som, &animacaoBau);
                                PlaySound(som[0]);
                            }
                            else if (mapa.porta != ' ') {
                                abrePorta(&mapa);
                            } else if ((mapa.mapa[mapa.jogador.posicao.linha / TAMANHO_BLOCOS][mapa.jogador.posicao.coluna / TAMANHO_BLOCOS] == 'P') && mapa.jogador.temChave) {
                                if (mapa.fase == 3) {
                                    win = true;
                                    close = true;
                                } else {
                                    levelUp = true;
                                    close = true;
                                }
                            }
                        }
                    } else if (IsKeyDown(KEY_DOWN)) {
                        if (mapa.mapa[mapa.jogador.posicao.linha /TAMANHO_BLOCOS + 1][mapa.jogador.posicao.coluna / TAMANHO_BLOCOS] == 'H') {
                            direcao = 1;
                            jogBaixo(&mapa, &animacaoVertical, &dMov, &frameCounter);
                        }
                    } else if (IsKeyDown(KEY_LEFT)) {
                        direcao = -1;
                        jogEsquerda(&mapa, &animacaoHorizontal, &dMov, &frameCounter);
                    }
                    else if (IsKeyDown(KEY_RIGHT)) {
                        direcao = 1;
                        jogDireita(&mapa, &animacaoHorizontal, &dMov, &frameCounter);
                    } else if (IsKeyPressed(KEY_THREE)) {
                        useItem(&mapa, item[3], som);
                    } else if (IsKeyPressed(KEY_FOUR)) {
                        useItem(&mapa, item[4], som);
                    } else if (IsKeyPressed(KEY_R)) {
                        if (!comparaLocal(mapa.jogador.posicao, mapa.jogador.posicaoInicial)) {
                            mapa.jogador.posicao = mapa.jogador.posicaoInicial;
                            if (mapa.jogador.pontos >= 50) {
                                mapa.jogador.pontos -= 50;
                            }
                        }
                    } else if (IsKeyPressed(KEY_ESCAPE)) {
                        exit = true;
                    }
                }
            }

            BeginDrawing();
            ClearBackground(LIGHTGRAY);
            desenhaFundo(textura);
            imprimeMapa(mapa, textura);
            desenhaMolduraMapa(textura);
            imprimeJog(mapa, textura, frameCounter, animacaoHorizontal);
            printJogInfo(mapa, textura);
            if (animacaoBau) {
                //imprimeItem()
            }
            EndDrawing();

            if (mapa.jogador.vidas == 0){
                morte = true;
                close = true;
            }
        }

        if (levelUp) {
            loadGameMap(mapa.fase + 1, &mapa);
            levelUp = false;
            close = false;
            saveGame(mapa);
            PlaySound(som[3]);
        }
    }

    if (!exit || win || morte) {
        desenhaEncerramento(win, som);
        deletaJogo();
    }

    if (win) {
        insJogRank(&ranking, mapa.jogador);
        saveRanking(ranking);
        win = false;
        while (!IsKeyPressed(KEY_ESCAPE)) {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            imprimeRanking(ranking);
        EndDrawing();
    }
    }

    UnloadMusicStream(music);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
