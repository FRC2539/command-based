#pragma once

#include "Types/InstantCommand.h"

class SetDriveTrainMaxSpeedCommand : public InstantCommand {

public:
	SetDriveTrainMaxSpeedCommand(double Speed);
	void Initialize();


protected:
	double m_Speed;
};