/*void movHorizontal() {
    (int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft, bool *animacao, int direcao) {
        const int accQueda = 5;
        const int framesSpeed = 2;

        *animacao = true;
        *frameCounter += 1;

        if (*frameCounter % framesSpeed == 0) {
            *tQueda += 1;
            *dQueda += accQueda * *tQueda;

            if (*dQueda <= h * TAMANHO_BLOCOS) {
                *yJog += accQueda * *tQueda;
            } else {
                *yJog += h * TAMANHO_BLOCOS - (*dQueda - accQueda * *tQueda);
                *animacao = false;
                *frameCounter = 0;
                *dQueda = 0;
                *tQueda = 0;
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
}
*/

void movVertical() {

}

void gravidade(int mapa[MAPA_L][MAPA_C], int *xJog, int *yJog, bool *animGravidade, int h, int *frameCounter, int *dQueda, int *tQueda, int *bau, int *porta) {

    const int accQueda = 5;
    const int framesSpeed = 2;

    *animGravidade = true;
    *frameCounter += 1;

    if (*frameCounter % framesSpeed == 0) {
        *tQueda += 1;
        *dQueda += accQueda * *tQueda;

        if (*dQueda <= h * TAMANHO_BLOCOS) {
            *yJog += accQueda * *tQueda;
        } else {
            *yJog += h * TAMANHO_BLOCOS - (*dQueda - accQueda * *tQueda);
            *animGravidade = false;
            *frameCounter = 0;
            *dQueda = 0;
            *tQueda = 0;
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
