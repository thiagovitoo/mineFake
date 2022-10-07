#include "../headers/movimentos.h"

void jogCima(Mapa *mapa, bool *animacaoVertical, int *dMov, int *frameCounter) {
    if (mapa->mapa[(mapa->jogador.posicao.linha - 1) / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS] != 'H') {
        switch (mapa->mapa[(mapa->jogador.posicao.linha - 1) / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS]) {
            case 49 ... 57:
                mapa->porta = mapa->mapa[(mapa->jogador.posicao.linha - 1) / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS];
                break;
        }
    }
    movVertical(mapa, animacaoVertical, -1, frameCounter, dMov);
}

void jogBaixo(Mapa *mapa, bool *animacaoVertical, int *dMov, int *frameCounter) {
    mapa->porta = '0';
    movVertical(mapa, animacaoVertical, 1, frameCounter, dMov);
}


void jogEsquerda(Mapa *mapa, bool *animacaoHorizontal, int *dMov, int *frameCounter) {
    if (mapa->jogador.facingLeft) {
        if (mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) - 1] != 'X') {
            switch (mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) - 1]) {
                case 49 ... 57:
                    mapa->porta = mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) - 1];
                    break;
                default:
                    mapa->porta = ' ';
            }
            movHorizontal(mapa, animacaoHorizontal, -1, frameCounter, dMov);
        }

    } else {
        mapa->jogador.facingLeft = true;
    }
}

void jogDireita(Mapa *mapa, bool *animacaoHorizontal, int *dMov, int *frameCounter) {
    if (mapa->jogador.facingLeft) {
        mapa->jogador.facingLeft = false;
    } else {
        if (mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) + 1] != 'X') {
            switch (mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) + 1]) {
                case 49 ... 57:
                    mapa->porta = mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][(mapa->jogador.posicao.coluna / TAMANHO_BLOCOS) + 1];
                    break;
                default:
                    mapa->porta = ' ';
            }
            movHorizontal(mapa, animacaoHorizontal, 1, frameCounter, dMov);
        }
    }

}

void abrePorta(Mapa *mapa) {
    int i = 0, j = 0, xPorta, yPorta;
    bool rodar = true;

    for (i = 0; i < mapa->dimensao.linha; i++) {
        for (j = 0; j < mapa->dimensao.coluna; j++) {
            if ((mapa->mapa[i][j] == mapa->porta) && ((i != (mapa->jogador.posicao.linha / TAMANHO_BLOCOS)) || (j != mapa->jogador.posicao.coluna / TAMANHO_BLOCOS))) {
                xPorta = j;
                yPorta = i;
            }
        }
    }
    mapa->jogador.posicao.linha = yPorta * TAMANHO_BLOCOS;
    mapa->jogador.posicao.coluna = xPorta * TAMANHO_BLOCOS;
}

Item abreBau(Mapa *mapa, Item itens[NUM_ITENS], Sound som[NUM_SONS], bool *animacaoBau) {
    int i = GetRandomValue(1, 10);
    int j = GetRandomValue(1, 10);
    Item item;

    mapa->mapa[mapa->jogador.posicao.linha / TAMANHO_BLOCOS][mapa->jogador.posicao.coluna / TAMANHO_BLOCOS] = ' ';
    mapa->bausAbertos += 1;

    if ((mapa->baus - mapa->bausAbertos == 2) && (!(mapa->jogador.temItemFase))) {
        item = getLevelItem(mapa, mapa->fase, itens);
        printf("Você recebeu um(a) %s!\n", item.nome);
        mapa->jogador.temItemFase = true;
        PlaySound(som[2]);
    } else if ((mapa->baus - mapa->bausAbertos == 1) && (!(mapa->jogador.temChave))) {
        item = getKey(itens);
        printf("Você encontrou a chave!\n");
        mapa->jogador.temChave = true;
        PlaySound(som[2]);
    } else {
        switch (i) {
            case 1 ... 3:
                printf("Você achou uma bomba e explodiu!\n");
                PlaySound(som[11]);
                if (!mapa->jogador.temArmadura || j > 3) {
                    mapa->jogador.vidas --;
                    mapa->jogador.posicao = mapa->jogador.posicaoInicial;
                }
                break;
            case 4 ... 5:
                if (!(mapa->jogador.temItemFase)) {
                    item = getLevelItem(mapa, mapa->fase, itens);
                    printf("Você recebeu um(a) %s!\n", item.nome);
                    mapa->jogador.temItemFase = true;
                    PlaySound(som[2]);
                } else if (!(mapa->jogador.temChave)) {
                    item = getKey(itens);
                    printf("Você encontrou a chave!\n");
                    mapa->jogador.temChave = true;
                    PlaySound(som[2]);
                } else {
                    item = getRandomItem(mapa, mapa->fase, itens);
                    printf("Você encontrou um(a) %s!\n", item.nome);
                    PlaySound(som[2]);
                }
                break;
            case 6 ... 10:
                item = getRandomItem(mapa, mapa->fase, itens);
                printf("Você encontrou um(a) %s!\n", item.nome);
                PlaySound(som[2]);
                break;
        }
    }
    return item;
}

int altura(Mapa mapa) {
    int h = 0;
    while ((mapa.mapa[(mapa.jogador.posicao.linha / TAMANHO_BLOCOS) + (h + 1)][(mapa.jogador.posicao.coluna / TAMANHO_BLOCOS)] != 'H') && (mapa.mapa[(mapa.jogador.posicao.linha / TAMANHO_BLOCOS) + (h + 1)][(mapa.jogador.posicao.coluna / TAMANHO_BLOCOS)] != 'X')) {
        h += 1;
    }
    return h;
}
