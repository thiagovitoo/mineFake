void movHorizontal(int *xJog, bool *animacaoHorizontal, int direcao, int *frameCounter, int *dMov) {
    const int velocidade = 4;
    const int framesSpeed = 2;

    *animacaoHorizontal = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *dMov += velocidade;
        *xJog += (velocidade * direcao);

        if (*dMov >= TAMANHO_BLOCOS) {
            *animacaoHorizontal = false;
            *frameCounter = 0;
            *dMov = 0;
        }
    }
}

void movVertical(int *yJog, bool *animacaoVertical, int direcao, int *frameCounter, int *dMov) {
    const int velocidade = 4;
    const int framesSpeed = 2;

    *animacaoVertical = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *dMov += velocidade;
        *yJog += (velocidade * direcao);

        if (*dMov >= TAMANHO_BLOCOS) {
            *animacaoVertical = false;
            *frameCounter = 0;
            *dMov = 0;
        }
    }
}

void gravidade(int mapa[MAPA_L][MAPA_C], int *xJog, int *yJog, bool *caindo, int h, int *frameCounter, int *dMov, int *tMov, int *bau, int *porta) {

    const int accQueda = 5;
    const int framesSpeed = 2;

    *caindo = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *tMov += 1;
        *dMov += accQueda * *tMov;

        if (*dMov < h * TAMANHO_BLOCOS) {
            *yJog += accQueda * *tMov;
        } else {
            *yJog += h * TAMANHO_BLOCOS - (*dMov - accQueda * *tMov);
            *caindo = false;
            *frameCounter = 0;
            *dMov = 0;
            *tMov = 0;
            switch (mapa[*yJog / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS]) {
                case 01 ... 10:
                    *porta = mapa[*yJog / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                    break;
                case 11 ... 13:
                    *bau = mapa[*yJog / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                    break;
            }
        }
    }
}
