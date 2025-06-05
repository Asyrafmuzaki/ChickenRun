#include "Ground.h"

Ground::Ground() {
    rect = { 0, 340, 800, 110 };
}

void Ground::Draw() const {
    DrawRectangleRec(rect, DARKGRAY);
}
