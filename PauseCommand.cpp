// PauseCommand.cpp
#include "PauseCommand.h"

void PauseCommand::Execute() {
    GameManager& gm = GameManager::GetInstance();
    if (gm.GetState() == GameState::PLAYING) {
        gm.SetState(GameState::PAUSED);
    }
    else if (gm.GetState() == GameState::PAUSED) {
        gm.SetState(GameState::PLAYING);
    }
}
