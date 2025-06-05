#ifndef OBSTACLE_H
#define OBSTACLE_H

#pragma once
#include "raylib.h"

class Obstacle {
public:
    Obstacle();
    Obstacle(float x, float y, float width, float height);
    ~Obstacle();
    void Update();
    void Draw();
    void Reset();
    Rectangle GetRect() const;

private:
    Rectangle rect;
    Vector2 position;
    bool active;

    Texture2D texture;
    Rectangle sourceRect;
    float scale;
};

#endif
