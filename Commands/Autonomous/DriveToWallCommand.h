#pragma once

#include "../Types/SensorCommand.h"

class DriveToWallCommand : public SensorCommand {

public:
	DriveToWallCommand(bool forward=true);
	void Initialize() override;
	bool IsFinished() override;

protected:
	double ReturnPIDInput() const override;
	void UsePIDOutput(double output);

	bool m_driveForward;
};
