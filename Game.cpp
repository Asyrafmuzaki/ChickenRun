#include "Game.h"
#include "GameManager.h"
#include <cstdlib>

Game& Game::GetInstance() {
    static Game instance;
    return instance;
}

void Game::Init() {
    player = Player();
    ground = Ground();
    score = Score();
    score.AddObserver(&scoreDisplay);
    obstacles.clear();
    obstacles.push_back(std::unique_ptr<Obstacle>(ObstacleFactory::CreateObstacle("ground")));
    jumpCommand = std::make_unique<JumpCommand>(&player);
    inputHandler.BindKey(KEY_SPACE, jumpCommand.get());
    pauseCommand = std::make_unique<PauseCommand>();
    inputHandler.BindKey(KEY_P, pauseCommand.get());
}

void Game::Update() {
    inputHandler.HandleInput();
    player.Update();
    player.Update();
    score.Update();

    for (auto& obs : obstacles) {
        obs->Update();
        if (CheckCollisionRecs(player.GetRect(), obs->GetRect())) {
            GameManager::GetInstance().SetState(GameState::GAME_OVER);
        }
    }

    if (obstacles.back()->GetRect().x < 400) {
        obstacles.push_back(std::unique_ptr<Obstacle>(ObstacleFactory::CreateObstacle("ground")));
    }
}

void Game::Draw() {
    ground.Draw();
    player.Draw();
    score.Draw();

    for (auto& obs : obstacles) {
        obs->Draw();
    }
}

void Game::Reset() {
    player.Reset();
    score.Reset();
    for (auto& obs : obstacles) {
        obs->Reset();
    }

}