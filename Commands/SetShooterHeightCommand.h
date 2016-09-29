#pragma once

#include "Types/DefaultCommand.h"

class SetShooterHeightCommand : public DefaultCommand {

public:
	SetShooterHeightCommand(int height);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;

protected:
	int m_height;
	int m_speed;
};
