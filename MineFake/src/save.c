#include "../headers/save.h"

void saveGame(Mapa mapa) {
    int l;
    FILE *file;
    file = fopen(FILE_PATH_MAPA, "wb");

    if (file) {
        fwrite(&(mapa.jogador), sizeof(Jogador), 1, file);
        fwrite(&(mapa.dimensao), sizeof(Localizacao), 1, file);
        fwrite(&(mapa.fase), sizeof(int), 1, file);
        fwrite(&(mapa.baus), sizeof(int), 1, file);
        fwrite(&(mapa.bausAbertos), sizeof(int), 1, file);
        fwrite(&(mapa.porta), sizeof(char), 1, file);
        for (l = 0; l < mapa.dimensao.linha; l++) {
            fwrite(&(mapa.mapa[l]), sizeof(char), mapa.dimensao.coluna, file);
        }
        printf("Jogo Salvo\n");
    } else {
        printf("Erro ao salvar progresso\n");
    }

    fclose(file);
}

void loadGame(Mapa *mapa, Texturas textura) {
    int l;
    FILE *file;
    file = fopen(FILE_PATH_MAPA, "r");

    if(file) {
        fread(&(mapa->jogador), sizeof(Jogador), 1, file);
        fread(&(mapa->dimensao), sizeof(Localizacao), 1, file);
        fread(&(mapa->fase), sizeof(int), 1, file);
        fread(&(mapa->baus), sizeof(int), 1, file);
        fread(&(mapa->bausAbertos), sizeof(int), 1, file);
        fread(&(mapa->porta), sizeof(char), 1, file);
        for (l = 0; l < mapa->dimensao.linha; l++) {
            fread(&(mapa->mapa[l]), sizeof(char), mapa->dimensao.coluna, file);
            mapa->mapa[l][mapa->dimensao.coluna] = '\0';
        }
        printf("SAVE LIDO COM SUCESSO\n");
    } else {
        printf("NÃO FOI POSSÍVEL ABRIR O ARQUIVO \"%s\"\n", FILE_PATH_MAPA);
        printf("INICIANDO UM NOVO JOGO\n");
        loadGameMap(1, mapa);
        mapa->jogador = jogInit(*mapa, textura);
    }
    fclose(file);
}

void saveRanking(Rank ranking) {
    int i;
    FILE *file;
    file = fopen(FILE_PATH_RANKING, "wb");

    if (file) {
        fwrite(&(ranking.numJogs), sizeof(int), 1, file);
        for (i = 0; i < ranking.numJogs; i++) {
            fwrite(&(ranking.jogador[i]), sizeof(JogBasico), 1, file);
        }
        printf("Ranking atualizado\n");
    } else {
        printf("Erro ao salvar ranking\n");
    }
    fclose(file);
}

void loadRanking(Rank *ranking) {
    int i;
    FILE *file;
    file = fopen(FILE_PATH_RANKING, "r");

    if(file) {
        fread(&(ranking->numJogs), sizeof(int), 1, file);
        for (i = 0; i < ranking->numJogs; i++) {
            fread(&(ranking->jogador[i]), sizeof(JogBasico), 1, file);
        }
        printf("RANKING LIDO COM SUCESSO\n");
    } else {
        printf("NÃO FOI POSSÍVEL ABRIR O ARQUIVO \"%s\"\n", FILE_PATH_RANKING);
    }
    fclose(file);
}

void deletaJogo() {
    int n;
    FILE *file;
    file = fopen(FILE_PATH_MAPA, "w");
    if (file) {
        fclose(file);
        n = remove(FILE_PATH_MAPA);
        if (n == 0) {
            printf("Jogo deletado com sucesso\n");
        } else {
            printf("Jogo deletado com fracasso\n");
        }
    } else {
        fclose(file);
    }
}
