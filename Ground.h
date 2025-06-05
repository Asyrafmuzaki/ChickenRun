#pragma once
#include "raylib.h"

class Ground {
public:
    Ground();
    void Draw() const;
private:
    Rectangle rect;
};