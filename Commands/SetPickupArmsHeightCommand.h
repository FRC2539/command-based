#pragma once

#include "Types/DefaultCommand.h"

class SetPickupArmsHeightCommand : public DefaultCommand {

public:
	SetPickupArmsHeightCommand(int height);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;

protected:
	int m_height;
};