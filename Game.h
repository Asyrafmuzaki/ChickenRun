#pragma once
#include "Player.h"
#include "Ground.h"
#include "Score.h"
#include "Obstacle.h"
#include "ScoreDisplay.h"
#include <vector>
#include <memory>
#include "ObstacleFactory.h"
#include "InputHandler.h"
#include "JumpCommand.h"
#include "PauseCommand.h"

using namespace std;

class Game {
public:
    static Game& GetInstance();
    void Init();
    void Update();
    void Draw();
    void Reset();

private:
    Game() = default;
    Player player;
    Ground ground;
    Score score;
    Obstacle obstacle;
    ScoreDisplay scoreDisplay;
    vector<std::unique_ptr<Obstacle>> obstacles;
    InputHandler inputHandler;
    unique_ptr<ICommand> jumpCommand;
    unique_ptr<ICommand> pauseCommand;
};
