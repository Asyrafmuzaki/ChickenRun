#include "ObstacleFactory.h"

Obstacle* ObstacleFactory::CreateObstacle(const std::string& type) {
    if (type == "ground") {
        return new Obstacle(800, 300, 20, 40);
    }
    else if (type == "flying") {
        return new Obstacle(800, 250, 20, 20);
    }
    return nullptr;
}
