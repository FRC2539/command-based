#pragma once

#include "Types/InstantCommand.h"

class SetPickupArmsHeightCommand : public InstantCommand {

public:
	SetPickupArmsHeightCommand(int height);
	void Initialize() override;

protected:
	int m_height;
};