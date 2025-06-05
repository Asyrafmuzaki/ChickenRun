#ifndef OBSTACLE_H
#define OBSTACLE_H

#pragma once
#include "raylib.h"

class Obstacle {
public:
    Obstacle(); // default constructor
    Obstacle(float x, float y, float width, float height);

    void Update();
    void Draw();
    void Reset();
    Rectangle GetRect() const;

private:
    Rectangle rect;
    bool active;
};

#endif
