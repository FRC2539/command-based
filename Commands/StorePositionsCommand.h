#pragma once

#include "Types/InstantCommand.h"

class StorePositionsCommand : public InstantCommand {

public:
	StorePositionsCommand();
	void Initialize();
};
