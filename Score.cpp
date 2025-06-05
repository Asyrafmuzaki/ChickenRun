#include "Score.h"
#include "raylib.h"

Score::Score() : value(0) {}

void Score::Update() {
    frameCounter++;

    if (frameCounter >= 20) {
        value++;
        frameCounter = 0;
        Notify();
    }
}

void Score::Reset() {
    value = 0;
    Notify();
}

int Score::GetValue() const {
    return value;
}

void Score::AddObserver(IScoreObserver* observer) {
    observers.push_back(observer);
}

void Score::RemoveObserver(IScoreObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Score::Notify() {
    for (auto observer : observers) {
        observer->OnScoreChanged(value);
    }
}

void Score::Draw() {
    DrawText(TextFormat("Score: %d", value), 10, 10, 20, BLACK);
}
