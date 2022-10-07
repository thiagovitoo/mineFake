#include "../headers/animacao.h"

void movVertical(Mapa *mapa, bool *animacaoVertical, int direcao, int *frameCounter, int *dMov) {
    const int velocidade = 4;
    const int framesSpeed = 2;

    *animacaoVertical = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *dMov += velocidade;
        mapa->jogador.posicao.linha += velocidade * direcao;

        if (*dMov >= TAMANHO_BLOCOS) {
            *animacaoVertical = false;
            *frameCounter = 0;
            *dMov = 0;
        }
    }
}

void movHorizontal(Mapa *mapa, bool *animacaoHorizontal, int direcao, int *frameCounter, int *dMov) {
    const int velocidade = 4;
    const int framesSpeed = 2;

    *animacaoHorizontal = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *dMov += velocidade;
        mapa->jogador.posicao.coluna += (velocidade * direcao);
        if (*dMov >= TAMANHO_BLOCOS) {
            *animacaoHorizontal = false;
            *frameCounter = 0;
            *dMov = 0;
        }
    }
}

void gravidade(Mapa *mapa, bool *caindo, int h, int *frameCounter, int *dMov, int *tMov, int *alt, Sound som[NUM_SONS]) {
    const int accQueda = 5;
    const int framesSpeed = 2;

    int j = GetRandomValue(1, 10);
    *caindo = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *tMov += 1;
        *dMov += accQueda * *tMov;

        if (*dMov < h * TAMANHO_BLOCOS) {
            mapa->jogador.posicao.linha += accQueda * *tMov;
        } else {
            mapa->jogador.posicao.linha += h * TAMANHO_BLOCOS - (*dMov - accQueda * *tMov);
            *caindo = false;
            *frameCounter = 0;
            *dMov = 0;
            *tMov = 0;
            if (h >= 3) {
                if ((!mapa->jogador.temArmadura) || (j > 3)) {
                    mapa->jogador.vidas --;
                    mapa->jogador.posicao = mapa->jogador.posicaoInicial;
                    PlaySound(som[7]);
                } else {
                    PlaySound(som[6]);
                }
            } else {
                PlaySound(som[6]);
            }
            switch (mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS]) {
                case 49 ... 57:
                    mapa->porta = mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS];
                    break;
            }
            *alt = 0;
        }
    }
}

void exibeItem() {

}
