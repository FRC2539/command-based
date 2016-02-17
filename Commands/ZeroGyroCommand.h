#pragma once

#include "Types/InstantCommand.h"

class ZeroGyroCommand : public InstantCommand {

public:
	ZeroGyroCommand();
	void Initialize() override;
};
