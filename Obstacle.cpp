// Obstacle.cpp
#include "Obstacle.h"

Obstacle::Obstacle() : rect{ 800, 300, 20, 40 }, active(true) {}

Obstacle::Obstacle(float x, float y, float width, float height)
    : rect{ x, y, width, height }, active(true) {
}

void Obstacle::Update() {
    if (active) {
        rect.x -= 5;
        if (rect.x < -rect.width) {
            active = false;
        }
    }
    else {
        rect.x = 800;
        active = true;
    }
}

void Obstacle::Draw() {
    if (active) {
        DrawRectangleRec(rect, GREEN);
    }
}

void Obstacle::Reset() {
    rect.x = 800;
    active = true;
}

Rectangle Obstacle::GetRect() const {
    return rect;
}
