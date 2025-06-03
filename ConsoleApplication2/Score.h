#ifndef SCORE_H
#define SCORE_H

#include "raylib.h"

typedef struct Score {
    int value;
} Score;

Score InitScore();
void UpdateScore(Score* score);
void DrawScore(Score score);

#endif // SCORE_H
