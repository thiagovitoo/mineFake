#include "../headers/coordenada.h"

Localizacao criaLocal(int linha, int coluna) {
    Localizacao local;
    local.linha = linha;
    local.coluna = coluna;
    return local;
}

bool comparaLocal(Localizacao localI, Localizacao localII) {
    if (localI.coluna == localII.coluna && localI.linha == localII.linha) {
        return true;
    } else {
        return false;
    }
}
