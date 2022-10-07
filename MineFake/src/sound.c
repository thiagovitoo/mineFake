#include "../headers/sound.h"

void loadSounds(Sound som[NUM_SONS]) {
    som[0] = LoadSound("assets/sounds/openChest.ogg");
    som[1] = LoadSound("assets/sounds/win.ogg");
    som[2] = LoadSound("assets/sounds/getPoints.ogg");
    som[3] = LoadSound("assets/sounds/levelUP.ogg");
    som[4] = LoadSound("assets/sounds/selecaoMenu.ogg");
    som[5] = LoadSound("assets/sounds/tzzzzz.ogg");
    som[6] = LoadSound("assets/sounds/queda.ogg");
    som[7] = LoadSound("assets/sounds/dano.ogg");
    som[8] = LoadSound("assets/sounds/eat.ogg");
    som[9] = LoadSound("assets/sounds/drink.ogg");
    som[10] = LoadSound("assets/sounds/lose.mp3");
    som[11] = LoadSound("assets/sounds/explosion.ogg");
}
