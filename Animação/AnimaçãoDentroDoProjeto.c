#include "raylib.h"

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    Texture2D texture[3];

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - sprite anim");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D scarfy = LoadTexture("Parado.png");
    texture[0] = LoadTexture("Esquerda.png");
    texture[1] = LoadTexture("Direita.png");
    texture[2] = LoadTexture("Parado.png");

    // Capta os frames do png pra usar na animação
    Vector2 position = { 350.0f, 280.0f };
    Rectangle frameRec = { 01.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;      // Velocidade da leitura de frames

    SetTargetFPS(60); // 60 FPS

    while (!WindowShouldClose())
    {
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)scarfy.width/6;
        }

        BeginDrawing(); // Desenhar na tela

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                scarfy = texture[1];
            } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                scarfy = texture[0];
            } else {
                scarfy = texture[2];
            }



            ClearBackground(RAYWHITE);
            DrawTexture(scarfy, 15, 40, WHITE); // Desenha o scarfy
            DrawTextureRec(scarfy, frameRec, position, WHITE);  // Desenha a animação (testa aí trocar WHITE por BLACK)

        EndDrawing();

    }

    UnloadTexture(scarfy);       // Texture unloading

    CloseWindow();

    return 0;
}
