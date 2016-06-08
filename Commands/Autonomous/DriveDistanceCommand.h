#pragma once

#include "../Types/DefaultCommand.h"

class DriveDistanceCommand : public DefaultCommand {

public:
	// distance should be in inches
	DriveDistanceCommand(
		double distance,
		DriveTrain::SensorMoveDirection direction=DriveTrain::SensorMoveDirection::DriveY
	);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double m_distance;
	unsigned int m_atTargetCount;
	DriveTrain::SensorMoveDirection m_direction;

};

