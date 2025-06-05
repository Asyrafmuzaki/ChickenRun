#include "JumpCommand.h"

void JumpCommand::Execute() {
    if (!player->IsJumping()) {
        player->StartJump();
    }
}
