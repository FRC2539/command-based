#pragma once

#include "Types/InstantCommand.h"

class StopPickupCommand : public InstantCommand {

public:
	StopPickupCommand();
	void Initialize();
};
