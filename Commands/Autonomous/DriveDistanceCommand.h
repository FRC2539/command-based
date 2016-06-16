#pragma once

#include "../Types/DefaultCommand.h"

class DriveDistanceCommand : public DefaultCommand {

public:
	// distance should be in inches
	DriveDistanceCommand(
		double distance,
		float error = 30,
		DriveTrain::SensorMoveDirection direction=DriveTrain::SensorMoveDirection::DriveY
	);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double m_distance;
	unsigned int m_atTargetCount;
	float m_error;
	DriveTrain::SensorMoveDirection m_direction;

};

