#include "../headers/jogador.h"

void leDadosJogador(Jogador *jog, Texturas textura) {
    int aux, selected = 0;
    char nomeJog[TAM_NOME];
    nomeJog[0] = '\0';

    while(!IsKeyReleased(KEY_ENTER) || strlen(nomeJog) == 0) {
        aux = strlen(nomeJog);
        if (strlen(nomeJog) < (TAM_NOME - 1)) {
            if (IsKeyPressed(KEY_A)) {
                nomeJog[aux] = 'A';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_B)) {
                nomeJog[aux] = 'B';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_C)) {
                nomeJog[aux] = 'C';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_D)) {
                nomeJog[aux] = 'D';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_E)) {
                nomeJog[aux] = 'E';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_F)) {
                nomeJog[aux] = 'F';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_G)) {
                nomeJog[aux] = 'G';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_H)) {
                nomeJog[aux] = 'H';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_I)) {
                nomeJog[aux] = 'I';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_J)) {
                nomeJog[aux] = 'J';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_K)) {
                nomeJog[aux] = 'K';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_L)) {
                nomeJog[aux] = 'L';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_M)) {
                nomeJog[aux] = 'M';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_N)) {
                nomeJog[aux] = 'N';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_O)) {
                nomeJog[aux] = 'O';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_P)) {
                nomeJog[aux] = 'P';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_Q)) {
                nomeJog[aux] = 'Q';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_R)) {
                nomeJog[aux] = 'R';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_S)) {
                nomeJog[aux] = 'S';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_T)) {
                nomeJog[aux] = 'T';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_U)) {
                nomeJog[aux] = 'U';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_V)) {
                nomeJog[aux] = 'V';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_W)) {
                nomeJog[aux] = 'W';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_X)) {
                nomeJog[aux] = 'X';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_Y)) {
                nomeJog[aux] = 'Y';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_Z)) {
                nomeJog[aux] = 'Z';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_ZERO)) {
                nomeJog[aux] = '0';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_ONE)) {
                nomeJog[aux] = '1';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_TWO)) {
                nomeJog[aux] = '2';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_THREE)) {
                nomeJog[aux] = '3';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_FOUR)) {
                nomeJog[aux] = '4';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_FIVE)) {
                nomeJog[aux] = '5';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_SIX)) {
                nomeJog[aux] = '6';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_SEVEN)) {
                nomeJog[aux] = '7';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_EIGHT)) {
                nomeJog[aux] = '8';
                nomeJog[aux + 1] = '\0';
            } else if (IsKeyPressed(KEY_NINE)) {
                nomeJog[aux] = '9';
                nomeJog[aux + 1] = '\0';
            }
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            nomeJog[aux - 1] = '\0';
        }
        BeginDrawing();
            DrawText("INSIRA SEU NOME", (LARGURA - MeasureText("INSIRA SEU NOME", 40))/2, 100, TAMANHO_FONTE, BLACK);
            ClearBackground(RAYWHITE);
            DrawText(nomeJog, (LARGURA - MeasureText(nomeJog, 40))/2, 175, TAMANHO_FONTE, RED);
            DrawText("SELECIONE SUA SKIN", (LARGURA - MeasureText("SELECIONE SUA SKIN", 40))/2, 300, TAMANHO_FONTE, BLACK);
            DrawTexture(textura.player[0][8],
                LARGURA/3 - textura.player[0][8].width/2,
                450, WHITE);
            DrawTexture(textura.player[1][8],
                LARGURA*2/3 - textura.player[1][8].width/2,
                450, WHITE);
        EndDrawing();
    }
    strcpy(jog->nome, nomeJog);

    while (IsKeyUp(KEY_ENTER)) {

        if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT)) {
            if (selected == 0){
                selected = 1;
            } else {
                selected = 0;
            }
        }

        BeginDrawing();
            DrawText("INSIRA SEU NOME", (LARGURA - MeasureText("INSIRA SEU NOME", 40))/2, 100, TAMANHO_FONTE, BLACK);
            ClearBackground(RAYWHITE);
            DrawText(nomeJog, (LARGURA - MeasureText(nomeJog, 40))/2, 175, TAMANHO_FONTE, RED);
            DrawText("SELECIONE SUA SKIN", (LARGURA - MeasureText("SELECIONE SUA SKIN", 40))/2, 300, TAMANHO_FONTE, BLACK);
            DrawTexture(textura.interface[3],
                        LARGURA*(selected + 1)/3 - textura.interface[3].width/2,
                        400, WHITE);
            DrawTexture(textura.player[0][8],
                LARGURA/3 - textura.player[0][8].width/2,
                450, WHITE);
            DrawTexture(textura.player[1][8],
                LARGURA*2/3 - textura.player[1][8].width/2,
                450, WHITE);
        EndDrawing();
    }

    jog->skin = selected;
}
