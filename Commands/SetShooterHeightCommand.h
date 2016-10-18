#pragma once

#include "Types/DefaultCommand.h"

class SetShooterHeightCommand : public DefaultCommand {

public:
	SetShooterHeightCommand(double height);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;

protected:
	double m_height;
	int m_speed;
};
