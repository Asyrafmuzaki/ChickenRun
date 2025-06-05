#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include "IScoreObserver.h"
#include "raylib.h"

class ScoreDisplay : public IScoreObserver {
public:
    void OnScoreChanged(int newScore) override;

private:
    int lastScore = 0;
};

#endif
