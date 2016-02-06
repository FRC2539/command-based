#pragma once

#include "Types/SensorCommand.h"

class FixedHeadingCommand : public SensorCommand {

public:
	explicit FixedHeadingCommand();
	void Initialize() override;
	bool IsFinished() override;

protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);
};
