// ScoreDisplay.cpp
#include "ScoreDisplay.h"
#include <cstdio>

void ScoreDisplay::OnScoreChanged(int newScore) {
    lastScore = newScore;

    // Contoh efek tambahan: Cetak log / bisa diganti SFX atau animasi UI
    TraceLog(LOG_INFO, "Score Updated: %d", newScore);
}
