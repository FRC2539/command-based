#pragma once

#include "Types/DefaultCommand.h"

class ManualShooterCommand : public DefaultCommand {

public:
	ManualShooterCommand(double power);
	void Initialize();
	void End();

protected:
	double m_power;
};