#pragma once

#include "Types/InstantCommand.h"

class ResetShooterPosistionCommand : public InstantCommand {

public:
	ResetShooterPosistionCommand();
	void Initialize();
};
