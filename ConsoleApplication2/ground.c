#include "ground.h"

Ground InitGround() {
    Ground ground = { 0 };
    ground.rect = (Rectangle){ 0, 340, 800, 110 };
    return ground;
}

void DrawGround(Ground ground) {
    DrawRectangleRec(ground.rect, DARKGRAY);
}
