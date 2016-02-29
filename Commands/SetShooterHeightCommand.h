#pragma once

#include "Types/InstantCommand.h"

class SetShooterHeightCommand : public InstantCommand {

public:
	SetShooterHeightCommand(int height);
	void Initialize() override;

protected:
	int m_height;
};