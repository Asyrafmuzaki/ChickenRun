#include "Player.h"

Player::Player()
    : rect{ 50, 300, 40, 40 }, velocity{ 0, 0 }, isJumping(false), jumpHeight(9.0f) {
}

void Player::Update() {
    if (isJumping) {
        velocity.y += 0.3f; // gravity
        rect.y += velocity.y;
        if (rect.y >= 300) {
            rect.y = 300;
            isJumping = false;
            velocity.y = 0;
        }
    }
}

void Player::Draw() {
    DrawRectangleRec(rect, BLACK);
}

void Player::Reset() {
    rect.y = 300;
    velocity = { 0, 0 };
    isJumping = false;
}

Rectangle Player::GetRect() const {
    return rect;
}

bool Player::IsJumping() const {
    return isJumping;
}

void Player::StartJump() {
    if (!isJumping) {
        velocity.y = -jumpHeight;
        isJumping = true;
    }
}
