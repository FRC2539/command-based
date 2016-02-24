#pragma once

#include "Types/SensorCommand.h"

class CrossDefenseCommand : public SensorCommand {

public:
	CrossDefenseCommand();
	void Initialize() override;
	bool IsFinished() override;
	void Interrupted() override;

protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);
	bool crossedDefense;
	int counter;
};
