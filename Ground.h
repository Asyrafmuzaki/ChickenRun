#pragma once
#include "raylib.h"

class Ground {
public:
    Ground();
    void Draw() const;
private:
    Texture2D bgTexture;
    Texture2D groundTexture;
};