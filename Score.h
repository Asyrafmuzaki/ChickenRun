#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include "IScoreObserver.h"

class Score {
private:
    int value;
    int frameCounter;
    std::vector<IScoreObserver*> observers;

    void Notify();

public:
    Score();
    void Update();
    void Reset();
    int GetValue() const;

    void AddObserver(IScoreObserver* observer);
    void RemoveObserver(IScoreObserver* observer);

    void Draw();
};

#endif
