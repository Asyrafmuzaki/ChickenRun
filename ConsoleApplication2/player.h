#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Rectangle rect;
    Vector2 velocity;
    bool isJumping;
    float jumpHeight;
} Player;

Player InitPlayer();
void UpdatePlayer(Player* player);
void DrawPlayer(Player player);

#endif // PLAYER_H
