#pragma once
#include "GameState.h"

class GameManager {
public:
    static GameManager& GetInstance();
    void SetState(GameState state);
    GameState GetState() const;
    void Run();

private:
    GameManager() = default;
    GameState currentState = GameState::START;
};
