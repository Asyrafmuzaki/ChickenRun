#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

#include "ICommand.h"
#include "Player.h"

class JumpCommand : public ICommand {
private:
    Player* player;
public:
    JumpCommand(Player* p) : player(p) {}
    void Execute() override;
};

#endif
