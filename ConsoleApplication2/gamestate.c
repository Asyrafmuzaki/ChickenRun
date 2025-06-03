#include "gamestate.h"
#include "raylib.h"
#include "player.h"
#include "obstacle.h"
#include "Score.h"
#include "ground.h"

void UpdateGame(GameState* gameState, Player* player, Ground* ground, Obstacle* obstacle, Score* score) {
    switch (*gameState) {
    case START:
        if (IsKeyPressed(KEY_ENTER)) {
            *gameState = PLAYING;
        }
        break;
    case PLAYING:
        UpdatePlayer(player);
        UpdateObstacle(obstacle);
        UpdateScore(score);
        if (CheckCollision(player->rect, obstacle->rect)) {
            *gameState = GAME_OVER;
        }
        break;
    case GAME_OVER:
        if (IsKeyPressed(KEY_R)) {
            *gameState = START;
            score->value = 0; // Reset score
        }
        break;
    }
}

void DrawGame(GameState* gameState, Player* player, Ground* ground, Obstacle* obstacle, Score* score) {
    switch (*gameState) {
    case START:
        DrawText("Press ENTER to Start", 250, 200, 20, BLACK);
        break;
    case PLAYING:
        DrawGround(*ground);
        DrawPlayer(*player);
        DrawObstacle(*obstacle);
        DrawScore(*score);
        break;
    case GAME_OVER:
        DrawText("Game Over! Press R to Restart", 200, 200, 20, BLACK);
        break;
    }
}
