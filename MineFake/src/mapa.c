#include "../headers/mapa.h"
#include <stdio.h>
#include <raylib.h>

#define TAM_MAX 256
#define TAMANHO_BLOCOS 64

void loadGameMap(int fase, Mapa *mapa) {
    char aux[TAM_MAX];
    int i, j, linhas = 0, colunas;
    char c;
    FILE *arquivo = NULL;

    if (fase == 1) {
        arquivo = fopen(MAPA1, "r");
    } else if (fase == 2) {
        arquivo = fopen(MAPA2, "r");
    } else if (fase == 3) {
        arquivo = fopen(MAPA3, "r");
    }

    if (arquivo == NULL) {
        printf("ERRO: Problema ao abrir o arquivo!");
    } else {
        while(feof(arquivo) == 0) {
            fgets(aux, sizeof(aux), arquivo);
            //fscanf(arquivo, "%s", &aux);
            if (aux == EOF) {
                printf("\nEncontrei o EOF!\n");
            } else {
                //printf("%d\n", strlen(aux));
                if (aux[strlen(aux) - 1] == '\n') {
                    aux[strlen(aux) - 1] = '\0';
                } else {
                    aux[strlen(aux)] = '\0';
                }
                strcpy(mapa->mapa[linhas], aux);
                linhas ++;
            }
        }
        mapa->dimensao.linha = linhas;
        mapa->dimensao.coluna = strlen(aux);
        mapa->fase = fase;
        mapa->baus = 0;
        mapa->porta = ' ';
        for (i = 0; i < mapa->dimensao.linha; i++) {
            for (j = 0; j < mapa->dimensao.coluna; j++) {
                if (mapa->mapa[i][j] == 'C') {
                    mapa->baus += 1;
                }
                if (mapa->mapa[i][j] == 'D') {
                    mapa->jogador.posicao = criaLocal(i * TAMANHO_BLOCOS, j * TAMANHO_BLOCOS);
                    mapa->jogador.posicaoInicial = criaLocal(i * TAMANHO_BLOCOS, j * TAMANHO_BLOCOS);
                }
            }
        }
        mapa->bausAbertos = 0;
        mapa->jogador.temChave = false;
        mapa->jogador.temItemFase = false;
    }
    printf("MAPA%d CARREGADO COM SUCESSO\n", mapa->fase);
    fclose(arquivo);
}

Jogador jogInit(Mapa mapa, Texturas textura) {
    Jogador jog;
    int l, c;
    jog.posicao = mapa.jogador.posicao;
    jog.posicaoInicial = mapa.jogador.posicaoInicial;
    jog.facingLeft = false;
    jog.temChave = false;
    jog.temItemFase = false;
    jog.temArmadura = false;
    jog.temEspada = false;
    jog.pontos = 0;
    jog.vidas = 3;
    jog.pontos = 0;
    jog.pocoes = 0;
    jog.macas = 0;
    leDadosJogador(&jog, textura);
    return jog;
}

void desenhaFundo(Texturas textura) {
    DrawTexture(textura.background, TAMANHO_BLOCOS, TAMANHO_BLOCOS, WHITE);
}

void desenhaMolduraMapa(Texturas textura) {
    int i = 0;
    for (i = 0; i < TAM_MOLDURA; i ++) {
        desenhaBloco(textura.blocos[0], 0, i);
        desenhaBloco(textura.blocos[0], TAM_MOLDURA - 1, i);
    }
    for (i = 1; i < TAM_MOLDURA - 1; i ++) {
        desenhaBloco(textura.blocos[0], i, 0);
        desenhaBloco(textura.blocos[0], i, TAM_MOLDURA - 1);
    }
}

void imprimeMapa(Mapa mapa, Texturas textura) {
    int l, c;

    for (l = 0; l < mapa.dimensao.linha; l++) {
        for (c = 0; c < mapa.dimensao.coluna; c++) {
            switch (mapa.mapa[l][c]) {
                case 49 ... 57:
                    desenhaBloco(textura.blocos[1], l + 1, c + 1);
                    break;
                case 'C':
                    desenhaBloco(textura.blocos[2], l + 1, c + 1);
                    break;
                case 'P':
                    if (mapa.jogador.temChave) {
                        desenhaBloco(textura.blocos[3], l + 1, c + 1);
                    }
                    break;
                case 'H':
                    if ((mapa.mapa[l][c - 1] == 'X') || (mapa.mapa[l][c + 1] == 'X')) {
                        desenhaBloco(textura.blocos[5], l + 1, c + 1);
                    }
                    desenhaBloco(textura.blocos[4], l + 1, c + 1);
                    break;
                case 'X':
                    if((l == 0) || (l == mapa.dimensao.linha - 1) || (c == 0) || (c == mapa.dimensao.coluna - 1)) {
                        desenhaBloco(textura.blocos[6], l + 1, c + 1);
                    } else if (mapa.mapa[l - 1][c] == 'X') {
                        desenhaBloco(textura.blocos[7], l + 1, c + 1);
                    } else {
                        desenhaBloco(textura.blocos[5], l + 1, c + 1);
                    }
                    break;
            }
        }
    }
}

