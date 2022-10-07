#include <stdbool.h>

#ifndef COORDENADAS_H
#define COORDENADAS_H

typedef struct {
    int linha, coluna;
} Localizacao;

Localizacao criaLocal(int linha, int coluna);
bool comparaLocal(Localizacao localI, Localizacao localII);

#endif // COORDENADAS_H
