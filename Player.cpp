#include "Player.h"

Player::Player(){
    velocityY = 0;
    position = { 100, 250 };
    isJumping = false;
    jumpHeight = 14.0f;
    texture = LoadTexture("Assets/Spritepitikjalan.png");
    frameWidth = texture.width / 3;
    frameHeight = texture.height;
    currentFrame = 0;
    frameCounter = 0;
    frameSpeed = 8;
}

void Player::Update() {
    if (!isJumping) {
        frameCounter++;
        if (frameCounter >= (60 / frameSpeed)) {
            frameCounter = 0;
            currentFrame++;
            if (currentFrame > 2) currentFrame = 0;
        }
    }

    if (isJumping) {
        velocityY += 0.40f; // gravity
        position.y += velocityY;
        if (position.y >= 250) {
            position.y = 250;
            isJumping = false;
            velocityY = 0;
        }
    }
}

void Player::Draw() {
    Rectangle source = { static_cast<float>(currentFrame * frameWidth), 0, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
    Rectangle dest = { position.x, position.y, static_cast<float>(frameWidth), static_cast<float>(frameHeight) };
    DrawTextureRec(texture, source, position, WHITE);
    //DrawRectangleLinesEx(GetRect(), 2, RED);
}


void Player::Reset() {
    position.y = 250;
    velocityY = 0;
    isJumping = false;
    currentFrame = 0;
    frameCounter = 0;
}

Rectangle Player::GetRect() const {
    float paddingX = 30.0f; 
    float paddingY = 38.0f;  

    return {
        position.x + paddingX,
        position.y + paddingY,
        static_cast<float>(frameWidth) - 2 * paddingX,
        static_cast<float>(frameHeight) - 2 * paddingY
    };
}


bool Player::IsJumping() const {
    return isJumping;
}

void Player::StartJump() {
    if (!isJumping) {
        velocityY = -jumpHeight;
        isJumping = true;
    }
}
