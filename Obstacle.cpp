#include "Obstacle.h"

Obstacle::Obstacle() : rect{ 800, 172 }, active(true) {
    texture = LoadTexture("Assets/obstacle.png");
    sourceRect = { 0, 0, 128, 128 };
    rect.width = 60;
    rect.height = 90;
    rect.x = position.x + 34;
    rect.y = position.y;
    scale = .6f;
}

Obstacle::Obstacle(float x, float y, float width, float height)
    : position{ x, y - (128 - height) }, active(true) {
    texture = LoadTexture("Assets/Obstacle.png");
    sourceRect = { 0, 0, 128, 128 };
    rect.width = 60;
    rect.height = 90;
    rect.x = position.x + 34;
    rect.y = position.y;
    scale = .6f;
}

void Obstacle::Update() {
    if (active) {
        position.x -= 5;
        rect.x -= 5;
        if (position.x < -sourceRect.width) {
            active = false;
        }
    }
    else {
        position.x = 800;
        rect.x = position.x + 34;
        active = true;
    }
}

void Obstacle::Draw() {
    if (active) {
        Rectangle destRect = {
            position.x,
            position.y,
            sourceRect.width * scale,
            sourceRect.height * scale
        };
        Vector2 origin = { 0, 0 };

        DrawTexturePro(texture, sourceRect, destRect, origin, 0.0f, WHITE);
        //DrawRectangleLinesEx(GetRect(), 2, RED);
    }
}


void Obstacle::Reset() {
    position.x = 800;
    rect.x = position.x + 34;
    active = true;
}

Rectangle Obstacle::GetRect() const {
    float offsetX = 33.0f;
    float offsetY = 16.0f;
    float width = 40.0f;
    float height = 70.0f;

    return {
        position.x + offsetX,
        position.y + offsetY,
        width,
        height
    };
}



Obstacle::~Obstacle() {
    UnloadTexture(texture);
}
