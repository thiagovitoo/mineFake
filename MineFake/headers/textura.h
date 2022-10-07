#include <raylib.h>

#define NUM_BLOCOS 8
#define TAMANHO_BLOCOS 64
#define SKINS 2
#define NUM_TEXTURAS_SKIN 9
#define NUM_TEXTURAS_GERAL 15


#ifndef TEXTURA_H
#define TEXTURA_H

typedef struct {
    Texture2D blocos[NUM_BLOCOS];
    Texture2D player[SKINS][NUM_TEXTURAS_SKIN];
    Texture2D background;
    Texture2D interface[NUM_TEXTURAS_GERAL];
} Texturas;

void loadTextures(Texturas *textura);
void desenhaBloco(Texture2D textura, int l, int c);

#endif // TEXTURA_H
