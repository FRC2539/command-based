#pragma once

#include "Types/SensorCommand.h"

class DriveToFloor : public SensorCommand {

public:
	explicit DriveToFloor();
	void Initialize() override;
	bool IsFinished() override;
	

protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);
	bool crossedDefense;
};
