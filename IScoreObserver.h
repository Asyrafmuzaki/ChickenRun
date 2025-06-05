#ifndef ISCOREOBSERVER_H
#define ISCOREOBSERVER_H

class IScoreObserver {
public:
    virtual void OnScoreChanged(int newScore) = 0;
    virtual ~IScoreObserver() = default;
};

#endif
