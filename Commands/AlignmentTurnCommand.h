#pragma once

#include "Types/SensorCommand.h"

class AlignmentTurnCommand : public SensorCommand {

public:
	AlignmentTurnCommand(double angle);
	void Initialize() override;
	void End() override;

protected:
	double ReturnPIDInput() const;
	void UsePIDOutput(double output);
};
