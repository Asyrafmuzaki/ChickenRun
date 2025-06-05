#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
    private:
        Vector2 position;
        float velocityY;
        bool isJumping;
        float jumpHeight;

        //Animation
        Texture2D texture;
        int frameWidth;
        int frameHeight;
        int currentFrame;
        int frameCounter;
        int frameSpeed;
    public:
        Player();
        void Update();
        void Draw();
        void Reset();
        Rectangle GetRect() const;

        bool IsJumping() const;
        void StartJump();
};

#endif
