#include "../headers/menu.h"

void selecionaMenu(int selected, Mapa *mapa, Texturas textura, bool *close, bool *ranking) {
    switch(selected) {
    case 0:
        loadGameMap(1, mapa);
        mapa->jogador = jogInit(*mapa, textura);
        *close = true;
        break;
    case 1:
        loadGame(mapa, textura);
        *close = true;
        break;
    case 2:
        printf("Carregando o Ranking\n");
        *ranking = true;
        break;
    case 3:
        printf("Encerrando o jogo\n");
        *close = true;
    }
}

void desenhaMenu(int selected) {
    char str[TAM_TEXTO + 2];
    char texto[OPCOES][TAM_TEXTO] = {"NOVO JOGO", "CARREGAR JOGO", "RANKING PONTOS", "SAIR"};
    int i;

    for (i = 0; i < 4; i++) {
        if (selected == i) {
            sprintf(str, "[%s]", texto[i]);
            DrawText(str, (LARGURA - MeasureText(str, TAMANHO_FONTE))/2, 220 + DISTANCIA_ENTRE_OPCOES * i, TAMANHO_FONTE, RED);
        }
        else {
            DrawText(texto[i], (LARGURA - MeasureText(texto[i], TAMANHO_FONTE))/2, 220 + DISTANCIA_ENTRE_OPCOES * i, TAMANHO_FONTE, GREEN);
        }
    }
}

void desenhaEncerramento(bool win, Sound som[NUM_SONS]) {
    bool encerramento = false;
    char str[TEXTO_ENCERRAMENTO];

    if (win) {
        strcpy(str, "VOCE VENCEU!");
        PlaySound(som[1]);
    } else {
        strcpy(str, "A NAO! VOCE MORREU!");
        PlaySound(som[10]);
    }
    while (!encerramento && !WindowShouldClose()) {
            if (!IsKeyUp(KEY_ENTER)) {
                encerramento = true;
            } else {
                BeginDrawing();
                    if (win) {
                        ClearBackground(GREEN);
                    } else {
                        ClearBackground(RED);
                    }
                    DrawText(str, (LARGURA - MeasureText(str, TAMANHO_FONTE + 10))/2, (ALTURA - (TAMANHO_FONTE + 10))/2, TAMANHO_FONTE + 10, WHITE);
                    DrawText("Pressione ENTER para prosseguir", (LARGURA - MeasureText("Pressione ENTER para prosseguir", TAMANHO_FONTE - 20))/2, (ALTURA - (TAMANHO_FONTE + 50))/2 + 80, TAMANHO_FONTE - 20, WHITE);
                EndDrawing();
            }
        }
}

void imprimeRanking(Rank ranking) {
    int i;
    char pontos[6];

    DrawText("RANKING", (LARGURA - MeasureText("RANKING", TAMANHO_FONTE + 10))/2, 100, TAMANHO_FONTE + 10, RED);
    for(i = 0; i < ranking.numJogs; i++) {
        sprintf(pontos, "%d", ranking.jogador[i].pontos);
        DrawText(pontos, LARGURA/2 - (MeasureText(pontos, TAMANHO_FONTE) + 25), 100 + (i + 1)*DISTANCIA_ENTRE_RANKINGS, TAMANHO_FONTE, RED);
        DrawText(ranking.jogador[i].nome, LARGURA/2 + 25, 100 + (i + 1)*DISTANCIA_ENTRE_RANKINGS, TAMANHO_FONTE, RED);
    }
}
