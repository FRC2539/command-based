#pragma once

#include "Types/InstantCommand.h"

class MoveToPosition : public InstantCommand {

public:
	MoveToPosition();
	void Initialize() override;
};