#pragma once

#include "Types/DefaultCommand.h"

class SetShooterHeightCommand : public DefaultCommand {

public:
	SetShooterHeightCommand(int i);
	void Initialize() override;

protected:
	int m_height;
};