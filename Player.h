#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
private:
    Rectangle rect;
    Vector2 velocity;
    bool isJumping;
    float jumpHeight;

public:
    Player();

    void Update();
    void Draw();
    void Reset();

    Rectangle GetRect() const;

    bool IsJumping() const;
    void StartJump();
};

#endif
