#ifndef PAUSECOMMAND_H
#define PAUSECOMMAND_H

#include "ICommand.h"
#include "GameManager.h"

class PauseCommand : public ICommand {
public:
    void Execute() override;
};

#endif
