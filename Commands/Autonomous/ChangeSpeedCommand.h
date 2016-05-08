#pragma once

#include "../Types/InstantCommand.h"

class ChangeSpeedCommand : public InstantCommand {

public:
	ChangeSpeedCommand(double speed);
	void Initialize();


protected:
	double m_speed;
};