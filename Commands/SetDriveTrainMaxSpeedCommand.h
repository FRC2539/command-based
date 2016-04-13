#pragma once

#include "Types/DefaultCommand.h"

class SetDriveTrainMaxSpeedCommand : public DefaultCommand {

public:
	SetDriveTrainMaxSpeedCommand(double Speed);
	void Initialize();


protected:
	double m_Speed;
};