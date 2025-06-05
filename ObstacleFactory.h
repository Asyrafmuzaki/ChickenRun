#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

#include "Obstacle.h"
#include <string>

class ObstacleFactory {
public:
    static Obstacle* CreateObstacle(const std::string& type);
};

#endif
