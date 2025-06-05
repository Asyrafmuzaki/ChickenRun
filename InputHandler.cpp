#include "InputHandler.h"

void InputHandler::BindKey(int key, ICommand* command) {
    commands[key] = command;
}

void InputHandler::HandleInput() {
    for (auto& pair : commands) {
        if (IsKeyPressed(pair.first)) {
            pair.second->Execute();
        }
    }
}
