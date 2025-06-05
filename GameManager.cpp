#include "GameManager.h"
#include "Game.h"
#include "raylib.h"

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::SetState(GameState state) {
    currentState = state;
}

GameState GameManager::GetState() const {
    return currentState;
}

void GameManager::Run() {
    InitWindow(800, 450, "Dino Runner");
    SetTargetFPS(60);

    Game& game = Game::GetInstance();
    game.Init();

    while (!WindowShouldClose()) {
        switch (currentState) {
        case GameState::START:
            if (IsKeyPressed(KEY_ENTER)) {
                SetState(GameState::PLAYING);
            }
            break;
        case GameState::PLAYING:
            game.Update();
            break;
        case GameState::PAUSED:
            if (IsKeyPressed(KEY_P)) {
                SetState(GameState::PLAYING);
            }
            break;
        case GameState::GAME_OVER:
            if (IsKeyPressed(KEY_R)) {
                game.Reset();
                SetState(GameState::PLAYING);
            }
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentState == GameState::START) {
            DrawText("Press ENTER to Start", 250, 200, 20, DARKGRAY);
        }
        else if (currentState == GameState::PAUSED) {
            DrawText("PAUSED - Press P to Resume", 200, 200, 20, DARKGRAY);
        }
        else {
            game.Draw();
            if (currentState == GameState::GAME_OVER) {
                DrawText("GAME OVER - Press R to Restart", 200, 150, 20, RED);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
