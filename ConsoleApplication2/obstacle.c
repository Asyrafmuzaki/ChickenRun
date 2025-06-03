#include "obstacle.h"

Obstacle InitObstacle() {
    Obstacle obstacle = { 0 };
    obstacle.rect = (Rectangle){ 800, 300, 20, 40 };
    obstacle.active = true;
    return obstacle;
}

void UpdateObstacle(Obstacle* obstacle) {
    if (obstacle->active) {
        obstacle->rect.x -= 5; // Move left
        if (obstacle->rect.x < -obstacle->rect.width) {
            obstacle->active = false; // Deactivate if off screen
        }
    }
    else {
        obstacle->rect.x = 800; // Reset position
        obstacle->active = true; // Reactivate
    }
}

void DrawObstacle(Obstacle obstacle) {
    if (obstacle.active) {
        DrawRectangleRec(obstacle.rect, GREEN);
    }
}

bool CheckCollision(Rectangle playerRect, Rectangle obstacleRect) {
    return CheckCollisionRecs(playerRect, obstacleRect);
}
