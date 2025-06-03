#ifndef GROUND_H
#define GROUND_H

#include "raylib.h"

typedef struct Ground {
    Rectangle rect;
} Ground;

Ground InitGround();
void DrawGround(Ground ground);

#endif // GROUND_H
#pragma once
