#pragma once

#include "Types/SensorCommand.h"

class AlignmentTurnCommand : public SensorCommand {

public:
	AlignmentTurnCommand(double angle);

protected:
	double ReturnPIDInput() const;
	void UsePIDOutput(double output);
};
