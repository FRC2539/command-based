#pragma once

#include "../Types/SensorCommand.h"

class DriveToFloorCommand : public SensorCommand {

public:
	DriveToFloorCommand(int directive);
	void Initialize() override;
	bool IsFinished() override;
	
protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);
	bool crossedDefense;
	int counter;
	int m_directive;
	int direction;
};
