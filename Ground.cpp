#include "Ground.h"

Ground::Ground() {
    bgTexture = LoadTexture("Assets/background.png");
    groundTexture = LoadTexture("Assets/tanah.png");
}

void Ground::Draw() const {
    DrawTextureEx(bgTexture, { 0, -100 }, 0.0f, 1.0f, WHITE);
    DrawTextureEx(groundTexture, {0, -120}, 0.0f, 1.0f, WHITE);
}
