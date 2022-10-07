#include "../headers/textura.h"

void loadTextures(Texturas *textura) {
    textura->background = LoadTexture("assets/backgrounds/fundoMoldura.png");

    textura->blocos[0] = LoadTexture("assets/blocks/blocoMoldura.png");
    textura->blocos[1] = LoadTexture("assets/blocks/minecraftNetherPortal.png");
    textura->blocos[2] = LoadTexture("assets/blocks/minecraftChest.png");
    textura->blocos[3] = LoadTexture("assets/blocks/minecraftAetherPortal.png");
    textura->blocos[4] = LoadTexture("assets/blocks/minecraftLadder.png");
    textura->blocos[5] = LoadTexture("assets/blocks/minecraftGrass.png");
    textura->blocos[6] = LoadTexture("assets/blocks/minecraftBricks.png");
    textura->blocos[7] = LoadTexture("assets/blocks/minecraftDirt.png");

    textura->player[0][0] = LoadTexture("assets/player/steve/steveLeft.png");
    textura->player[0][1] = LoadTexture("assets/player/steve/steveRunLeftI.png");
    textura->player[0][2] = LoadTexture("assets/player/steve/steveLeft.png");
    textura->player[0][3] = LoadTexture("assets/player/steve/steveRunLeftII.png");
    textura->player[0][4] = LoadTexture("assets/player/steve/steveRight.png");
    textura->player[0][5] = LoadTexture("assets/player/steve/steveRunRightI.png");
    textura->player[0][6] = LoadTexture("assets/player/steve/steveRight.png");
    textura->player[0][7] = LoadTexture("assets/player/steve/steveRunRightII.png");
    textura->player[0][8] = LoadTexture("assets/player/steve/steveBig.png");

    textura->player[1][0] = LoadTexture("assets/player/alex/alexLeft.png");
    textura->player[1][1] = LoadTexture("assets/player/alex/alexRunLeftI.png");
    textura->player[1][2] = LoadTexture("assets/player/alex/alexLeft.png");
    textura->player[1][3] = LoadTexture("assets/player/alex/alexRunLeftII.png");
    textura->player[1][4] = LoadTexture("assets/player/alex/alexRight.png");
    textura->player[1][5] = LoadTexture("assets/player/alex/alexRunRightI.png");
    textura->player[1][6] = LoadTexture("assets/player/alex/alexRight.png");
    textura->player[1][7] = LoadTexture("assets/player/alex/alexRunRightII.png");
    textura->player[1][8] = LoadTexture("assets/player/alex/alexBig.png");

    textura->interface[0] = LoadTexture("assets/interface/diamondChestplate.png");
    textura->interface[1] = LoadTexture("assets/interface/peitoralVazio.png");
    textura->interface[2] = LoadTexture("assets/interface/inventario.png");
    textura->interface[3] = LoadTexture("assets/interface/select.png");
    textura->interface[4] = LoadTexture("assets/interface/copper.png");
    textura->interface[5] = LoadTexture("assets/interface/iron.png");
    textura->interface[6] = LoadTexture("assets/interface/gold.png");
    textura->interface[7] = LoadTexture("assets/interface/diamond.png");
    textura->interface[8] = LoadTexture("assets/interface/emerald.png");
    textura->interface[9] = LoadTexture("assets/interface/tnt.png");
    textura->interface[10] = LoadTexture("assets/interface/diamondSword.png");
    textura->interface[11] = LoadTexture("assets/interface/minecraftHeart.png");
    textura->interface[12] = LoadTexture("assets/interface/waterBucket.png");
    textura->interface[13] = LoadTexture("assets/interface/enchantedGoldenApple.png");
    textura->interface[14] = LoadTexture("assets/interface/healthPotion.png");

}

void desenhaBloco(Texture2D textura, int l, int c) {
    DrawTexture(textura, c * TAMANHO_BLOCOS + (TAMANHO_BLOCOS - textura.width)/2, l * TAMANHO_BLOCOS, WHITE);
}
