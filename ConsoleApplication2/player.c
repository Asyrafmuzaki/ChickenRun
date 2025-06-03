#include "player.h"

Player InitPlayer() {
    Player player = { 0 };
    player.rect = (Rectangle){ 50, 300, 40, 40 };
    player.velocity = (Vector2){ 0, 0 };
    player.isJumping = false;
    player.jumpHeight = 9.0f;
    return player;
}

void UpdatePlayer(Player* player) {
    if (IsKeyPressed(KEY_SPACE) && !player->isJumping) {
        player->velocity.y = -player->jumpHeight;
        player->isJumping = true;
    }

    player->velocity.y += 0.5f; // Gravity
    player->rect.y += player->velocity.y;

    if (player->rect.y >= 300) {
        player->rect.y = 300;
        player->isJumping = false;
        player->velocity.y = 0;
    }
}

void DrawPlayer(Player player) {
    DrawRectangleRec(player.rect, BLACK);
}
