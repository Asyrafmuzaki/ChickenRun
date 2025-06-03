#include "raylib.h"
#include "player.h"
#include "obstacle.h"
#include "ground.h"
#include "score.h"
#include "gamestate.h"

int main(void) {
    // Inisialisasi Raylib
    InitWindow(800, 450, "Dino Runner");
    SetTargetFPS(60);

    GameState gameState = { 0 };
    Player player = InitPlayer();
    Ground ground = InitGround();
    Score score = InitScore();
    Obstacle obstacle = InitObstacle();

    while (!WindowShouldClose()) {
        UpdateGame(&gameState, &player, &ground, &obstacle, &score);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame(&gameState, &player, &ground, &obstacle, &score);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
