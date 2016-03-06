#pragma once

#include "../Types/SensorCommand.h"

class DriveToDefenseCommand : public SensorCommand {

public:
	DriveToDefenseCommand();
	void Initialize() override;
	bool IsFinished() override;

protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);
};
