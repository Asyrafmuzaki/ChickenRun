#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "ICommand.h"
#include <unordered_map>
#include "raylib.h"

class InputHandler {
private:
    std::unordered_map<int, ICommand*> commands; // key -> command

public:
    void BindKey(int key, ICommand* command);
    void HandleInput();
};

#endif
