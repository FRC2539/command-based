#pragma once

#include "Types/InstantCommand.h"

class ReloadShooterPositionCommand : public InstantCommand {

public:
	ReloadShooterPositionCommand();
	void Initialize() override;
};
