#define MAPA_L 30
#define MAPA_C 120
#define TAMANHO_BLOCOS 64

void jogCima(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *animacao) {
    if (mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS] != 15) {
        switch (mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS]) {
            case 01 ... 10:
                *porta = mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                break;
            case 11 ... 13:
                *bau = mapa[(*yJog - 1) / TAMANHO_BLOCOS][*xJog / TAMANHO_BLOCOS];
                break;
        }
    }
    *yJog = *yJog - TAMANHO_BLOCOS;
}

void jogBaixo(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *animacao) {
    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;

    if (mapa[*yJog][*xJog] != 15) {
        *bau = 0;
        *porta = 0;
    }
    *yJog = *yJog + TAMANHO_BLOCOS;
}

void jogEsquerda(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft, bool *animacao) {
    if (*facingLeft) {


        if (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1] < 16) {
            switch (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1]) {
                case 00:
                    *porta = 0;
                    *bau = 0;
                    break;
                case 01 ... 10:
                    *porta = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1];
                    *bau = 0;
                    break;
                case 11 ... 13:
                    *porta = 0;
                    *bau = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) - 1];
                    break;
                case 15:
                    *porta = 0;
                    *bau= 0;
                    break;
            }
            *xJog = *xJog - TAMANHO_BLOCOS;
        }

    } else {
        *facingLeft = true;
    }
}

void jogDireita(int mapa[MAPA_L][MAPA_C], int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft, bool *animacao) {
    if (*facingLeft) {
        *facingLeft = false;
    } else {
        if (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1] < 16) {
            switch (mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1]) {
                case 00:
                    *porta = 0;
                    *bau = 0;
                    break;
                case 01 ... 10:
                    *porta = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1];
                    *bau = 0;
                    break;
                case 11 ... 13:
                    *porta = 0;
                    *bau = mapa[*yJog / TAMANHO_BLOCOS][(*xJog / TAMANHO_BLOCOS) + 1];
                    break;
                case 15:
                    *porta = 0;
                    *bau = 0;
                    break;
            }
            *xJog = *xJog + TAMANHO_BLOCOS;
        }
    }

}


void abrePorta(int mapa[MAPA_L][MAPA_C], int *porta, int *xJog, int *yJog, int linhas, int colunas, bool *animacao) {
    int i = 0, j = 0, xPorta, yPorta;
    bool rodar = true;

    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if ((mapa[i][j] == *porta) && ((i != *yJog) || (j != *xJog))) {
                xPorta = j;
                yPorta = i;
            }
        }
    }

    *xJog = xPorta;
    *yJog = yPorta;
    *xJog = *xJog * TAMANHO_BLOCOS;
    *yJog = *yJog * TAMANHO_BLOCOS;
}


void abreBau(int mapa[MAPA_L][MAPA_C], int *bau, int *xJog, int *yJog, bool *animacao) {

    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;
    switch (mapa[*yJog][*xJog]) {
        case 11:
            printf("Você achou a chave!\n");
            break;
        case 12:
            printf("Você explodiu!\n");
            break;
        case 13:
            printf("Você achou um item bacana!\n");
            break;
    }
    *xJog = *xJog * TAMANHO_BLOCOS;
    *yJog = *yJog * TAMANHO_BLOCOS;
}

int altura(int mapa[MAPA_L][MAPA_C], int *xJog, int *yJog) {
    int h = 0;
    *xJog = *xJog / TAMANHO_BLOCOS;
    *yJog = *yJog / TAMANHO_BLOCOS;
    while (mapa[*yJog + (h + 1)][*xJog] < 15) {
        h += 1;
    }
    *xJog = *xJog * TAMANHO_BLOCOS;
    *yJog = *yJog * TAMANHO_BLOCOS;
    return h;
}
