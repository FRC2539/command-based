#pragma once

#include "Types/InstantCommand.h"

class ReloadPickupPositionCommand : public InstantCommand {

public:
	ReloadPickupPositionCommand();
	void Initialize() override;
};
