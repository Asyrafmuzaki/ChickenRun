#include "score.h"

Score InitScore() {
    Score score = { 0 };
    return score;
}

void UpdateScore(Score* score) {
    score->value++;
}

void DrawScore(Score score) {
    DrawText(TextFormat("Score: %d", score.value), 10, 10, 20, BLACK);
}