void imprimeJog(Mapa mapa, Texturas textura, int frameCounter, bool animacaoHorizontal) {
    int aux;

    if (animacaoHorizontal) {
        aux = (frameCounter/4) % 4;
    } else {
        aux = 0;
    }

    if (mapa.jogador.facingLeft) {
        DrawTexture(textura.player[mapa.jogador.skin][0 + aux], mapa.jogador.posicao.coluna + TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura.player[mapa.jogador.skin][0 + aux].width)/2, mapa.jogador.posicao.linha + TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura.player[mapa.jogador.skin][0 + aux].height), WHITE);
    } else {
        DrawTexture(textura.player[mapa.jogador.skin][4 + aux], mapa.jogador.posicao.coluna + TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura.player[mapa.jogador.skin][4 + aux].width)/2, mapa.jogador.posicao.linha + TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura.player[mapa.jogador.skin][4 + aux].height), WHITE);
    }
}

void printJogInfo(Mapa mapa, Texturas textura) {
    char pontos[15];
    char vidas[5];
    char aux[3];

    sprintf(pontos, "PONTOS: %d", mapa.jogador.pontos);
    sprintf(vidas, " x %d", mapa.jogador.vidas);

    DrawText("JOGADOR", TAMANHO_BLOCOS*12 + ((LARGURA-TAMANHO_BLOCOS*12) - MeasureText("JOGADOR", TAMANHO_FONTE))/2, 50, TAMANHO_FONTE, BLACK);

    DrawTexture(textura.player[mapa.jogador.skin][8],
                TAMANHO_BLOCOS*12 + ((LARGURA-TAMANHO_BLOCOS*12) - textura.player[mapa.jogador.skin][8].width)/2,
                100, WHITE);

    DrawText(mapa.jogador.nome, TAMANHO_BLOCOS*12 + ((LARGURA-TAMANHO_BLOCOS*12) - MeasureText(mapa.jogador.nome, TAMANHO_FONTE - 10))/2, 375, TAMANHO_FONTE - 10, RED);

    DrawText(pontos, TAMANHO_BLOCOS*12 + 30, 450, TAMANHO_FONTE - 10, BLACK);

    DrawTexture(textura.interface[11], TAMANHO_BLOCOS*12 + 30, 510, WHITE);
    DrawText(vidas, TAMANHO_BLOCOS*12 + 78, 515, TAMANHO_FONTE, BLACK);

    DrawTexture(textura.interface[2], TAMANHO_BLOCOS*12 + 20, 600, WHITE);
    if (mapa.jogador.temEspada) {
        DrawTexture(textura.interface[10], TAMANHO_BLOCOS*12 + 29, 609, WHITE);
    }

    if (mapa.jogador.temArmadura) {
        DrawTexture(textura.interface[2], TAMANHO_BLOCOS*13 + 25, 600, WHITE);
        DrawTexture(textura.interface[0], TAMANHO_BLOCOS*13 + 33, 606, WHITE);
    } else {
        DrawTexture(textura.interface[1], TAMANHO_BLOCOS*13 + 25, 600, WHITE);
    }
    DrawTexture(textura.interface[2], TAMANHO_BLOCOS*14 + 30, 600, WHITE);
    if (mapa.jogador.macas > 0) {
        sprintf(aux, "%d", mapa.jogador.macas);
        DrawTexture(textura.interface[13], TAMANHO_BLOCOS*14 + 45, 611, WHITE);
        DrawText(aux, TAMANHO_BLOCOS*15 + 15, 640, TAMANHO_FONTE - 10, BLACK);
    }
    DrawTexture(textura.interface[2], TAMANHO_BLOCOS*15 + 35, 600, WHITE);
    if (mapa.jogador.pocoes > 0) {
        sprintf(aux, "%d", mapa.jogador.pocoes);
        DrawTexture(textura.interface[14], TAMANHO_BLOCOS*15 + 52, 611, WHITE);
        DrawText(aux, TAMANHO_BLOCOS*16 + 20, 640, TAMANHO_FONTE - 10, BLACK);
    }
}
