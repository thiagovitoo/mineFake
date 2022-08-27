#define MAPA_L 30
#define MAPA_C 120
#define TAMANHO_BLOCOS 64

void blocosMapaI(int mapa[MAPA_L][MAPA_C], int *linhas, int *colunas, int *porta, int *bau, int *xJog, int *yJog, bool *facingLeft) {
    *linhas = 10;
    *colunas = 10;
    *porta = 0;
    *bau = 0;
    *xJog = 1 * TAMANHO_BLOCOS;
    *yJog = 8 * TAMANHO_BLOCOS;
    *facingLeft = false;

    mapa[0][0] = 17;
    mapa[0][1] = 17;
    mapa[0][2] = 17;
    mapa[0][3] = 17;
    mapa[0][4] = 17;
    mapa[0][5] = 17;
    mapa[0][6] = 17;
    mapa[0][7] = 17;
    mapa[0][8] = 17;
    mapa[0][9] = 17;

    mapa[1][0] = 17;
    mapa[1][1] = 01;
    mapa[1][2] = 00;
    mapa[1][3] = 11;
    mapa[1][4] = 00;
    mapa[1][5] = 00;
    mapa[1][6] = 13;
    mapa[1][7] = 02;
    mapa[1][8] = 00;
    mapa[1][9] = 17;

    mapa[2][0] = 17;
    mapa[2][1] = 16;
    mapa[2][2] = 15;
    mapa[2][3] = 16;
    mapa[2][4] = 00;
    mapa[2][5] = 00;
    mapa[2][6] = 16;
    mapa[2][7] = 16;
    mapa[2][8] = 00;
    mapa[2][9] = 17;

    mapa[3][0] = 17;
    mapa[3][1] = 12;
    mapa[3][2] = 15;
    mapa[3][3] = 00;
    mapa[3][4] = 00;
    mapa[3][5] = 00;
    mapa[3][6] = 00;
    mapa[3][7] = 01;
    mapa[3][8] = 00;
    mapa[3][9] = 17;

    mapa[4][0] = 17;
    mapa[4][1] = 16;
    mapa[4][2] = 16;
    mapa[4][3] = 00;
    mapa[4][4] = 15;
    mapa[4][5] = 16;
    mapa[4][6] = 15;
    mapa[4][7] = 16;
    mapa[4][8] = 00;
    mapa[4][9] = 17;

    mapa[5][0] = 17;
    mapa[5][1] = 00;
    mapa[5][2] = 00;
    mapa[5][3] = 00;
    mapa[5][4] = 15;
    mapa[5][5] = 00;
    mapa[5][6] = 15;
    mapa[5][7] = 00;
    mapa[5][8] = 00;
    mapa[5][9] = 17;

    mapa[6][0] = 17;
    mapa[6][1] = 00;
    mapa[6][2] = 00;
    mapa[6][3] = 00;
    mapa[6][4] = 15;
    mapa[6][5] = 00;
    mapa[6][6] = 15;
    mapa[6][7] = 12;
    mapa[6][8] = 02;
    mapa[6][9] = 17;

    mapa[7][0] = 17;
    mapa[7][1] = 00;
    mapa[7][2] = 15;
    mapa[7][3] = 16;
    mapa[7][4] = 16;
    mapa[7][5] = 00;
    mapa[7][6] = 16;
    mapa[7][7] = 16;
    mapa[7][8] = 16;
    mapa[7][9] = 17;

    mapa[8][0] = 17;
    mapa[8][1] = 00;
    mapa[8][2] = 15;
    mapa[8][3] = 00;
    mapa[8][4] = 20;
    mapa[8][5] = 00;
    mapa[8][6] = 00;
    mapa[8][7] = 00;
    mapa[8][8] = 14;
    mapa[8][9] = 17;

    mapa[9][0] = 17;
    mapa[9][1] = 17;
    mapa[9][2] = 17;
    mapa[9][3] = 17;
    mapa[9][4] = 17;
    mapa[9][5] = 17;
    mapa[9][6] = 17;
    mapa[9][7] = 17;
    mapa[9][8] = 17;
    mapa[9][9] = 17;
}
