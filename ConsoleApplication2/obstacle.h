#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

typedef struct Obstacle {
    Rectangle rect;
    bool active;
} Obstacle;

Obstacle InitObstacle();
void UpdateObstacle(Obstacle* obstacle);
void DrawObstacle(Obstacle obstacle);
bool CheckCollision(Rectangle playerRect, Rectangle obstacleRect);

#endif // OBSTACLE_H
