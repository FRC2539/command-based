#pragma once

#include "Types/DefaultCommand.h"

class SpinShooterCommand : public DefaultCommand {

public:
	explicit SpinShooterCommand(double speed);
	void Initialize() override;
	bool IsFinished() override;

protected:
	double m_speed;
};
